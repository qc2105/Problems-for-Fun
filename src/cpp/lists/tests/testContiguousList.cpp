#include <iostream>
#include <gtest/gtest.h>

using ::testing::InitGoogleTest;
using ::testing::Test;

#include "ContiguousList.hpp"

using namespace std;

TEST(TestContiguousList, test_size)
{
    List<int> myList = List<int>();
    ASSERT_EQ(myList.size(), 0);
}

TEST(TestContiguousList, test_function_full)
{
    List<int> myList = List<int>();
    ASSERT_FALSE(myList.full());
}

TEST(TestContiguousList, test_insert_retrieve)
{
    List<int> myList = List<int>();
    int value;
    ASSERT_EQ(myList.insert(0, 5), success);
    ASSERT_EQ(myList.retrieve(0, value), success);
    ASSERT_EQ(myList.size(), 1);
    int x, y;
    myList.retrieve(0, x);
    myList.insert(1, 6);
    ASSERT_EQ(x, 5);
    myList.retrieve(1, y);
    ASSERT_EQ(y, 6);
}

TEST(TestContiguousList, test_remove)
{
    double value = 0.1;
    List<double> list = List<double>();

    list.insert(0, 0.0);
    list.insert(1, 1.0);
    list.insert(2, 2.0);

    list.remove(1, value);
    ASSERT_EQ(1, value);
    ASSERT_EQ(2, list.size());
    list.retrieve(0, value);
    ASSERT_EQ(value, 0.0);
    list.retrieve(1, value);
    ASSERT_EQ(value, 2.0);
}

TEST(TestContiguousList, test_insert_last)
{
    List<double> list = List<double>();
    double value = 0.1;

    insert_last(0.0, list);
    list.retrieve(0, value);
    ASSERT_EQ(0.0, value);

    list.insert(1, 1.0);
    list.insert(2, 2.0);

    insert_last<double>(3.0, list);
    list.retrieve(3, value);
    ASSERT_EQ(3.0, value);
}

TEST(TestContiguousList, test_remove_last)
{
    double value = 0.1;
    List<double> list = List<double>();

    list.insert(0, 0.0);
    list.insert(1, 1.0);
    list.insert(2, 2.0);

    remove_last(value, list);
    ASSERT_EQ(value, 2.0);
    ASSERT_EQ(2, list.size());

    list.retrieve(list.size() - 1, value);
    ASSERT_EQ(1.0, value);
}

TEST(TestContiguousList, test_median_list)
{
    double value = 0.1;
    List<double> list = List<double>();

    list.insert(0, 0.0);
    list.insert(1, 1.0);
    list.insert(2, 2.0);

    median_list(value, list);
    ASSERT_EQ(value, 1.0);

    list.insert(3, 3.0);
    list.insert(4, 4.0);
    list.insert(5, 5.0);

    median_list(value, list);
    ASSERT_EQ(value, 2.0);
}

TEST(TestContiguousList, test_replace)
{
    double value = 0.1;
    List<double> list = List<double>();
    list.insert(0, 0.0);
    list.insert(1, 1.0);
    list.insert(2, 2.0);

    list.replace(2, 3.0);
    list.retrieve(2, value);

    ASSERT_EQ(3.0, value);
}

TEST(TestContiguousList, test_interchange)
{
    double value = 0.1;
    List<double> list = List<double>();
    list.insert(0, 0.0);
    list.insert(1, 1.0);
    list.insert(2, 2.0);

    interchange(1, 2, list);
    list.retrieve(1, value);

    ASSERT_EQ(2.0, value);
    list.retrieve(2, value);
    ASSERT_EQ(1.0, value);

    interchange(0, 1, list);
    list.retrieve(0, value);
    ASSERT_EQ(2.0, value);
}

template <class List_entry>
void add_one(List_entry &x)
{
    x += 1;
}

TEST(TestContiguousList, test_reverse_traverse)
{
    List<double> list = List<double>();
    list.insert(0, 0.0);
    list.insert(1, 1.0);
    list.insert(2, 2.0);

    reverse_traverse_list(list, add_one);

    for (int i = 0; i < 3; i++)
    {
        double value;
        list.retrieve(i, value);
        ASSERT_EQ(value, double(i + 1));
    }
}

TEST(TestContiguousList, test_copy)
{
    List<double> list = List<double>();
    list.insert(0, 0.0);
    list.insert(1, 1.0);
    list.insert(2, 2.0);

    List<double> list2 = List<double>();
    list2.insert(0, 0.0);
    list2.insert(1, 3.0);

    copy(list2, list);

    ASSERT_EQ(list.size(), list2.size());
    for (int i = 0; i < list.size(); i++)
    {
        double value;
        list.retrieve(i, value);
        double value2;
        list2.retrieve(i, value2);
        ASSERT_EQ(value, value2);
    }
}

int main(int argc, char *argv[])
{
    InitGoogleTest();

    return RUN_ALL_TESTS();
}