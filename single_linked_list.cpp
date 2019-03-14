/*
 * Problem: Reverse a single linked list.
 * Key points:
 *  1. Use a pointer to a pointer that points the head as the arguments that refer to the list head to functor functions if
 *     you don't create a list class and make a Node *head as its data member.
 *  2. For list creating function, once create a new node, make its next pointer points to the original head first,
 *     and then you can make head points to it.
 *  3. For free function, use a temp pointer to hold next node first and then delete the node. Remember to assign NULL to head at the end.
 *  4. For the reverse function, utilize three assistant pointers: pre, current, and next. Initialize pre to NULL,
 *     current to head outside the loop, and make next = current->next; as the first statement inside the loop, current->next = pre; the
 *     second. The remain two statements inside the loop move pre and current pointers each one step to the right.
 *  5. You can draw three node figures and refresh them after each time of the execution of each of the loop steps.
 *     This is the ULTIMATE WEAPON for this problem.
 * Author: Chuan Qin (qc2105@qq.com) 2019-03-15
 * License: GPLv2
 * 
 */

#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};

class Single_Linked_List
{
  public:
    Single_Linked_List(string size);
    ~Single_Linked_List();

    void reverse();
    void print();

    bool is_number(const std::string& s);

    Node *head;
    size_t length;
};

Single_Linked_List::Single_Linked_List(string size)
{
    head = NULL;
    length = 0;

    if (size.length() == 0 || !is_number(size) || stoi(size) <= 0)
    {
        return;
    }
    for (size_t n = stoi(size); n >= 1; n--, length++)
    {
        Node *new_node = new Node();
        new_node->data = n;
        new_node->next = head;
        head = new_node;
    }
}

Single_Linked_List::~Single_Linked_List()
{
    Node *pointer = head;
    Node *temp = NULL;
    while (pointer != NULL)
    {
        temp = pointer->next;
        delete pointer;
        pointer = temp;
    }

    head = NULL;
}

void Single_Linked_List::reverse()
{
    Node *current = head;
    Node *next = NULL;
    Node *pre = NULL;

    while (current != NULL)
    {
        next = current->next; // (0)
        current->next = pre;  // (1)
        pre = current;        // (2)
        current = next;       // (3)
    }

    head = pre;
}

void Single_Linked_List::print()
{
    Node *pointer = head;
    while (pointer != NULL)
    {
        cout << pointer->data << "->";
        pointer = pointer->next;
    }
    cout << "NULL"
         << ", length: " << length << endl;
}

bool Single_Linked_List::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <Size of the list>" << endl;
        return -1;
    }
    
    Single_Linked_List sl = Single_Linked_List(string(argv[1]));
    sl.print();

    sl.reverse();
    sl.print();

    return 0;
}