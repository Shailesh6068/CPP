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
void insert_at_tail(node* &head,int val)
{
    node* new_node = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
void delete_at_head(node* &head)
{
    node* temp = head;
    head = head->next;
    free(temp);           // to free the memory of first element.
}
void delete_at_pos(node* &head , int pos)
{
    if (pos == 0)
    {
        delete_at_head(head);
        return;
    }
   int curr_pos = 0;
   node* prev = head;
   while(curr_pos != pos-1)
   {
        prev = prev->next;
        curr_pos++;
   }
   node* temp = prev->next;
   prev->next = prev->next->next;
   free(temp);
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
    insert_at_tail(head,50);
    display(head);
    delete_at_pos(head,1);
    display(head);
    return 0;
}