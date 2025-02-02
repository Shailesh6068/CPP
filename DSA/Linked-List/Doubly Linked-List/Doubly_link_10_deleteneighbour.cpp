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
void delete_if_same_neighbour(node* &head,node* &tail)
{
    node* curr_ptr = tail->prev;
    while(curr_ptr != head)
    {
        node* prev_ptr = curr_ptr->prev;
        node* next_ptr = curr_ptr->next;
        if(prev_ptr->val == next_ptr->val)
        {
            node* temp = curr_ptr;
            //curr_ptr->prev->next = curr_ptr->next;
            //curr_ptr->next->prev = curr_ptr->prev; 
            prev_ptr->next = curr_ptr->next;
            next_ptr->prev = curr_ptr->prev;   
            free(temp);
        }
        curr_ptr = prev_ptr;
    }
}
int main()
{
    doubly_list dl;
    dl.insert_at_start(1);
    dl.insert_at_start(3);
    dl.insert_at_start(3);
    dl.insert_at_start(4);
    dl.insert_at_start(3);
    dl.insert_at_start(3);
    dl.insert_at_start(1);
    dl.display();
    delete_if_same_neighbour(dl.head,dl.tail);
    dl.display();
   
}