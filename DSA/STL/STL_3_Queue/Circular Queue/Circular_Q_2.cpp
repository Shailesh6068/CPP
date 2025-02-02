#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, size;

public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {                          //         front            rear       jar aapan full check karayal 
        return (rear + 1) % size == front;  //          1     2  3  4  5   6       rear+1 == front use kel tar te problem 
                                             // deil tyamule (rear + 1) % size == front    he use karayach
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % size;
        queue[rear] = value;
        cout << "Enqueued: " << value << endl;           
    }                                                    

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // or throw an exception
        }
        int value = queue[front];
        if(front == rear){ // Queue is now empty
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Dequeued: " << value << endl;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // or throw an exception
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        int index = front;
        while (true) 
        {
            cout << queue[index] << " ";
            if (index == rear) break;
            index = (index + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); // This will show "Queue is full!"
    cq.display();
    return 0;
}
