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
int leafcount(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (!root->left && !root->right)
    {
        return 1;
    }

    return leafcount(root->left)+leafcount(root->right);    
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
    cout<<"Total Numbers Of leafs :"<<leafcount(root);
}

            //                 1  
            //             2
            //         3
            //     4
            // 5 