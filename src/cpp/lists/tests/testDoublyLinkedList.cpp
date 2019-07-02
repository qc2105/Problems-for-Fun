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

int main()
{
    InitGoogleTest();

    return RUN_ALL_TESTS();
}