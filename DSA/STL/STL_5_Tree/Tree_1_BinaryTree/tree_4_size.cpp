// Here we use NLR Logic 
// First Visit the Node and increase count and go to left side.
// aftrer left is over we go towards right side.
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
void totalsize(Node* rootnode , int &count )
{
    if (rootnode == nullptr)
    {
        return;
    }
    count++;
    totalsize(rootnode->left,count);
    totalsize(rootnode->right,count);

}
int main()
{
    int x;
    cout<<"Enter the root value :\n";
    cin>>x;
    queue<Node*> tree;
    Node* root = new Node(x);
    tree.push(root);

    while(!tree.empty())
    {
        Node* temp = tree.front();
        tree.pop();

        int leftvalue, rightvalue;
        cout<<"Enter the left value "<<temp->data<<" :";
        cin>>leftvalue;
        if (leftvalue != -1)
        {
            temp->left = new Node(leftvalue);
            tree.push(temp->left);        
        }
        
        cout<<"Enter the Right value "<<temp->data<<" :";
        cin>>rightvalue;
        if (rightvalue != -1)
        {
            temp->right = new Node(rightvalue);
            tree.push(temp->right);        
        }
    }

    int count = 0;
    totalsize(root,count);
    cout<<"The Number of nodes is :"<<count;
    return 0;
}

// there are two methods to passing value :
// 1 ) pass by value : here only value pass directly. the change is value are not seen in the value in other function:
// 2 ) Pass by refference : Use when we need to chang ethe value.here the changes are occured in original value,
//      
//    int a = 10;
//    cout << &a;  // 'a' चा मेमरी अ‍ॅड्रेस दाखवतो