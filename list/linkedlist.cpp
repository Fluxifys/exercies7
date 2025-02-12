#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr), listSize(0) {}

LinkedList::~LinkedList()
{
    clear();
}

LinkedList::LinkedList(LinkedList &&other) noexcept
    : head(std::move(other.head)), listSize(other.listSize)
{
    other.listSize = 0;
}

LinkedList &LinkedList::operator=(LinkedList &&other) noexcept
{
    if (this != &other)
    {
        clear();
        head = std::move(other.head);
        listSize = other.listSize;
        other.listSize = 0;
    }
    return *this;
}

bool LinkedList::insert(int value)
{
    auto newNode = std::make_unique<Node>(value);
    bool inserted = false;

    if (!head)
    {
        // List is empty, insert as the first node
        head = std::move(newNode);
        inserted = true;
    }
    else
    {
        Node *current = head.get();
        Node *prev = nullptr;

        // Traverse to the correct position (sorted insertion)
        while (current && current->data < value)
        {
            prev = current;
            current = current->next.get();
        }

        // Check for duplicates; don't insert if already exists
        if (!(current && current->data == value))
        {
            if (!prev)
            {
                // Insert at the head if no previous node
                newNode->next = std::move(head);
                head = std::move(newNode);
            }
            else
            {
                // Insert after the previous node
                newNode->next = std::move(prev->next);
                prev->next = std::move(newNode);
            }
            inserted = true;
        }
    }

    if (inserted)
    {
        listSize++;
    }
    return inserted;
}

size_t LinkedList::size() const
{
    return listSize;
}

int LinkedList::search(int value) const
{
    Node *current = head.get();
    size_t position = 0;
    bool found = false;

    while (!found && current)
    {
        if (current->data == value)
        {
            found = true;
        }
        else
        {
            current = current->next.get();
            position++;
        }
    }
    if (!found)
    {
        position = -1;
    }
    return position;
}

bool LinkedList::remove(int value)
{
    Node *current = head.get();
    Node *prev = nullptr;
    bool removed = false;

    while (current)
    {
        if (current->data == value)
        {
            if (prev)
            {
                prev->next = std::move(current->next);
            }
            else
            {
                head = std::move(current->next);
            }
            listSize--;
            removed = true;
            break;
        }
        prev = current;
        current = current->next.get();
    }
    return removed;
}

bool LinkedList::edit(int oldValue, int newValue)
{
    bool success = false;
    if (remove(oldValue))
    {
        success = insert(newValue);
    }
    return success;
}

void LinkedList::clear()
{
    head.reset();
    listSize = 0;
}
