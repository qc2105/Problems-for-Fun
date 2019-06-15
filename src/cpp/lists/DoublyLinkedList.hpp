#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

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
    Node(Node_entry _entry, Node<Node_entry> *_next = NULL, Node<Node_entry> *_back = NULL);

    Node_entry entry;
    Node<Node_entry> *next;
    Node<Node_entry> *back;
};

template <class Node_entry>
Node<Node_entry>::Node()
{
    entry = 0;
    next = NULL;
    back = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry _entry, Node<Node_entry> *_next, Node<Node_entry> *_back)
{
    entry = _entry;
    next = _next;
    back = _back;
}

template <class List_entry>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<List_entry> &);
    ~DoublyLinkedList();

    bool empty() const;
    void clear();
    int size() const;

protected:
    int count = 0;
    mutable int current_position = 0;
    mutable Node<List_entry> *current = NULL;

    void set_position(int position) const;
};

template <class List_entry>
DoublyLinkedList<List_entry>::DoublyLinkedList()
{
    count = 0;
    set_position(0);
    current = NULL;
}

template <class List_entry>
DoublyLinkedList<List_entry>::~DoublyLinkedList()
{
    Node<List_entry> *pNode_forward, *pNode_backward;
    pNode_backward = pNode_forward = current;
    while (pNode_forward != NULL)
    {
        delete pNode_forward++;
        count--;
    }
    while (pNode_backward != NULL)
    {
        delete --pNode_backward;
        count--;
    }

    current = NULL;
    set_position(0);
}

template <class List_entry>
int DoublyLinkedList<List_entry>::size() const
{
    return count;
}

template <class List_entry>
void DoublyLinkedList<List_entry>::set_position(int position) const
{
    if (current_position <= position)
    {
        for (; current_position != position; current_position++)
        {
            current = current->next;
        }
    }
    else
    {
        for (; current_position != position; current_position--)
        {
            current = current->back;
        }
    }
}

#endif