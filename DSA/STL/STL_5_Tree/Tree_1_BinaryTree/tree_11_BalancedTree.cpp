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
void levelOrderTraversal(Node* root) {              // Yat aapan queue Direct print karat nahi karan maza queue Empty aahe .
    if (root == nullptr) return;                   //  pan Je Node Aahet tyat address aahest.
    queue<Node*> display;
    display.push(root);
    while (!display.empty()) {
        Node* temp = display.front();
        display.pop();
        cout << temp->data << " ";
        if (temp->left) 
        {
            display.push(temp->left);
        }
        if (temp->right) 
        {
            display.push(temp->right);
        }
    }
}
// Methd : 1
// int HeightTree(Node* root,bool &valid)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }

//     int l = HeightTree(root->left,valid);
//     int r = HeightTree(root->right,valid);
//     if (abs(l-r) > 1)
//     {
//         valid = 0;
//     }
//     return 1+max(l,r);      
// }
// 
// Method : 2
int HeightTree(Node* root,bool &valid)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    if (valid)
    {   
        int l = HeightTree(root->left,valid);
        int r = HeightTree(root->right,valid);
        if (abs(l-r) > 1)
        {
            valid = 0;
        }
        return 1+max(l,r); 
    }
    return -1;  
}
bool isBalanced(Node *root)
{
    bool valid = 1;
    HeightTree(root ,valid);
    return valid;
}
int main()
{
    int rootvalue;
    cout<<"Enter the root Value :\n";
    cin>>rootvalue;
    
    Node* root = new Node(rootvalue);

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftvalue,rightvalue;
        cout<<"Enter the left Child For "<<temp->data<<" this :";
        cin>>leftvalue;
        if (leftvalue != -1)
        {
            temp->left = new Node(leftvalue);
            q.push(temp->left);
        }
        
        cout << "Enter the right child of " << temp->data << " (-1 for no child): ";
        cin >> rightvalue;
        if (rightvalue!= -1) {
            temp->right = new Node(rightvalue);
            q.push(temp->right);
        }
    }

    levelOrderTraversal(root);
    if (isBalanced(root) == 1)
    {
        cout<<"\nIt is Balanced.\n";
    }
    else
    {
        cout<<"\nIt is Not-Balanced.\n";
    }

    return 0;
}