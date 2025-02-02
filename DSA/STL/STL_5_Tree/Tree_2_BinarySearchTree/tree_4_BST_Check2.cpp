// This Using a Without a Vector 
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
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
// 3 -> But in this we Not use extra vector we Check there order in same function using prev.
// our Logic is left = 1 && right = 1 && root < prev
// 4 -> We first make prev which is point prev number initially it was INT_MIN.
// 5 -> check the number is high or not.
// 6 -> if the number is high then update prev
// 7 -> we check left side -> check root -> right side.
// 8 -> 
bool BST(Node* root,int &prev)
{
    if (!root)
    {
        return 1;
    }
     
    // Left side
    if (!BST(root->left , prev))
    {
        return 0;
    }    

    // Root 
    if (root->data <= prev)
    {
        return 0;
    }

    prev = root->data;

    // Right Side
    return BST(root->right, prev);  
    
}
bool isBST(Node* root)
{     
    int prev = INT_MIN;
    return BST(root,prev);
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