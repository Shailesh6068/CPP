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
// 1 -> We use l and r but in code we use only l,to find size of answer Vector.
// 2 -> we use find function to fine l,we increase the l while going to left but while going right not increase.
// 3 -> make ans vector of vector of size l,in this we push the element using recursion.
// 4 -> after that push all element in single vector.
void find(Node* root , int pos , int &l)
{
    if (root == nullptr)
    {
        return;
    }

    l = max(l,pos);
    find(root->left,pos+1,l);
    find(root->right,pos,l);    
}
void findDiagonal(Node* root , vector<vector<int>> &ans , int pos)
{
    if (root == nullptr)
    {
        return;
    }
    ans[pos].push_back(root->data);
    findDiagonal(root->left , ans , pos+1);
    findDiagonal(root->right , ans , pos);    
}
vector<int> DiagonalTraversal(Node* root)
{
    int l = 0;
    find(root , 0 , l);
    vector<vector<int>> ans(l+1);
    findDiagonal(root , ans , 0);

    vector<int> temp;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            temp.push_back(ans[i][j]);
        }
    }
    return temp;
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

    cout<<"\nDiagonal Traversal of Tree :\n";
    vector<int> ans = DiagonalTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}