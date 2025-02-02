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
void del_duplicate(node* &head)
{   
    node* curr = head;
    do          // also write curr != NULL
    {
        while(curr->next != NULL && curr->val == curr->next->val )   // curr->next only write this
        {
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        curr = curr->next;   
    }while(curr != head);
}
int main()
{
    linkedlist ll;
    ll.insert_at_tail(1);
    ll.insert_at_tail(6);
    ll.insert_at_tail(7);
    ll.insert_at_tail(7);
    ll.display();
    del_duplicate(ll.head);
    ll.display();
    return 0;

}