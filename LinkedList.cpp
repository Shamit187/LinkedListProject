#include "LinkedList.h"
template <typename T>
void LinkedList<T>::add(const T& value) {
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

template <typename T>
void LinkedList<T>::remove(const T& value) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
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

template <typename T>
bool LinkedList<T>::contains(const T& value){
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    size = 0;
}

template <typename T>
size_t LinkedList<T>::getSize() const {
    return size;
}

template <typename T>
void LinkedList<T>::print() const {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}