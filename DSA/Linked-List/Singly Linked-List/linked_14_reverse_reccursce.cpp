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
node* reverse_recu(node* &head)      // doubt
{      
    // Base case                
    if(head == NULL || head->next == NULL)
    { 
        cout<<head->val<<endl;
        return head;
    }
    // recursive case
    node* new_head = reverse_recu(head->next);
    // cout<<"head :"<<head->val<<endl;
    // cout<<"New_head :"<<new_head->val<<endl;
    head->next->next = head;
   // cout<<"head->next->next :"<<head->next->next->val<<endl;
    head->next = NULL;
   // cout<<"head->next :"<<head->next->val<<endl;
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
    ll.head = reverse_recu(ll.head);
    ll.display();
    return 0;

}