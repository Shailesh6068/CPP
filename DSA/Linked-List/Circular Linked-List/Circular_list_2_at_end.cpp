#include<iostream>
using namespace std;
class node
{   public:
    int val;
    node* next;

    node(int data)
    {
        val = data;
        next = NULL; 
    }
};
class circular_list
{
    public:
    node* head;

    circular_list()
    {
        head = NULL;
    }
    
    void insert_at_end(int data)
    {
        node* new_node = new node(data);
        
        if(head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }
        
        node* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        
        tail->next = new_node;
        new_node->next = head;        
    }
    void display()
    {
        node* temp = head;
        do
        {
          
            cout<<temp->val<<"->";
            temp = temp->next;
        }while(temp!=head);
    }
};
int main()
{
    circular_list cl;
    cl.insert_at_end(1);
    cl.insert_at_end(2);
    cl.insert_at_end(3);
    cl.insert_at_end(4);
    cl.insert_at_end(5);
    cl.display();

    return 0;
}