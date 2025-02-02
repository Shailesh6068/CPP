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
// 1 -> in this we use InOrder Traversal
// 2 -> first we need to make to variable for store prev and ans.
// 3 -> We goto left side.
// 3 -> in prev we update prev root value
// 4 -> and ans we need to update minimum value of (ans,root->data - prev);
// 5 -> we goto right side.
void MinDiffernce(Node* root,int &ans,int &prev)
{
    if (!root)
    {
        return;
    }
    
    MinDiffernce(root->left,ans,prev);    // Goto Left Side.
    if (prev != INT_MIN)                 // We Use this Condition Because the at initially the prev is INT_MIN
    {                                    // When we Subtract then it give the wrong ans which is out of bound.
        ans = min(ans,root->data-prev);       // Find Min Value.
    }
    prev = root->data;                    // Update Prev Value.
    MinDiffernce(root->right,ans,prev);   // Goto Right value.
    
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

    int ans = INT_MAX;
    int prev = INT_MIN;

    MinDiffernce(root,ans,prev);
    cout<<"The Minimum Difference Between Node are :"<<ans;

    return 0;
}