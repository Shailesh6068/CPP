// Pre_Order + In-Order
#include <iostream>
#include <vector>
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
// Function to find the position of a target in the InOrder array
int findPos(const vector<int>& InOrder, int target, int Instart, int InEnd) {
    for (int i = Instart; i <= InEnd; i++) {
        if (InOrder[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to construct the binary tree
Node* Solution(const vector<int>& pre, const vector<int>& In, int Instart, int InEnd, int& index) {
    // Base case
    if (Instart > InEnd) {
        return nullptr;
    }

    // Create the root node with the current preorder element
    int current = pre[index++];
    Node* root = new Node(current);

    // If this node has no children, return it
    if (Instart == InEnd) {
        return root;
    }

    // Find the position of this node in the inorder array
    int pos = findPos(In, current, Instart, InEnd);

    // Recursively construct the left and right subtrees
    root->left = Solution(pre, In, Instart, pos - 1, index);
    root->right = Solution(pre, In, pos + 1, InEnd, index);

    return root;
}

int main() {
    vector<int> PreOrder = {4, 2, 8, 5, 9, 1, 6, 3, 7, 10};
    vector<int> InOrder = {1, 2, 4, 5, 8, 9, 3, 6, 7, 10};
    int n = PreOrder.size();

    int preIndex = 0;
    Node* root = Solution(PreOrder, InOrder, 0, n - 1, preIndex);

    // Level order traversal to print the tree
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }

    return 0;
}
