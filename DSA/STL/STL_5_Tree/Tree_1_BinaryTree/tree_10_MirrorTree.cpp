#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int x) {
        left = right = nullptr;
        data = x;
    }
};
void printtree(Node* root) 
{
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
void Mirrortree(Node* root)
{
    if (!root)
    {
        return;
    }

    Node* temp = root->right;
    root->right = root->left;
    root->left = temp;
    
    Mirrortree(root->left);
    Mirrortree(root->right);
}
int main() {
    int x;
    cout << "Enter the root Element: ";
    cin >> x;

    int first, second;
    queue<Node*> tree;
    Node* root = new Node(x);
    tree.push(root);

    while (!tree.empty()) {
        Node* temp = tree.front();
        tree.pop();

        // Left child
        cout << "Enter the left child of " << temp->data << " (-1 for no child): ";
        cin >> first;
        if (first != -1) {
            temp->left = new Node(first);
            tree.push(temp->left);
        }

        // Right child
        cout << "Enter the right child of " << temp->data << " (-1 for no child): ";
        cin >> second;
        if (second != -1) {
            temp->right = new Node(second);
            tree.push(temp->right);
        }
    }
    cout<<"\nPrint Before Mirror :\n";
    printtree(root); 

    Mirrortree(root);

    cout<<"\nPrint Aftere Mirror :\n";
    printtree(root); 

    return 0;
}
    //         1
    //     2       3
    // 4       5  