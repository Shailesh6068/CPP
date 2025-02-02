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
    if (head == NULL)
    {
        head = new_node;
        return;
    }  
    new_node->next = head;
    head = new_node;
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
    return 0;
}