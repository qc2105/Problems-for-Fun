#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>

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
    Node(Node_entry _entry, Node<Node_entry> *_back = NULL, Node<Node_entry> *_next = NULL);

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
Node<Node_entry>::Node(Node_entry _entry, Node<Node_entry> *_back, Node<Node_entry> *_next)
{
    entry = _entry;
    back = _back;
    next = _next;
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
    clear();
}

template <class List_entry>
bool DoublyLinkedList<List_entry>::empty() const
{
    return count == 0;
}

template <class List_entry>
void DoublyLinkedList<List_entry>::clear()
{
    Node<List_entry> *pNode_forward = NULL, *pNode_backward = NULL, *temp = NULL;
    pNode_forward = current;
    if (NULL != current)
    {
        pNode_backward = current->back;
    }
    while (pNode_forward != NULL)
    {
        temp = pNode_forward;
        pNode_forward = pNode_forward->next;
        delete temp;
        count--;
    }
    while (pNode_backward != NULL)
    {
        temp = pNode_backward;
        pNode_backward = pNode_backward->back;
        delete temp;
        count--;
    }

    set_position(0);
    current = NULL;
}

template <class List_entry>
int DoublyLinkedList<List_entry>::size() const
{
    return count;
}

template <class List_entry>
Error_code DoublyLinkedList<List_entry>::insert(int position, const List_entry &x)
{
    if (position < 0 || position > count)
    {
        return out_of_bound;
    }

    Node<List_entry> *new_node = NULL, *following = NULL, *preceding = NULL;
    if (0 == position)
    {
        if (0 == count)
        {
            following = NULL;
        }
        else
        {
            set_position(0);
            following = current;
        }
        preceding = NULL;
    }
    else
    {
        set_position(position - 1);
        preceding = current;
        following = preceding->next;
    }

    new_node = new Node<List_entry>(x, preceding, following);
    if (NULL == new_node)
    {
        return overflow;
    }
    if (NULL != preceding)
    {
        preceding->next = new_node;
    }
    if (NULL != following)
    {
        following->back = new_node;
    }
    current = new_node;
    current_position = position;
    count++;

    return success;
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