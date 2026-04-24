#pragma once
#include <iostream>
#include <memory>

class DoublyLinkedList {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
        
        Node(int value) : value(value), next(nullptr), prev(nullptr) {}
        
        ~Node() {
            std::cout << "Destroying node " << value << "\n";
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedList() = default;
    ~DoublyLinkedList() = default;

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void push_back(int value) {
        auto new_node = std::make_shared<Node>(value);

        if (head_ == nullptr) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next = new_node;
            new_node->prev = tail_;
            tail_ = new_node;
        }
    }

    void print_forward(std::ostream& os) const {
        std::shared_ptr<Node> current = head_;
        while (current != nullptr) {
            os << current->value;
            if (current->next != nullptr) {
                os << " <-> ";
            }
            current = current->next;
        }
        os << "\n";
    }
};
