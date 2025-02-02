#include<iostream>                    // Used doubly linked list
using namespace std;
class node
{
    public:
    node* next;
    node* prev;
    int val;

    node(int data)
    {
        next = nullptr;
        prev = nullptr;
        val = data;
    }
};
class Deque
{
    public:
    node* front;
    node* rear;

    Deque()
    {
        front = nullptr;
        rear = nullptr;
    }
    
    void push_front(int data)
    {
        node* new_node = new node(data);
        if (front == nullptr)
        {
            front = new_node;
            rear = new_node;
            return;
        }
        new_node->next = front;
        front->prev = new_node;
        front = new_node;
        return;
    }

    void push_back(int data)
    {
        node* new_node = new node(data);
        if (front == nullptr)
        {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        new_node->prev = rear;
        rear = new_node;
        return;      
    }

    void pop_front()
    {
        if (front == nullptr)
        {
            cout<<"Queue is Empty.\n";
            return;
        }
        node* temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        else
        {
            front->prev = nullptr;
        }
        delete temp;    
    }

    void pop_back()
    {
       if (rear == nullptr)
       {
          cout<<"Queue is empty\n";
       }
       node* temp = rear;
       rear = rear->prev;
       if (rear == nullptr)
       {
          front = nullptr;
       }
       else
       {
          rear->next = nullptr;
       }
       free(temp);
    }

    void display()
    {
        node* curr = front;
        while (curr != nullptr)
        {
            cout<<curr->val<<"  ";
            curr = curr->next;
        }       
        cout<<endl;
    }
};
int main()
{
    Deque De;
    De.push_front(1);
    De.push_back(2);
    De.push_front(3);
    De.push_back(4);
    De.display();
    De.pop_back();
    De.display();
    De.pop_front();
    De.display();
}