#include<iostream>
using namespace std;
class node                                  // Format of linked list
{
    public:
    int val;
    node *next;
    node(int a)
    {
       val = a;
       next = NULL;
    }   
};
void insertAthead(node* &head,int val)   // head pass by reference bcz old head la new head la update karayacha aahe
{
    node* new_node = new node(val);
    new_node->next = head;
    head = new_node;
}
void insert_at_position(node* &head,int val,int pos)
{   
    if(pos == 0)
    {
        insertAthead(head,val);
        return;
    }

    node* new_node = new node(val);
    int current_pos = 0;
    node* temp = head;

    while( current_pos != pos-1 )
    {
        temp = temp->next;
        current_pos++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    
}
void display(node* head )
{
    node* temp = head;
    while (temp != NULL )
    {
        cout<<temp->val<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL \n";

}
int main()
{
    node *head = NULL;
    insertAthead(head,6);
    display(head);
    insertAthead(head,10);
    display(head);
    insert_at_position(head,45,1);
    display(head);
    return 0;
}