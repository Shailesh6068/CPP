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
    cout<<"❌  **No payments are currently in the queue.**\n"<< endl;
    node *head = NULL;
    insertAthead(head,6);
    display(head);
    insertAthead(head,10);
    display(head);
    insert_at_tail(head,50);
    display(head);
    delete_at_head(head);
    display(head);
    return 0;
}