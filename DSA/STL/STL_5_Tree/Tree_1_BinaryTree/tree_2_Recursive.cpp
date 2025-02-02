// Recursive Binary Tree Construction
// Binary Tree Input Builder
// Dynamic Binary Tree Creation
#include<iostream>
using namespace std;
class Node
{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int x)
    {
        data = x;
    }
};
Node* BinaryTree()
{   
    int x;
    cin>>x;

    if(x==-1)
    {
        return NULL;
    }

    Node* temp = new Node(x);
    cout<<"Enter the left Child of "<<x<<" :";
    temp->left = BinaryTree();
    cout<<"Enter the right Child of "<<x<<" :";
    temp->right = BinaryTree();

    return temp;
}
int main()
{
    cout<<"Enter the root element: ";
    Node* root = BinaryTree();
    return 0;
}