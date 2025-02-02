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
void preorder(Node* root)
{
    // Base Case
    if (root == NULL )
    {
        return;
    }
    // NLR :- Node Print
    cout<<root->data<<" ";
    // Left Node
    preorder(root->left);
    // Right Node
    preorder(root->right);
}
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    // LNR
    // left Node
    inorder(root->left);
    // Node Print
    cout<<root->data<<" ";
    // right Node
    inorder(root->right);
}
void postorder(Node* root)
{   
    if (root == NULL)
    {
        return;
    }

    // LRN
    // Left Node
    postorder(root->left);
    // Right Node
    postorder(root->right);
    // Print data
    cout<<root->data<<" ";
}
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

    cout<<"Pre-Order :";
    preorder(root);

    cout<<"\nInorder :";
    inorder(root);

    cout<<"\nPost-Order :";
    postorder(root);


    return 0;
}