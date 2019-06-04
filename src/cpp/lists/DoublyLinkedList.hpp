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

protected:
    int count;
    mutable int current_position;
    mutable Node<List_entry> *current;

    void set_position(int position) const;
};

#endif