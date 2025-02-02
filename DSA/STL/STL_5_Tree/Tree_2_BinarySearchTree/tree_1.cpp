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
// Steps :
// 1 -> Create array or Vector.
// 2 -> Declare Root Node as a NULL.
// 3 -> Create function to InsertNode where returntype is Node*.
// 4 -> pass the root and vector values in this.
// 5 -> in this function if root is null then make a Node and return this node.
// 6 -> if the target value is less than the root data then push at the left of the node. else right
// 7 -> return root.
// In this Always Node add to leaf node.
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
    

    


}