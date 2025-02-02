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
        left = right = nullptr;
        data = x;
    }
};
int nonleafcount(Node* root)
{
    
    if (root == nullptr)
    {
        return 0;
    }

    if (!root->left && !root->right )
    {
        return 0;
    }   
    return 1+nonleafcount(root->left)+nonleafcount(root->right);
}
Node* binarytree()
{
    int x;
    cin>>x;
    if (x == -1)
    {
        return nullptr;
    }

    Node* temp = new Node(x);
    cout<<"Enter the left value "<<temp->data<<" :";
    temp->left = binarytree();
    cout<<"Enter the right value "<<temp->data<<" :";
    temp->right = binarytree();

    return temp;    
}
int main()
{
    int x;
    cout<<"Enter the root value :";
    Node* root = binarytree();

    cout<<"The Total Non-leafs are the :"<<nonleafcount(root);
    return 0;
}