#include "linkedlist.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, HandlesEmptyList) {
    LinkedList list;
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListTest, HandlesInsert) {
    LinkedList list;
    EXPECT_TRUE(list.insert(5));
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.insert(10));
    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.insert(7));
    EXPECT_EQ(list.size(), 3);
    EXPECT_TRUE(list.insert(3));
    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.insert(8));
    EXPECT_EQ(list.size(), 5);
}

TEST(LinkedListTest, HandlesDuplicate) {
    LinkedList list;
    EXPECT_TRUE(list.insert(5));
    EXPECT_FALSE(list.insert(5));
    EXPECT_EQ(list.size(), 1);
}

TEST(LinkedListTest, HandlesSearch) {
    LinkedList list;
    EXPECT_TRUE(list.insert(5));
    EXPECT_TRUE(list.insert(10));
    EXPECT_TRUE(list.insert(7));
    EXPECT_TRUE(list.insert(3));
    EXPECT_TRUE(list.insert(8));
    EXPECT_EQ(list.search(5), 1);
    EXPECT_EQ(list.search(10), 4);
    EXPECT_EQ(list.search(7), 2);
    EXPECT_EQ(list.search(3), 0);
    EXPECT_EQ(list.search(8), 3);
    EXPECT_EQ(list.search(1), -1);
    EXPECT_EQ(list.search(6), -1);
    EXPECT_EQ(list.search(9), -1);
}

TEST(LinkedListTest, HandleRemove){
    LinkedList list;
    EXPECT_TRUE(list.insert(5));
    EXPECT_TRUE(list.insert(10));
    EXPECT_TRUE(list.insert(7));
    EXPECT_TRUE(list.insert(3));
    EXPECT_TRUE(list.insert(8));
    EXPECT_TRUE(list.remove(5));
    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list.search(5), -1);
    EXPECT_TRUE(list.remove(10));
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.search(10), -1);
    EXPECT_TRUE(list.remove(8));
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.search(8), -1);
    EXPECT_TRUE(list.remove(7));
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.search(7), -1);
    EXPECT_TRUE(list.remove(3));
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.search(3), -1);
}

TEST(LinkedListTest, HandleEdit){
    LinkedList list;
    EXPECT_TRUE(list.insert(5));
    EXPECT_TRUE(list.insert(10));
    EXPECT_TRUE(list.insert(7));
    EXPECT_TRUE(list.insert(3));
    EXPECT_TRUE(list.insert(8));
    EXPECT_TRUE(list.edit(5, 6));
    EXPECT_EQ(list.search(5), -1);
    EXPECT_EQ(list.search(6), 1);
    EXPECT_TRUE(list.edit(10, 11));
    EXPECT_EQ(list.search(10), -1);
    EXPECT_EQ(list.search(11), 4);
    EXPECT_TRUE(list.edit(7, 9));
    EXPECT_EQ(list.search(7), -1);
    EXPECT_EQ(list.search(9), 3);
    EXPECT_TRUE(list.edit(3, 4));
    EXPECT_EQ(list.search(3), -1);
    EXPECT_EQ(list.search(4), 0);
    EXPECT_TRUE(list.edit(8, 12));
    EXPECT_EQ(list.search(8), -1);
    EXPECT_EQ(list.search(12), 4);
}

TEST(LinkedList, HandleClear){
    LinkedList list;
    EXPECT_TRUE(list.insert(5));
    EXPECT_TRUE(list.insert(10));
    EXPECT_TRUE(list.insert(7));
    EXPECT_TRUE(list.insert(3));
    EXPECT_TRUE(list.insert(8));
    list.clear();
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.search(5), -1);
    EXPECT_EQ(list.search(10), -1);
    EXPECT_EQ(list.search(7), -1);
    EXPECT_EQ(list.search(3), -1);
    EXPECT_EQ(list.search(8), -1);
}

TEST(LinkedList, HandleMove){
    LinkedList list;
    EXPECT_TRUE(list.insert(5));
    EXPECT_TRUE(list.insert(10));
    EXPECT_TRUE(list.insert(7));
    EXPECT_TRUE(list.insert(3));
    EXPECT_TRUE(list.insert(8));
    LinkedList list2{std::move(list)};
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list2.size(), 5);
    list = std::move(list2);
    EXPECT_EQ(list.size(), 5);
    EXPECT_EQ(list2.size(), 0);
    list = std::move(list);
    EXPECT_EQ(list.size(), 5);
    list.clear();
    EXPECT_EQ(list.size(), 0);
}