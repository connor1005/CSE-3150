#pragma once
#include <iostream>

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int value) : value(value), next(nullptr) {}
    };
    
    Node* head_;
    Node* tail_; 

public:
    // Constructor
    LinkedList() {
        head_ = nullptr;
        tail_ = nullptr;
    }
    
    // Destructor (manual cleanup required for raw pointers)
    ~LinkedList() {
        Node* current = head_;
        while (current != nullptr) {
            Node* next_node = current->next; 
            delete current; 
            current = next_node; 
        }
    }
    
    // Copying disabled
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Append a node to the end
    void push_back(int value) {
        Node* new_node = new Node(value);
        
        if (head_ == nullptr) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next = new_node;
            tail_ = new_node;
        }
    }

    // Print the list
    void print(std::ostream& os) const {
        Node* current = head_;
        while (current != nullptr) {
            os << current->value;
            if (current->next != nullptr) {
                os << " -> "; // Format as 1 -> 2 -> 3
            }
            current = current->next;
        }
        os << "\n";
    }
};
