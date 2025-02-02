// Here We Use Recursive Method :
// Steps :
// We Calculate left side nodes.
// after this calculate right side nodes.
#include<iostream>
#include<queue>
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
        left = right = nullptr;
    }
};
int totalSum(Node* rootnode)
{
    if(rootnode == nullptr)
    {
        return 0;
    }
    return rootnode->data + totalSum(rootnode->left) + totalSum(rootnode->right);
}
int main()
{
    int x;
    cout<<"Enter the root value :\n";
    cin>>x;
    queue<Node*> tree;
    Node* root = new Node(x);
    tree.push(root);

    while(!tree.empty())
    {
        Node* temp = tree.front();
        tree.pop();

        int leftvalue, rightvalue;
        cout<<"Enter the left value "<<temp->data<<" :";
        cin>>leftvalue;
        if (leftvalue != -1)
        {
            temp->left = new Node(leftvalue);
            tree.push(temp->left);        
        }
        
        cout<<"Enter the Right value "<<temp->data<<" :";
        cin>>rightvalue;
        if (rightvalue != -1)
        {
            temp->right = new Node(rightvalue);
            tree.push(temp->right);        
        }
    }

    cout<<"Total Size is :"<<totalSum(root);
    return 0;
    
}