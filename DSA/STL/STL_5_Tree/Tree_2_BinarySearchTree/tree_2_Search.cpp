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
// Steps :
// 1 -> here is the answer is in the yes and no format for it is make as boolean type.
// 2 -> first we check the root if it null it return 0.
// 3 -> after this we check the root data if it same as the search value then return 1
// 4 -> if the searcing value is less than root data go to left side
// 5 -> if the searching value is greater than the root data go to right side.
// In this Always Node add to leaf node.
bool SearchNode(Node* root , int search)
{
    if (!root)
    {
        return 0;
    }

    if (root->data == search)
    {
        return 1;
    }

    if (search < root->data )
    {
        return SearchNode(root->left , search);
    }
    else
    {
        return SearchNode(root ->right , search);
    }
}
int main()
{
    vector<int> v(7);
    
    cout<<"Enter The Element : \n";
    for (int i = 0; i < v.size(); i++)
    {
        cin>>v[i];
    }
      
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    Node* root = nullptr;
    for (int i = 0; i < v.size(); i++)
    {
        root = InsertNode(root , v[i]);
    }
    
    int search;
    cout<<"Enter the Value to search : ";
    cin>>search;
    if (SearchNode(root,search))
    {
        cout<<search<<" is the Present.\n";
    }
    else
    {
        cout<<search<<" is Not Present.\n";
    }

    return 0;

}