#include <gtest/gtest.h>
#include <iostream>

#include "DoublyLinkedList.hpp"

using namespace std;
using ::testing::InitGoogleTest;
using ::testing::Test;

TEST(TestDoublyLinkedList, testNodeContor)
{
    Node<float> nod = Node<float>();

    ASSERT_EQ(nod.entry, 0.f);
    ASSERT_EQ(nod.next, nullptr);
    ASSERT_EQ(nod.back, nullptr);

    Node<float> nod2 = Node<float>(2.f, &nod, &nod);

    ASSERT_EQ(nod2.entry, 2.f);
    ASSERT_EQ(nod2.next, &nod);
    ASSERT_EQ(nod2.back, &nod);
}

TEST(TestDoublyLinkedList, testListContor)
{
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();

    ASSERT_EQ(dl.size(), 0);
}

TEST(TestDoublyLinkedList, testEmpty)
{
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();

    ASSERT_TRUE(dl.empty());
}

template <class List_entry>
void add_one(List_entry &x)
{
    x += 1;
}

TEST(TestDoublyLinkedList, testTraverse)
{
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();

    dl.insert(0, 0);
    dl.insert(1, 1);
    dl.insert(2, 2);

    dl.traverse(add_one);

    int value;
    dl.retrieve(0, value);
    ASSERT_EQ(value, 1);

    dl.retrieve(1, value);
    ASSERT_EQ(value, 2);

    dl.retrieve(2, value);
    ASSERT_EQ(value, 3);
}

TEST(TestDoublyLinkedList, testInsert)
{
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();
    int ret = dl.insert(100, 60);
    ASSERT_EQ(ret, out_of_bound);

    ret = dl.insert(0, 1);
    ASSERT_EQ(ret, success);
    ASSERT_EQ(1, dl.size());

    ret = dl.insert(0, 2);
    ASSERT_EQ(ret, success);
    ASSERT_EQ(2, dl.size());

    ret = dl.insert(1, 3);
    ASSERT_EQ(ret, success);
    ASSERT_EQ(3, dl.size());

    ret = dl.insert(3, 4);
    ASSERT_EQ(ret, success);
    ASSERT_EQ(4, dl.size());
}

TEST(TestDoublyLinkedList, testClear)
{
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();
    dl.clear();

    ASSERT_TRUE(dl.empty());
}

TEST(TestDoublyLinkedList, test_replace)
{
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();

    dl.insert(0, 5);

    dl.insert(1, 6);

    dl.insert(1, 7); // dl: 5->7->6

    int value = -1;
    int ret;

    ret = dl.replace(1, 8);
    ASSERT_EQ(ret, success);
    dl.retrieve(1, value);
    ASSERT_EQ(value, 8); // 5->8->6

    ret = dl.replace(0, 9);
    ASSERT_EQ(ret, success);
    dl.retrieve(0, value);
    ASSERT_EQ(value, 9); // 9->8->6

    ret = dl.replace(2, 10);
    ASSERT_EQ(ret, success);
    dl.retrieve(2, value);
    ASSERT_EQ(value, 10); // 9->8->10
}

TEST(TestDoublyLinkedList, test_remove_and_retrieve)
{
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();

    dl.insert(0, 5);

    dl.insert(1, 6);

    dl.insert(1, 7); // dl: 5<->7<->6

    int x = 0;
    int ret = dl.remove(0, x); // dl: 7<->6

    ASSERT_EQ(ret, success);
    ASSERT_EQ(x, 5);
    ASSERT_EQ(dl.size(), 2);
    ret = dl.retrieve(0, x);
    ASSERT_EQ(x, 7);
    ASSERT_EQ(ret, success);
    ret = dl.retrieve(1, x);
    ASSERT_EQ(x, 6);
    ASSERT_EQ(ret, success);

    dl.insert(0, 5); // dl: 5<->7<->6

    ret = dl.remove(1, x);
    ASSERT_EQ(ret, success);
    ASSERT_EQ(x, 7);
    ASSERT_EQ(dl.size(), 2);
    ret = dl.retrieve(0, x);
    ASSERT_EQ(x, 5);
    ASSERT_EQ(ret, success);

    dl.insert(1, 7);

    ret = dl.remove(2, x);
    ASSERT_EQ(ret, success);
    ASSERT_EQ(x, 6);
    ASSERT_EQ(dl.size(), 2);
    ret = dl.retrieve(0, x);
    ASSERT_EQ(x, 5);
    ASSERT_EQ(ret, success);
    ret = dl.retrieve(2, x);
    ASSERT_EQ(ret, out_of_bound);
}

int main()
{
    InitGoogleTest();

    return RUN_ALL_TESTS();
}