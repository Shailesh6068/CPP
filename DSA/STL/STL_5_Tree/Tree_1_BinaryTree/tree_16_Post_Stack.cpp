#include<iostream>
#include<vector>
#include <algorithm>  // For std::reverse
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
vector<int> PostOrder(Node* root)
{
    // In PostOredr We Use :-         LRN
    // For Simplicity we Use:         NRL      -> And reverse it.
    stack<Node*> st;
    vector<int> ans;

    st.push(root);
    while (!st.empty())
    {
        Node* temp = st.top();
        ans.push_back(temp->data);
        st.pop();
       
        // For Right
        if (temp->right)
        {
            st.push(temp->right);
        }
        // For Left
        if (temp->left)
        {
            st.push(temp->left);
        }
    }

    // Reverse it
    reverse(ans.begin(),ans.end());

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

    vector<int> ans = PostOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}