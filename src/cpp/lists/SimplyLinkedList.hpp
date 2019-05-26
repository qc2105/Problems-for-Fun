#ifndef SIMPLY_LINKED_LIST_HPP
#define SIMPLY_LINKED_LIST_HPP

typedef const int Error_code;
Error_code success = 0;
Error_code overflow = -1;
Error_code range_error = -2;
Error_code out_of_bound = -3;
Error_code not_enough_memory = -4;

template <class Node_entry>
class Node
{
public:
    Node();
    Node(Node_entry _entry, Node<Node_entry> *_next = NULL);

    Node_entry entry;
    Node<Node_entry> *next;
};

template <class Node_entry>
Node<Node_entry>::Node()
{
    entry = 0;
    next = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry _entry, Node<Node_entry> *_next)
{
    entry = _entry;
    next = _next;
}

template <class List_entry>
class SimplyLinkedList
{
public:
    SimplyLinkedList();
    SimplyLinkedList(const SimplyLinkedList<List_entry> &);
    ~SimplyLinkedList();

    SimplyLinkedList<List_entry> &operator=(const SimplyLinkedList<List_entry>);

    bool empty() const;
    void clear();
    int size() const;

    void reverse();

    void traverse(void (*visit)(List_entry &));

    bool is_out_of_bound(int position) const
    {
        if (0 <= position && position < count)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    Error_code insert(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
    Error_code retrieve(int position, List_entry &x) const;
    Error_code replace(int position, const List_entry &x);

protected:
    int count = 0;
    mutable int current_position = 0;
    Node<List_entry> *head = NULL;
    mutable Node<List_entry> *current = NULL;

    void set_position(int position) const;
};

template <class List_entry>
SimplyLinkedList<List_entry>::SimplyLinkedList()
{
    count = 0;
    head = NULL;
    set_position(0);
}

template <class List_entry>
SimplyLinkedList<List_entry>::SimplyLinkedList(const SimplyLinkedList &src_list)
{
    if (this != &src_list)
    {
        clear();
        List_entry value;

        for (int i = 0; i < src_list.size(); i++)
        {
            src_list.retrieve(i, value);
            insert(i, value);
        }
    }
}

template <class List_entry>
SimplyLinkedList<List_entry>::~SimplyLinkedList()
{
    Node<List_entry> *it_pointer;
    Node<List_entry> *temp;

    for (it_pointer = head; it_pointer != NULL;)
    {
        temp = it_pointer;
        it_pointer = it_pointer->next;
        delete temp;
        count--;
    }
    head = NULL;
    set_position(0);
}

template <class List_entry>
SimplyLinkedList<List_entry> &SimplyLinkedList<List_entry>::operator=(const SimplyLinkedList<List_entry> other)
{
    if (this != &other)
    {
        this->clear();
        List_entry value;

        for (int i = 0; i < other.size(); i++)
        {
            other.retrieve(i, value);
            this->insert(i, value);
        }
    }

    return *this;
}

template <class List_entry>
bool SimplyLinkedList<List_entry>::empty() const
{
    return count == 0;
}

template <class List_entry>
void SimplyLinkedList<List_entry>::clear()
{
    Node<List_entry> *it_pointer = head;
    Node<List_entry> *temp;

    while (it_pointer != NULL)
    {
        temp = it_pointer;
        it_pointer = it_pointer->next;
        delete temp;
        count--;
    }

    head = NULL;
    set_position(0);
}

template <class List_entry>
int SimplyLinkedList<List_entry>::size() const
{
    return count;
}

template <class List_entry>
void SimplyLinkedList<List_entry>::reverse()
{
    Node<List_entry> *curr = head;
    Node<List_entry> *next = NULL;
    Node<List_entry> *pre = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }

    head = pre;
}

template <class List_entry>
void SimplyLinkedList<List_entry>::traverse(void (*visit)(List_entry &))
{
    Node<List_entry> *iterator = head;
    while (iterator != NULL)
    {
        (*visit)(iterator->entry);
        iterator = iterator->next;
    }
}

template <class List_entry>
Error_code SimplyLinkedList<List_entry>::insert(int position, const List_entry &x)
{
    if (position < 0 || position > count)
    {
        return out_of_bound;
    }

    Node<List_entry> *newNode, *pre, *next;

    if (0 == position)
    {
        next = head;
    }
    else
    {
        set_position(position - 1);
        pre = current;
        if (current != NULL)
        {
            next = current->next;
        }
        else
        {
            next = NULL;
        }
    }

    newNode = new Node<List_entry>(x, next);
    if (NULL == newNode)
    {
        return not_enough_memory;
    }

    if (0 == position)
    {
        head = newNode;
    }
    else
    {
        pre->next = newNode;
    }

    count++;

    return success;
}

template <class List_entry>
Error_code SimplyLinkedList<List_entry>::remove(int position, List_entry &x)
{
    if (is_out_of_bound(position))
    {
        return out_of_bound;
    }

    Node<List_entry> *pre, *next, *to_be_removed;

    if (0 == position)
    {
        pre = NULL;
        set_position(position);
        head = current->next;

        x = current->entry;
        delete current;
    }
    else
    {
        set_position(position - 1);
        pre = current;
        to_be_removed = pre->next;
        x = to_be_removed->entry;
        next = to_be_removed->next;
        pre->next = next;

        delete to_be_removed;
    }

    count--;

    return success;
}

template <class List_entry>
Error_code SimplyLinkedList<List_entry>::retrieve(int position, List_entry &x) const
{
    if (is_out_of_bound(position))
    {
        return out_of_bound;
    }

    set_position(position);

    x = current->entry;

    return success;
}

template <class List_entry>
Error_code SimplyLinkedList<List_entry>::replace(int position, const List_entry &x)
{
    if (is_out_of_bound(position))
    {
        return out_of_bound;
    }

    set_position(position);
    current->entry = x;

    return success;
}

template <class List_entry>
void SimplyLinkedList<List_entry>::set_position(int position) const
{
    if (position <= current_position)
    {
        current_position = 0;
        current = head;
    }
    for (; current_position != position; current_position++)
    {
        current = current->next;
    }
}

template <class _List_entry>
void reverse_traverse_list(SimplyLinkedList<_List_entry> &a_list, void (*visit)(_List_entry &));

template <class _List_entry>
void reverse_traverse_list(SimplyLinkedList<_List_entry> &a_list, void (*visit)(_List_entry &))
{
    a_list.reverse();
    a_list.traverse(visit);
    a_list.reverse();
}

#endif