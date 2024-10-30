#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Add a node at the end
    void add(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node by value
    void deleteNode(int data) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == data) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next; // If the node to delete is head
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
                delete temp; // Free the memory
                return;
            }
            temp = temp->next;
        }
    }

    // Display the list in forward direction
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Display the list in backward direction
    void displayBackward() {
        Node* temp = head;
        if (temp == nullptr) return;

        // Go to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Traverse backward
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }

    // Destructor to free the memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.add(10);
    dll.add(20);
    dll.add(30);
    dll.add(40);

    std::cout << "Doubly linked list in forward direction:" << std::endl;
    dll.displayForward();

    std::cout << "Doubly linked list in backward direction:" << std::endl;
    dll.displayBackward();

    dll.deleteNode(20);
    std::cout << "After deleting 20:" << std::endl;
    dll.displayForward();

    return 0;
}
