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
vector<int> Spiraltree(Node* root)
{   
    stack<Node*> s1;             // Right to Left
    stack<Node*> s2;             // Left to Right
    vector<int> ans;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                Node* temp = s1.top();
                ans.push_back(temp->data);
                s1.pop();

                if(temp->right)
                {
                    s2.push(temp->right);
                }
                if (temp->left)
                {
                    s2.push(temp->left);
                }
            }
        }

        // Left to Right
        if (!s2.empty())
        {
            while (!s2.empty())
            {
                Node* temp = s2.top();
                ans.push_back(temp->data);
                s2.pop();
                
                if (temp->left)
                {
                    s1.push(temp->left);
                }
                if (temp->right)
                {
                    s1.push(temp->right);
                }
            }
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

    cout<<"\nWithout Spiral traversal :\n";
    levelOrderTraversal(root);

    cout<<"\nAfter Spiral traversal :\n";
    vector<int> ans = Spiraltree(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
       
    return 0;
}