#include <iostream>
#include <climits>
using namespace std;
class PriorityQueue {
private:
    int* arr;       // Array to store elements
    int capacity;   // Maximum number of elements
    int size;       // Current number of elements

public:
    // Constructor
    PriorityQueue(int size1) {
        capacity = size1;
        size = 0;
        arr = new int[capacity];
    }

    // Destructor
    ~PriorityQueue() {
        delete[] arr;
    }

    // Function to insert an element
    void insert(int element) {
        if (size == capacity) {
            cout << "Priority Queue is full!" << endl;
            return;
        }
        arr[size] = element;
        size++;
        // Rearrange the array to maintain the priority
        for(int i = size - 1; i > 0 && arr[i] > arr[i - 1]; i--) {
            swap(arr[i], arr[i - 1]);
        }
    }

    // Function to remove the element with the highest priority
    int remove() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return INT_MIN; // Return a sentinel value
        }
        return arr[--size];
    }

    // Function to get the highest priority element without removing it
    int peek() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return INT_MIN; // Return a sentinel value
        }
        return arr[size - 1];
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to get the current size of the priority queue
    int getSize() {
        return size;
    }

    void display()
    {
        for (int i = 0; i < size ; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    PriorityQueue pq(10);
    pq.insert(3);
    pq.insert(5);
    pq.insert(1);
    pq.insert(10);
    pq.display();
    cout << "Highest priority element: " << pq.peek() << endl; // Should print 10
    cout << "Removing: " << pq.remove() << endl; // Should remove 10
    cout << "Highest priority element: " << pq.peek() << endl; // Should print 5

    return 0;
}
