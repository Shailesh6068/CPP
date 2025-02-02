#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    // Enqueue function
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
            newNode->next = front; // Point to itself
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Make it circular
        }
    }

    // Dequeue function
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return -1; // Indicate empty queue
        }

        int value = front->data;
        Node* temp = front;

        if (front == rear) {
            // Only one element in the queue
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
            rear->next = front; // Maintain circularity
        }

        delete temp;
        return value;
    }

    // Display function
    void display() const {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularQueue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue elements: ";
    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Queue after dequeue: ";
    queue.display();

    return 0;
}
