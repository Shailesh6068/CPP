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
};
void reverse(node* &head,node* &tail)
{
    node* curr_ptr = head;
    while(curr_ptr)
    {
        node* next_ptr = curr_ptr->next;
        curr_ptr->next = curr_ptr->prev;
        curr_ptr->prev = next_ptr;
        curr_ptr = next_ptr;
    }
    node* temp = head;
    head = tail;
    tail = head;
}
int main()
{
    doubly_list dl;
    dl.insert_at_start(1);
    dl.insert_at_start(2);
    dl.insert_at_start(3);
    dl.insert_at_start(4);
    dl.display();
    cout<<"The Reverse list is:\n\a";
    reverse(dl.head,dl.tail);
    dl.display();
}