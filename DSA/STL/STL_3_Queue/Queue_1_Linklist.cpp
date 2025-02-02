#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }

    // void read()
    // {
    //     cout<<"Enter data :";
    //     cin>>data;
    // }
};
class Queue
{
    public:
    node* front;
    node* tail;
    int size;

    Queue()
    {
        front = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(int data)
    {
        node* new_node =  new node(data);
        if (front == NULL)
        {
            front = tail = new_node;  
        }          
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void dequeue()
    {
        if(front == NULL)
        {
            return;
        }
        else
        {
            node* temp = front;
            front =front->next;
            if(front == NULL)
            {
                tail = NULL;
            }
            free(temp);
        }
    }

    void display()
    {
        node* curr =front;
        while(curr != NULL)
        {
            cout<<curr->data<<"  ";
            curr = curr->next;
        }
    }

    int getsize()
    {
        return size;
    }

    bool is_empty()
    {
        return front == NULL;
    }

    int Front()
    {
        return front->data;
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
    cout<<endl;
    //Q.display();

    while(!Q.is_empty())
    {
        cout<<Q.Front()<<"  ";
        Q.dequeue();
    }
    Q.is_empty();
    Q.Front();
    Q.getsize();

}