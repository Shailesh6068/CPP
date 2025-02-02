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
void leafcount(Node* root, int &count)
{

    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        count++;
        return;
    }
    
    leafcount(root->left,count);
    leafcount(root->right,count);
    
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
   // cout<<root->data;
    int count = 0;
    leafcount(root,count);

    cout<<"The Total leafs are the :"<<count<<" :";
    return 0;
}