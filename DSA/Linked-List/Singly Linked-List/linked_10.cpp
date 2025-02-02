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
   void del_alternate();   //    METHOD 1    for method 2 we pass head therefore note necessary  write inside.

};
//          METHOD  1
//
void Linkedlist::del_alternate()
{
   // cout<<a;
    node* curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        curr = curr->next;
    }
}
//      METHOD 2
//
// void del_alternate(node* head)
// {
//     node* curr = head;
//     while (curr != NULL && curr->next != NULL)
//     {
//         node *temp = curr->next;
//         curr->next = curr->next->next;
//         free(temp);
//         curr = curr->next;
//     }
// }
int main()
{
    Linkedlist ll;
    ll.insert_at_end(1);
    ll.insert_at_end(2);
    ll.insert_at_end(3);
    ll.insert_at_end(4);
    ll.insert_at_end(5);
    ll.display();
    ll.del_alternate();             //     METHOD  1
    //del_alternate(ll.head)        //     METHOD  2
    ll.display();
}