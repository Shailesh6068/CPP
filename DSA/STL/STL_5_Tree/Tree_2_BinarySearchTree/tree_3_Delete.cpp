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
        Node* current = new Node(target);
        return current;
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
// 1 -> check the node it is pres
Node* DeleteNode(Node* root , int target)
{  
    // Base Case.
    if (!root)
    {
        return nullptr;
    }

    // Find node.
    if ( target < root->data)
    {
        root->left = DeleteNode(root->left , target);
        return root;
    }
    else if ( target > root->data)
    {
        root->right = DeleteNode(root->right , target);
        return root;
    }
    else                   // If the above is Not Perform Means You are in the target node.
    {
        // Delete Node:
        // Leaf Node
        if (!root->left && !root->right )
        {      
            delete root;
            return nullptr;
        }

        // Single Child.
        else if (!root->right)                // Left child only Exist.
        {
            Node* temp  = root->left;
            delete root;
            return temp;
        }
        else if (!root->left)                 // Right child only Exist.
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Both Child Present.
        else if (root->left && root->right)
        {
            Node* child = root->left;
            Node* parent = root;

            while (child->right)
            {
                parent = child;
                child = child->right;
            }

            // after this we Check 2 condition :
            // 1 -> parent != root
            // 2 -> parent == root
            if (parent != root)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;

            } 
        }          
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

    Node* root = nullptr;
    for (int i = 0; i < v.size(); i++)
    {
        root = InsertNode(root , v[i]);
    }
    
    int target;
    cout<<"Enter the Value for Delete: ";
    cin>>target;
    
    Node* temp =  DeleteNode(root,target);
    
    return 0;

}