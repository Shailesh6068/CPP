#include<iostream>
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
void levelOrdertree(Node* root)
{
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
        
        cout << "Enter the right child for " << temp->data << " this: ";
        cin >> rightvalue;
        if (rightvalue!= -1) {
            temp->right = new Node(rightvalue);
            q.push(temp->right);
        }
    }
}
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
bool Identical(Node* root1,Node* root2)
{
    if (!root1 && !root2)
    {
        return 1;
    } 
    if ((!root1 && root2) || (root1 && !root2)  )
    {
        return 0;
    } 
    if (root1->data != root2->data)
    {
        return 0;
    }
    return Identical(root1->left,root2->left) && Identical(root1->right , root2->right);     
}
int main()
{
    int first_root , second_root;

    cout<<"Enter the root Value of first tree :";
    cin>>first_root;
    Node* root1 = new Node(first_root);
    levelOrdertree(root1);

    cout<<"Enter the root Value of Second tree :";
    cin>>second_root;
    Node* root2 = new Node(second_root);
    levelOrdertree(root2);

    
    levelOrderTraversal(root1);
    cout<<endl;
    levelOrderTraversal(root2); 
    if (Identical(root1,root2) == 1)
    {
        cout<<"\nThe Tree is Identical.";
    }
    else
    {
        cout<<"\nTree is Not Identical.";
    }
    return 0;
}

                    //         1
                    //     2       3
                    // 4      3