#include "ContiguousList.hpp"

template<class List_entry>
List<List_entry>::List()
{
    count = 0;
}

template<class List_entry>
void List<List_entry>::clear()
{
    count = 0;
}

template<class List_entry>
int List<List_entry>::size() const
{
    return count;
}

template<class List_entry>
bool List<List_entry>::empty() const
{
    return count == 0;
}

template<class List_entry>
bool List<List_entry>::full() const
{
    return count == max_list;
}

template<class List_entry>
Error_code List<List_entry>::retrieve(int postion, List_entry &x) const
{
    if (postion >=0 && postion < count)
    {
        x = entry[postion];
    }
    else 
    {
        return -1;
    }
}