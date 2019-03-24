#ifndef LIST_HPP
#define LIST_HPP

typedef int Error_code;

template <class List_entry>
class List
{
  public:
    List();
    List(int n);
    void clear();
    
    bool empty() const;
    bool full() const;
    bool size() const;

    Error_code insert(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
    Error_code retrieve(int position, List_entry &x) const;
    Error_code replace(int position, const List_entry &x);

    void traverse(void (*visit)(List_entry &));
};

#endif