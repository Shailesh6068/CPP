#include<iostream>
using namespace std;
class Queue
{
    int front,back;

    public:

    int arr[10];

    Queue()
    {
        front = back = -1;
    }

    void enqueue(int data)
    {
        if (front == -1)
        {
            front++;
            back++;
            arr[front] = data;
            return;
        }
        back++;
        arr[back] = data; 
        // back++;
        // arr[back] = data;
        // if(back == 0)
        // {
        //     front = 0;
        // }
    }
    
    void dequeue()
    {
        if(front == back)
        {
            front = back = -1;
        }
        else
        {
            front++;
        }
    }

    bool is_empty()
    {
        return front == -1;
    }

    int get_front()
    {
        if(front == -1)
        {
            return -1;
        }
        return arr[front];
    }
    
    void display()
    {
        int temp_front = front;        // because when we use only front it will increment 
        while(temp_front <= back)     // and dor another display it go to end of array
        {
            cout<<arr[temp_front]<<"  ";
            temp_front++;
        }  
        cout << endl;
    }
};
int main()
{
    Queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.display();
    Q.dequeue();
    Q.display();

    return 0;

}