#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

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
    }

    // Delete a node by value
    void deleteNode(int data) {
        Node* temp = head;
        Node* prev = nullptr;

        // If the node to be deleted is the head node
        if (temp != nullptr && temp->data == data) {
            head = temp->next; // Change head
            delete temp;       // Free memory
            return;
        }

        // Search for the node to delete
        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        // If the data was not present in the list
        if (temp == nullptr) return;

        // Unlink the node from the linked list
        prev->next = temp->next;
        delete temp; // Free memory
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    SinglyLinkedList sll;
    sll.add(10);
    sll.add(20);
    sll.add(30);
    sll.add(40);

    std::cout << "Singly linked list:" << std::endl;
    sll.display();

    sll.deleteNode(20);
    std::cout << "After deleting 20:" << std::endl;
    sll.display();

    return 0;
}
