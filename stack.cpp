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

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {}

    // Push an element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top; // Link the new node to the previous top
        top = newNode;       // Update the top to the new node
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return -1; // Return an error value
        }

        Node* temp = top;     // Store the current top node
        int poppedValue = temp->data; // Get the value to return
        top = top->next;      // Move the top pointer to t
