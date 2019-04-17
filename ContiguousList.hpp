#ifndef CONTIGUOUS_LIST_HPP
#define CONTIGUOUS_LIST_HPP

typedef int Error_code;
const int max_list = 1000;

template <class List_entry>
class List
{
  public:
    List();
    void clear();
    
    bool empty() const;
    bool full() const;
    int size() const;

    Error_code insert(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
    Error_code retrieve(int position, List_entry &x) const;
    Error_code replace(int position, const List_entry &x);

    void traverse(void (*visit)(List_entry &));

    Error_code insert_first(const List_entry &x, List &a_list);
    Error_code remove_first(List_entry &x, List &a_list);
    Error_code insert_last(const List_entry &x, List &a_list);
    Error_code remove_last(List_entry &x, List &a_list);
    Error_code median_list(List_entry &x, List &a_list);
    Error_code interchange(int pos1, int pos2, List &a_list);

    void reverse_traverse_list(List &a_list, void(*visit)(List_entry &));

    Error_code copy(List &dest, List &source);
    Error_code join(List &list1, List &list2);

    void reverse(List &a_list);
    
    Error_code split(List &source, List &oddlist, List &evenlist);
  
  protected:
    int count;
    List_entry entry[max_list];
};

#endif