//For Cousin there are condition :
// 1 ) Level Same Pahije
// 2 ) Parent Different Pahije.

#include<iostream>
#include<queue>
#include<stack>
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
bool checkLevel(Node* root, int a,int b)
{
    queue<Node*> q;
    q.push(root);
    int l1 = -1;                  // Level of a
    int l2 = -1;                  // Level of b
    int level = 0;                // Global level

    while (!q.empty())
    {
        int n = q.size();        // It is used to find the new level / Or jar tya level che all element sample tar new level start honar.
        while (n--)
        {
            Node* temp = q.front();
            q.pop();

            if (temp->data == a)
            {
                l1 = level;
            }
            if (temp->data == b)
            {
                l2 = level;
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }            
        }
        level++;
        if (l1 != l2)               // Same Level par nahit.
        {
            return 0;
        }
        if (l1 != -1 && l2 != -1) // Donhi pan sapadale aani level same aahe mhanun pudhe loop chalavyachi garaj nahi
        {
            break;
        }
    }
    return 1;
}
// Yat Aapan Baghanar aahe ki te donhi ekach node la aahet , ka hi method use karatoy.
bool ParentCheck(Node* root , int a , int b)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left && root->right)
    {
        if (root->left->data == a && root->right->data == b)
        {
            return 1;
        }
        if (root->left->data == b && root->right->data == a)
        {
            return 1;
        }
    }
    return ParentCheck(root->left,a,b) || ParentCheck(root->right,a,b);  
    // Donhikadun jar eka jari side n 1 dil mhanaje te present aahe tyamule. or operator vaparato.
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

    cout<<"\nTree traversal :\n";
    levelOrderTraversal(root);
    
    int a,b;
    cout<<"Enter values a and b :";
    cin>>a>>b;
    
    cout<<"\nIt is Cousin :";
    if (checkLevel(root,a,b) == 1 && ParentCheck(root,a,b) != 1)
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
    
    return 0;
}