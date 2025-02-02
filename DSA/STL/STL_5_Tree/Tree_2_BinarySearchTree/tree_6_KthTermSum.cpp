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
// Kth term sum BST 
// Steps :
// 1 -> We use InOrder Traversal
// 2 -> We need to sum first k smallest element
// 3 -> go to left side
// 4 -> when we return from left side add the value of node in this.
// 5 -> if the k is greater than 0 then sum
// 6 -> if k is less than 0 then return
// 7 -> Goto Left side.
void SumofKterm(Node* root,int &sum,int &k)
{
    if (!root)
    {
        return;
    }
    SumofKterm(root->left,sum,k);           // Go towards Left Side
    k--;
    if (k >= 0)                           // We take greater than 0 not 1 bcz the initially the decrease k
    {
        sum = sum + root->data;
    }
    if (k <= 0)
    {
        return;
    }
    SumofKterm(root->right,sum,k);    
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

    int k;
    int sum = 0;
    cout<<"How Many term sum required :";
    cin>>k;
    int n = k;
    SumofKterm(root,sum,k);
    cout<<"The Sum of first "<<n<<" terms are :"<<sum;

    return 0;
}