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
void printQueue(queue<Node*> q) {
    while (!q.empty()) {
        cout << q.front()->data << " ";  // Node चा डेटा छापा
        q.pop();                         // पहिला घटक काढा
    }
    cout << endl;
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
            cout << "Queue after adding left child: ";
            printQueue(tree);  // Queue छापा
        }

        // Right child
        cout << "Enter the right child of " << temp->data << " (-1 for no child): ";
        cin >> second;
        if (second != -1) {
            temp->right = new Node(second);
            tree.push(temp->right);
            cout << "Queue after adding right child: ";
            printQueue(tree);  // Queue छापा
        }
    }

    return 0;
}
