#include<iostream>
using namespace std;
class node
{
    public:
    int val;
    node* Next;

    node(int a)
    {
        val = 1;
        Next = NULL;
    }             
};
int main()
{   
    // Method 1 
    // node n(1);
    // cout<<"val :"<<n.val<<"     Next :"<<n.Next;

    // Method 2
    // node n(2);
    // node* ptr = &n;
    // cout<<"val :"<<ptr->val<<"     Next :"<<ptr->Next;

    // Method 3 for linked list 
    node* n = new node(1);
    cout<<"val :"<<n->val<<"     Next :"<<n->Next;

}