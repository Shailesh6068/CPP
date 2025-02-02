//                   1
//                  /  \
//                 2    3
//                / \    \          Ans :- 1,3,6,10,2,5,9,4,8,7,11
//               4   5    6
//              / \      / \
//             7   8    9   10
//                /
//               11

#include<iostream>
#include<vector>
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
// Steps :
// 1 -> Push first element in the ans vector. 
// 2 -> traverse towards left side and push element in ans vector except leaf node.
// 3 -> traverse in leaf node and push this leaf node data in ans vector.
// 4 -> traverse right side and push element from ending to root node in ans.(bottom to top)
void leftBoundry(Node* root , vector<int> &ans)
{
    if (root == nullptr || (!root->left && !root->right) )
    {
        return;   
    }
    ans.push_back(root->data);
    if (root->left)
    {
        leftBoundry(root->left,ans);
    }
    else
    {
        leftBoundry(root->right,ans);
    }
}
void LeafBoundry(Node* root , vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    
    LeafBoundry(root->left,ans);
    LeafBoundry(root->right,ans);
}
void RightBoundry(Node* root , vector<int> &ans)
{   
    if (root == nullptr || (!root->left && !root->right))
    {
        return;
    }
    if (root->right)
    {
        RightBoundry(root->right,ans);
    }
    else
    {
        RightBoundry(root->left,ans);
    }    
    ans.push_back(root->data);
}
vector<int> BoundryTree(Node* root)
{
    //
    vector<int> ans;
    ans.push_back(root->data);

    // left
    leftBoundry(root->left, ans);
    // leaf
    if (root->left && root->right)
    {
        LeafBoundry(root , ans);
    }
    // right
    RightBoundry(root->right, ans);
    
    return ans;
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
    
    cout<<"Tree Written By You : \n";
    levelOrderTraversal(root);

    cout<<"\nBoundry Traversal of Tree :\n";
    vector<int> ans = BoundryTree(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}