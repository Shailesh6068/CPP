//give the head delete the alternate element
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
class Linkedlist
{
    int a;
    public:

    node* head;
    Linkedlist()
    {   //a = 6;
        head = NULL;
    }
    void insert_at_end(int val)
    {  
        node* new_node = new node(val);
        if( head == NULL)
        {
            head = new_node;
            return;
        }

        node* temp = head;
        while(temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display()
    {
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};
void del_same(node* head)
{
    node* curr = head;
    while (curr->next != NULL )
    {
        if(curr->val == curr->next->val)
        {
            node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            //cout<<curr->val<<" ";
        }
      else
      { //cout<<"a"<<" ";
        curr = curr->next;
      }
    }
}
int main()
{
    Linkedlist ll;
    ll.insert_at_end(1);
    ll.insert_at_end(2);
    ll.insert_at_end(2);
    ll.insert_at_end(4);
    ll.insert_at_end(4);
    ll.insert_at_end(4);
    ll.insert_at_end(5);
    ll.insert_at_end(5);
    ll.insert_at_end(5);
    ll.insert_at_end(5);
    ll.display();
    del_same(ll.head);
    ll.display();      
}