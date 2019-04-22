#ifndef CONTIGUOUS_LIST_HPP
#define CONTIGUOUS_LIST_HPP

typedef int Error_code;
const int success = 0;
const int overflow = 1;
const int range_error = -2;
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

template <class List_entry>
List<List_entry>::List()
{
    count = 0;
}

template <class List_entry>
void List<List_entry>::clear()
{
    count = 0;
}

template <class List_entry>
int List<List_entry>::size() const
{
    return count;
}

template <class List_entry>
bool List<List_entry>::empty() const
{
    return count == 0;
}

template <class List_entry>
bool List<List_entry>::full() const
{
    return count == max_list;
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int postion, List_entry &x) const
{
    if (postion >= 0 && postion < count)
    {
        x = entry[postion];
    }
    else
    {
        return -1;
    }
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
    if (full())
    {
        return overflow;
    }
    if (position < 0 || position > count)
    {
        return range_error;
    }
    for (int i = count - 1; i >= position; i--)
    {
        entry[i + 1] = entry[i];
    }
    entry[position] = x;
    count++;
    return success;
}

template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &))
{
    for (int i = 0; i < count; i++)
    {
        (*visit)(entry[i]);
    }
}

#endif