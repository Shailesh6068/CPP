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
void insert_at_tail(node* &head, int val) 
{
    node* new_node = new node(val);
    if(head == NULL)
    {
        head = new_node;                        // If the list is empty, make the new node the head
    } 
    else 
    {                                           // Traverse to the end of the list
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }                                       // Insert the new node at the end
        temp->next = new_node;
    } 
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
    insert_at_tail(head,50);
    display(head);
    insert_at_tail(head,55);
    display(head);
    insert_at_tail(head,89);
    display(head);

    return 0;
}