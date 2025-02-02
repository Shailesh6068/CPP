#include<iostream>
using namespace std;      //  work on the property of circular queue this use (front+1)%size
class Deque
{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    int cur_size;

    Deque(int cap)
    {   size = cap;
        arr = new int[size];
        front = -1;
        rear = -1;
        cur_size = 0;
    }

    bool isfull()
    {
       return (rear+1)%size == front;
    }

    bool isempty()
    {
       return front == -1;
    }

    void push_front(int data)
    {
        if(isfull())
        {
            cout<<"Queue is full.\n";
            return;
        }
        else if (isempty())
        {
            front = rear =0;
            arr[front] = data;
            return;
        }
        else
        {
            front = (front-1+size)%size;
            arr[front] = data;
        }
    }

    void push_back(int data)
    {
       if(isfull())
       {
        cout<<"Queue is full\n";
        return;
       }
       
       if (isempty())
       {
           front = 0;
          
           return;
       }
      
           rear = (rear+1)%size;
           arr[rear] = data;
    }

    void pop_back()
    {   if (isempty())
        {
            cout<<"Is empty\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear-1)%size;
        }
    }

    void pop_front()
    {
        if (isempty())
        {
            cout<<"Queue is Empty.\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%size;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) 
            {  break;
            }                           // Stop when we've displayed all elements
            i = (i + 1) % size; // Move to next index
        }
        cout << endl; // New line for better output formatting
    }

};
int main()
{
    Deque De(4);
    De.push_front(1);
    De.push_back(2);
    De.push_front(3);
    De.push_back(4);
    De.display();

}