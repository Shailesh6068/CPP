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
// make vector -> right(positive pos) and left(negative pos) ;
// for this size is required left and right.(left most element index and right most element index)
// this size required for positive vecor and negative vector.
// for finding the left and right size we use find function there we use l & r.
// check the pos / index of this node if positive push in positive vectoer and if negative push in nagative vector
// merge this two vector : first traverse from bottom of negative vector to top and for positive 
//                         go from top to Bottom.
// we required element from left side to right side.
// Find Funcion : Used For the to find leftMost and RightMost Element index for vector Size.
void find(Node* root ,int &l , int &r ,int pos)
{
    if (root == nullptr)
    {
        return;
    }
    l = min(l,pos);
    r = max(r , pos);
    find(root->left,l,r,pos-1);
    find(root->right , l , r , pos+1);
}
vector<int> verticalTraversal(Node* root)
{
    int l = 0;
    int r = 0;
    find(root , l , r ,0);

    vector<vector<int>> negative(abs(l)+1);
    vector<vector<int>> positive(r+1);
    
    queue<Node*> q;
    queue<int> index;

    q.push(root);
    index.push(0);

    while (!q.empty())
    {   
        Node* temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if (pos >= 0)
        {
            positive[pos].push_back(temp->data);
        }
        if (pos < 0)
        {
            negative[abs(pos)].push_back(temp->data);
        }
        
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos-1);    
        }
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos+1);
        }
    }

    vector<int> ans;

    // for Negative
    for (int i = negative.size()-1; i >= 0; i--)
    {
        for (int j = 0; j < negative[i].size(); j++)
        {
            ans.push_back(negative[i][j]);
        }
    }

    // for Positive
    for (int i = 0; i < positive.size(); i++)
    {
        for (int j = 0; j < positive[i].size(); j++)
        {
            ans.push_back(positive[i][j]);
        }
        
    }
    
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

    cout<<"\nVertical Traversal of Tree :\n";
    vector<int> ans = verticalTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}