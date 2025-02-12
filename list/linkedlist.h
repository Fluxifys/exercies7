#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    // Uncopyable and moveable
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    LinkedList(LinkedList&&) noexcept;
    LinkedList& operator=(LinkedList&&) noexcept;

    bool insert(int value);
    size_t size() const;
    int search(int value) const; // Return position or 0 if not found
    bool remove(int value);
    bool edit(int oldValue, int newValue);
    void clear();

private:
    struct Node {
        int data;
        std::unique_ptr<Node> next;
        Node(int val) : data(val), next(nullptr) {}
    };

    std::unique_ptr<Node> head;
    size_t listSize;
};

#endif
