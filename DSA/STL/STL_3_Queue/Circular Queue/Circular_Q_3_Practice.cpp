#include<iostream>
using namespace std;
class Circular_queu
{
    public:
    int front,rear;
    int val;
    int* arr;
    int size;
    Circular_queu(int n)
    {
        size = n;
        front = rear = -1;
        arr = new int[size];
    }
    
    bool is_empty()
    {
       return rear == front;
    }

    bool is_full()
    {
       return (rear+1)%size == front;
    }

    void enqueue(int data)
    {
        if (is_full())
        {
           cout<<"Queue is Full.\n";
           return;
        }
        if (is_empty())
        {
            front =  0;
        }
        rear = (rear+1)%size;
        arr[rear] = data;     
    }

    void dequeue()
    {
        if (is_empty())
        {
            cout<<"Queue is Empty.\n";
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
            return;
        }
        front = (front+1)%size;       
    }

    void display()
    {
        if (is_empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        int curr = front;
        while(true)
        {
            cout<<arr[curr]<<"  ";
            if (curr == rear)
            {
                break;
            }
            curr = (curr+1)%size;            
        }
        cout<<endl;
    }

};
int main()
{
    Circular_queu cq(3);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(40);
    cq.display();
    cq.enqueue(50);
    cq.enqueue(60); // This will show "Queue is full!"
    cq.display();
    return 0;
}