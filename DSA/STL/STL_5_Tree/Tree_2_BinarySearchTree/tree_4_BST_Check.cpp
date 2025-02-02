#include<iostream>
#include<vector>
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
Node* InsertNode(Node* root,int target)
{
    if (!root)
    {
        Node* temp = new Node(target);
        return temp;
    }  
    if (root->data < target)
    {
        root->right = InsertNode(root->right , target);
    }
    else
    {
        root->left = InsertNode(root->left , target);
    }
    return root;          // Beacase in this we Compare With Starting/ root node where the tree is created.
}
// Check BST 
// Steps :
// 1 -> In-Order traversal ( LNR ).
// 2 -> check it is ascending or not.
// 3 -> if it is ascending then it is BST.
void inOrder(Node* root,vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    
    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}
bool isBST(Node* root)
{   
    vector<int> ans;

    inOrder(root,ans);

    for (int i = 1; i < ans.size() ; i++)
    {
        if (ans[i] <= ans[i-1])
        {
            return false;
        }        
    }
    
    return true;
}
int main()
{
    vector<int> v(7);
    
    cout<<"Enter The Element : \n";
    for (int i = 0; i < v.size(); i++)
    {
        cin>>v[i];
    }
      
    Node* root = nullptr;
    for (int i = 0; i < v.size(); i++)
    {
        root = InsertNode(root , v[i]);
    }
    
    if (isBST(root))
    {
        cout<<"It is Binary Search Tree.\n";
    }
    else
    {
        cout<<"It is not Binary Search Tree.\n";
    }
    return 0;
}