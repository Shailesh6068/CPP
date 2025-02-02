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

     
    void delete_at_start()
    {
        //node* temp = head;
        if(head == NULL)
        {
            return;
        }
        node* temp = head;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
        }
        else
        {
        head->prev = NULL;
        }
        delete temp;
    }

    void delete_at_pos(int k)
    {
        if(k==1)
        {
            delete_at_start();
            return;
        }                              //       1 2 3 4 
        int cur_pos = 1;
        node* curr = head;
        while(cur_pos < k)
        {
            curr = curr->next;
            cur_pos++;
        }
        
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr); 
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
    dl.delete_at_pos(2);
    dl.display();
}