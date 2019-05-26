#include <gtest/gtest.h>
#include "SimplyLinkedList.hpp"

#include <iostream>

using namespace std;
using ::testing::InitGoogleTest;
using ::testing::Test;

TEST(TestSimplyLinkedList, test_node_null_contor)
{
    Node<float> node = Node<float>();

    ASSERT_EQ(node.next, nullptr);
    ASSERT_EQ(node.entry, 0);
}

TEST(TestSimplyLinkedList, test_node_contor)
{
    Node<float> node_0 = Node<float>();
    Node<float> node = Node<float>(1.f, &node_0);

    ASSERT_EQ(node.next, &node_0);
    ASSERT_EQ(node.entry, 1.f);
}

TEST(TestSimplyLinkedList, test_list_contor)
{
    SimplyLinkedList<float> slist = SimplyLinkedList<float>();

    ASSERT_EQ(slist.size(), 0);
}

TEST(TestSimplyLinkedList, test_list_copy_contor)
{
    SimplyLinkedList<int> slist = SimplyLinkedList<int>();
    slist.insert(0, 0);
    slist.insert(1, 1);
    slist.insert(2, 2);

    SimplyLinkedList<int> copied(slist);

    int value = -1;
    copied.retrieve(0, value);
    ASSERT_EQ(value, 0);

    copied.retrieve(1, value);
    ASSERT_EQ(value, 1);

    copied.retrieve(2, value);
    ASSERT_EQ(value, 2);
}

TEST(TestSimplyLinkedList, test_assignment_operator)
{
    SimplyLinkedList<int> slist = SimplyLinkedList<int>();
    slist.insert(0, 0);
    slist.insert(1, 1);
    slist.insert(2, 2);

    SimplyLinkedList<int> assigned = slist;

    int value = -1;
    assigned.retrieve(0, value);
    ASSERT_EQ(value, 0);

    assigned.retrieve(1, value);
    ASSERT_EQ(value, 1);

    assigned.retrieve(2, value);
    ASSERT_EQ(value, 2);
}

TEST(TestSimplyLinkedList, test_empty)
{
    SimplyLinkedList<float> slist = SimplyLinkedList<float>();

    ASSERT_TRUE(slist.empty());
}

TEST(TestSimplyLinkedList, test_insert)
{
    SimplyLinkedList<float> slist = SimplyLinkedList<float>();

    int ret = slist.insert(0, 5.5f);
    ASSERT_EQ(ret, 0);
    float value;
    slist.retrieve(0, value);
    ASSERT_EQ(value, 5.5f);
    ASSERT_EQ(slist.size(), 1);

    ret = slist.insert(1, 5.6f);
    ASSERT_EQ(ret, 0);
    slist.retrieve(1, value);
    ASSERT_EQ(value, 5.6f);
    ASSERT_EQ(slist.size(), 2);

    ret = slist.insert(1, 7.7f);
    ASSERT_EQ(ret, 0);
    slist.retrieve(1, value);
    ASSERT_EQ(value, 7.7f);
    ASSERT_EQ(slist.size(), 3);
    slist.retrieve(2, value);
    ASSERT_EQ(value, 5.6f);

    ret = slist.insert(100, 50.f);
    ASSERT_EQ(ret, out_of_bound);
}

TEST(TestSimplyLinkedList, test_clear)
{
    SimplyLinkedList<float> slist = SimplyLinkedList<float>();

    slist.insert(0, 5.5);
    slist.insert(1, 6.6);
    slist.clear();

    ASSERT_EQ(slist.size(), 0);
}

TEST(TestSimplyLinkedList, test_size)
{
    SimplyLinkedList<float> slist = SimplyLinkedList<float>();

    slist.insert(0, 5.5);
    ASSERT_EQ(slist.size(), 1);

    slist.insert(1, 6.6);
    ASSERT_EQ(slist.size(), 2);

    slist.insert(1, 7.7);
    ASSERT_EQ(slist.size(), 3);

    slist.clear();
    ASSERT_EQ(slist.size(), 0);
}

TEST(TestSimplyLinkedList, test_reverse)
{
    SimplyLinkedList<float> slist = SimplyLinkedList<float>();

    slist.insert(0, 5.5);

    slist.insert(1, 6.6);

    slist.insert(1, 7.7);

    slist.reverse();

    float value;
    slist.retrieve(0, value);
    ASSERT_EQ(value, 6.6f);

    slist.retrieve(1, value);
    ASSERT_EQ(value, 7.7f);

    slist.retrieve(2, value);
    ASSERT_EQ(value, 5.5f);
}

template <class List_entry>
void add_one(List_entry &x)
{
    x += 1;
}

TEST(TestSimplyLinkedList, test_traverse)
{
    SimplyLinkedList<int> slist = SimplyLinkedList<int>();

    slist.insert(0, 5);

    slist.insert(1, 6);

    slist.insert(2, 7);

    slist.traverse(add_one);

    int value;
    slist.retrieve(0, value);
    ASSERT_EQ(value, 6);

    slist.retrieve(1, value);
    ASSERT_EQ(value, 7);

    slist.retrieve(2, value);
    ASSERT_EQ(value, 8);
}

TEST(TestSimplyLinkedList, test_reverse_traverse_list)
{
    SimplyLinkedList<int> slist = SimplyLinkedList<int>();

    slist.insert(0, 5);

    slist.insert(1, 6);

    slist.insert(1, 7);

    reverse_traverse_list(slist, add_one);

    int value;
    slist.retrieve(0, value);
    ASSERT_EQ(value, 6);

    slist.retrieve(1, value);
    ASSERT_EQ(value, 8);

    slist.retrieve(2, value);
    ASSERT_EQ(value, 7);
}

TEST(TestSimplyLinkedList, test_remove_and_retrieve)
{
    SimplyLinkedList<int> slist = SimplyLinkedList<int>();

    slist.insert(0, 5);

    slist.insert(1, 6);

    slist.insert(1, 7); // slist: 5->7->6

    int value = -1;
    int ret;
    ret = slist.remove(0, value);

    ASSERT_EQ(ret, success);
    ASSERT_EQ(value, 5);
    ASSERT_EQ(slist.size(), 2);

    slist.retrieve(0, value);
    ASSERT_EQ(value, 7);
    slist.retrieve(1, value);
    ASSERT_EQ(value, 6);

    slist.insert(0, 8); // slist: 8->7->6
    slist.retrieve(1, value);
    ASSERT_EQ(value, 7);
    slist.retrieve(0, value);
    ASSERT_EQ(value, 8);
    slist.retrieve(2, value);
    ASSERT_EQ(value, 6);

    slist.remove(1, value);
    ASSERT_EQ(value, 7);
}

TEST(TestSimplyLinkedList, test_replace)
{
    SimplyLinkedList<int> slist = SimplyLinkedList<int>();

    slist.insert(0, 5);

    slist.insert(1, 6);

    slist.insert(1, 7); // slist: 5->7->6

    int value = -1;
    int ret;

    ret = slist.replace(1, 8);
    ASSERT_EQ(ret, success);
    slist.retrieve(1, value);
    ASSERT_EQ(value, 8); // 5->8->6

    ret = slist.replace(0, 9);
    ASSERT_EQ(ret, success);
    slist.retrieve(0, value);
    ASSERT_EQ(value, 9); // 9->8->6

    ret = slist.replace(2, 10);
    ASSERT_EQ(ret, success);
    slist.retrieve(2, value);
    ASSERT_EQ(value, 10); // 9->8->10
}

int main()
{
    InitGoogleTest();

    return RUN_ALL_TESTS();
}