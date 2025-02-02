#include<iostream>
using namespace std;
class node
{
    public:
    int val;
    node* next;
    node(int data)
    {
        val = data;
        next = NULL; 
    }
};
class linkedlist
{
    public:
    node* head;
    linkedlist()
    {
        head = NULL;
    }
    void insert_at_tail(int val)
    {
        node* new_node = new node(val); 
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        
        node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        
    } 

    void display()
    {
        node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
node* reverse(node* &head)
{                       // NULL 1 2 3 4 5 6
    node* prev_ptr = NULL;         //1->NULL          = 2 :next_ptr
    node* curr_ptr = head;
    node* next_ptr;
    while(curr_ptr != NULL)
    {   
        next_ptr = curr_ptr->next;
        curr_ptr->next = prev_ptr;
        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
    }
    node* new_head = prev_ptr;
    return new_head; 
}
int main()
{
    linkedlist ll;
    ll.insert_at_tail(1);
    ll.insert_at_tail(2);
    ll.insert_at_tail(3);
    ll.insert_at_tail(4);
    ll.display();
    ll.head = reverse(ll.head);
    ll.display();
    return 0;

}