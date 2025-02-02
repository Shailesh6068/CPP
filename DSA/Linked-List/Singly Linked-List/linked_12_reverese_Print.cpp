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
void reverse_link(node* &head)
{   
    if(head == NULL)
    {
        return;
    }
    reverse_link(head->next);
    cout<<head->val<<"->";
    return;
}
int main()
{
    linkedlist ll;
    ll.insert_at_tail(1);
    ll.insert_at_tail(2);
    ll.insert_at_tail(3);
    ll.insert_at_tail(4);
    ll.display();
    reverse_link(ll.head);
    ll.display();
     return 0;

}