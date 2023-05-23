#ifndef LINKEDLISTPROJECT_LINKEDLIST_H
#define LINKEDLISTPROJECT_LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    size_t size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    //modification
    void add(const T& value);
    void remove(const T& value);
    void clear();

    //special util
    bool contains(const T& value);
    size_t getSize() const;
    void print() const;
};



#endif
