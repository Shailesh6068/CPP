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
        next = NULL;
        prev = NULL;
        val = data;
    }
};
class doubly_list
{
    public:
    node* head;
    node* tail;
    doubly_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_start(int data)
    {
        node* new_node = new node(data);
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
           // new_node->prev = NULL;
            head = new_node;
        }
    }

    void display()
    {
        node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->val<<"<->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void delete_at_end()
    {
        if(tail == NULL)
        {
            return;
        }
        node* temp = tail;
        tail = tail->prev;
        if(tail == NULL)                  // if there only one element.
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(temp);
    }
};
int main()
{
    doubly_list dl;
    dl.insert_at_start(1);
    dl.insert_at_start(2);
    dl.insert_at_start(3);
    dl.insert_at_start(4);
    dl.display();
    dl.delete_at_end();
    dl.display();
}