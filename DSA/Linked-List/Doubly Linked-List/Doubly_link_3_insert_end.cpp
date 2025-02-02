#include<iostream>
using namespace std;
class node
{   
    public:
    int val;
    node* next;
    node* prev;
    node(int data)
    {
        val = data;
        next = NULL;
        prev = NULL;
    }
};
class Doubly_list
{   
    public:
    node* head;
    node* tail;

    Doubly_list()
    {
        head = NULL;
        tail = NULL;
    }

    void display()
    {
        node* temp = head;
        while (temp != NULL )
        {
            cout<<temp->val<<"<->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void insert_at_end(int data)
    {
        node* new_node = new node(data);
        if(tail == NULL)
        {   
            head = new_node;
            tail = new_node;
            return;
        }
        
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }
};
int main()
{
    Doubly_list ll;

    ll.insert_at_end(5);
    ll.insert_at_end(6);
    ll.insert_at_end(7);
    ll.insert_at_end(8);
    ll.display();

}