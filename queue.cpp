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

class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue an element at the rear of the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) { // If the queue is empty
            front = rear = newNode; // Both front and rear point to the new node
            return;
        }
        rear->next = newNode; // Link the new node after the rear
        rear = newNode;       // Update the rear to the new node
    }

    // Dequeue an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Return an error value
        }
        Node* temp = front;     // Store the current front node
        int dequeuedValue = temp->data; // Get the value to return
        front = front->next;    // Move the front pointer to the next node

        // If the queue becomes empty, update the rear pointer as well
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;            // Free the memory of the dequeued node
        return dequeuedValue;   // Return the dequeued value
    }

    // Peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek." << std::endl;
            return -1; // Return an error value
        }
        return front->data; // Return the value of the front node
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Dequeue all elements to free memory
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element is: " << queue.peek() << std::endl; // Should print 10

    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;  // Should print 10
    std::cout << "Front element is now: " << queue.peek() << std::endl; // Should print 20

    queue.dequeue(); // Remove 20
    queue.dequeue(); // Remove 30
    queue.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}
