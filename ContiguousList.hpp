#ifndef CONTIGUOUS_LIST_HPP
#define CONTIGUOUS_LIST_HPP

const int max_list = 1000;

typedef const int Error_code;
Error_code success = 0;
Error_code overflow = -1;
Error_code range_error = -2;
Error_code out_of_bound = -3;

template <class List_entry>
class List
{
  public:
    List();
    void clear();

    bool empty() const;
    bool full() const;
    int size() const;

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
        return out_of_bound;
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
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (is_out_of_bound())
    {
        return out_of_bound;
    }

    x = entry[position];

    for (int i = position; i < count - 1; i++)
    {
        entry[position] = entry[position + 1];
    }

    return success;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
{
    for (int i = 0; i < count; i++)
    {
        (*visit)(entry[i]);
    }
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
    if (is_out_of_bound())
    {
        return out_of_bound;
    }

    entry[position] = x;
    return success;
}

template <class List_entry>
Error_code insert_first(const List_entry &x, List<List_entry> &a_list);

template <class List_entry>
Error_code remove_first(List_entry &x, List<List_entry> &a_list);

template <class List_entry>
Error_code insert_last(const List_entry &x, List<List_entry> &a_list);

template <class List_entry>
Error_code remove_last(List_entry &x, List<List_entry> &a_list);

template <class List_entry>
Error_code median_list(List_entry &x, List<List_entry> &a_list);

template <class List_entry>
Error_code interchange(int pos1, int pos2, List<List_entry> &a_list);

template <class List_entry>
void reverse_traverse_list(List<List_entry> &a_list, void (*visit)(List_entry &));

template <class List_entry>
Error_code copy(List<List_entry> &dest, List<List_entry> &source);

template <class List_entry>
Error_code join(List<List_entry> &list1, List<List_entry> &list2);

template <class List_entry>
void reverse(List<List_entry> &a_list);

template <class List_entry>
Error_code split(List<List_entry> &source, List<List_entry> &oddlist, List<List_entry> &evenlist);

template <class List_entry>
Error_code insert_first(const List_entry &x, List<List_entry> &a_list)
{
    List_entry temp;
    Error_code ret;
    for (int i = a_list.size() - 1; i > 0; i--)
    {
        ret = a_list.retrieve(i, temp);
        if (ret != success)
        {
            return ret;
        }

        ret = a_list.insert(i + 1, temp);

        if (ret != success)
        {
            return ret;
        }
    }
    
    ret = a_list.replace(0, x);
    if (ret != success)
    {
        return ret;
    }

    return success;
}

#endif