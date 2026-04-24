#pragma once
#include <iostream>
#include <memory>

class LinkedList {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;
        Node(int value) : value(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    
    ~LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        auto new_node = std::make_unique<Node>(value);
        Node* raw_ptr = new_node.get(); 

        if (head_ == nullptr) {
            head_ = std::move(new_node);
            tail_ = raw_ptr;
        } else {
            tail_->next = std::move(new_node);
            tail_ = raw_ptr;
        }
    }

    void print(std::ostream& os) const {
        Node* current = head_.get();
        while (current != nullptr) {
            os << current->value;
            if (current->next != nullptr) {
                os << " -> ";
            }
            current = current->next.get();
        }
        os << "\n";
    }
};
