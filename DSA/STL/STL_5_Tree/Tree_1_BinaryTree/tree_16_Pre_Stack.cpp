#include<iostream>
#include<vector>
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
        Node* left = right = nullptr;
    }
};
vector<int> preorder(Node* root)
{
    stack<Node*> st;
    vector<int> ans;
    st.push(root);
    while (!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }   
    }
    return ans;
}
Node* BinaryTree()
{   
    int x;
    cin>>x;

    if(x==-1)
    {
        return NULL;
    }

    Node* temp = new Node(x);
    cout<<"Enter the left Child of "<<x<<" :";
    temp->left = BinaryTree();
    cout<<"Enter the right Child of "<<x<<" :";
    temp->right = BinaryTree();

    return temp;
}
int main()
{
    cout<<"Enter the root element: ";
    Node* root = BinaryTree();

    vector<int> ans = preorder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}