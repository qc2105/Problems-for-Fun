#ifndef SIMPLY_LINKED_LIST_HPP
#define SIMPLY_LINKED_LIST_HPP

typedef const int Error_code;
Error_code success = 0;
Error_code overflow = -1;
Error_code range_error = -2;
Error_code out_of_bound = -3;

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
    ~SimplyLinkedList();
    
    bool empty();
    bool full();
    void clear();
    int size() const;

    template <class _List_entry>
    friend void reverse_traverse_list(SimplyLinkedList<_List_entry> &a_list, void (*visit)(_List_entry &));

    bool is_out_of_bound(int position)
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

    void traverse(void (*visit)(List_entry &));

protected:
    int count;
    mutable int current_position;
    Node<List_entry> *head;
    mutable Node<List_entry> *current;

    void set_position(int position) const;
};

template <class List_entry>
SimplyLinkedList<List_entry>::SimplyLinkedList()
{
    count = 0;
    current_position = 0;
    head = NULL;
    current = head;
}

template <class List_entry>
SimplyLinkedList<List_entry>::~SimplyLinkedList()
{
    Node<List_entry> *it_pointer;
    Node<List_entry> *temp;

    for (it_pointer = head; it_pointer != NULL; )
    {
        temp = it_pointer;
        it_pointer=it_pointer->next;
        delete temp;
        count--;
    }

    current_position = 0;
    head = NULL;
    current = head;
}

template <class List_entry>
int SimplyLinkedList<List_entry>::size() const
{
    return count;
}

template <class List_entry>
void SimplyLinkedList<List_entry>::set_position(int position) const
{
    if (position < current_position)
    {
        current_position = 0;
        current = head;
    }
    for (; current_position != position; current_position++)
    {
        current = current->next;
    }
}

#endif