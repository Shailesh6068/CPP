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
    
    void insert_at_start(int data)
    {
        node* new_node = new node(data);
        if (head == NULL)
        {
            head = new_node;       
            new_node->next = head;               // make circular linked list..bcaz at first node there next is head
          //  cout<<head->val<<"  "<<head->next<<"   ";
        }
        node* tail = head;
        //cout<<"new head :"<<head->val<<"  "<<endl;
        while(tail->next != head)
        { 
            tail = tail->next;            // 1      -> 2 -> 3 -> 4 -> 5 -> head (next of 5 store head)
        }                                 // (head)                 (tail)
        // cout<<"tail :"<<tail->val<<"  "<<endl;
        // cout<<"head :"<<head->val<<"  "<<endl;
        tail->next = new_node;
        new_node->next = head;
        head = new_node;        // 5->4->3->2->1->5
    }
    void display()
    {
        node* temp = head;
        do
        {
          
            cout<<temp->val<<"->";
            temp = temp->next;
        }while(temp!=head);

        // while (temp->next != head)
        // {
        //     cout<<temp->val<<"  ";
        //     temp = temp->next;
        // }
    }
};
int main()
{
    circular_list cl;
    cl.insert_at_start(5);
    cl.insert_at_start(4);
    cl.insert_at_start(3);
    cl.insert_at_start(2);
    cl.insert_at_start(1);
    cl.display();

    return 0;
}