#ifndef LINKEDLISTPROJECT_LINKEDLIST_H
#define LINKEDLISTPROJECT_LINKEDLIST_H

#include <iostream>
#include <string>

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
    ~LinkedList(){
        clear();
    }

    //modification
    void add(const T& value){
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }
    void remove(const std::string id){
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data == id) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }

                delete current;
                size--;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    void clear(){
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        size = 0;
    }
    bool update(const std::string id, const T& value){
        Node* current = head;

        while (current != nullptr) {
            if (current->data == id) {
                current->data = value;
                return true;
            }

            current = current->next;
        }

        return false;
    }

    //special util
    bool contains(const T& value){
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }

            current = current->next;
        }

        return false;
    }
    bool contains(const std::string id){
        Node* current = head;

        while (current != nullptr) {
            if (current->data == id) {
                return true;
            }

            current = current->next;
        }

        return false;
    }
    T* search(const std::string id){
        Node* current = head;

        while (current != nullptr) {
            if (current->data == id) {
                return &(current->data);
            }

            current = current->next;
        }
        return nullptr;
    }
    size_t getSize() const{
        return size;
    }

    void print() const{
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << "\n";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

#endif
