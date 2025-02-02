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

    void insert_at_begin(int data)
    {
        node* new_node = new node(data);
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
            //return;
        }
        else
        {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        }
    }

};
int main()
{
    Doubly_list ll;
    ll.insert_at_begin(1);
    ll.insert_at_begin(2);
    ll.insert_at_begin(3);
    ll.insert_at_begin(4);
    ll.display();
}