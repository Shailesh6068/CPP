// PostOrder (LRN) + InOrder (LNR) Tree Construction
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

// Function to construct the binary tree using Postorder and Inorder
Node* Solution(const vector<int>& Post, const vector<int>& In, int Instart, int InEnd, int& index) {
    // Base case
    if (Instart > InEnd) {
        return nullptr;
    }

    // Create the root node with the current postorder element
    int current = Post[index--];
    Node* root = new Node(current);

    // If this node has no children, return it
    if (Instart == InEnd) {
        return root;
    }

    // Find the position of this node in the inorder array
    int pos = findPos(In, current, Instart, InEnd);

    // Recursively construct the right and left subtrees (IMPORTANT: Right first for PostOrder)
    root->right = Solution(Post, In, pos + 1, InEnd, index);
    root->left = Solution(Post, In, Instart, pos - 1, index);

    return root;
}

int main() {
    vector<int> PostOrder = {4, 2, 8, 5, 9, 1, 6, 3, 7, 10};  // Postorder (LRN)
    vector<int> InOrder = {1, 2, 4, 5, 8, 9, 3, 6, 7, 10};    // Inorder (LNR)
    int n = PostOrder.size();

    // Start from the last index of PostOrder
    int PostIndex = n - 1;
    Node* root = Solution(PostOrder, InOrder, 0, n - 1, PostIndex);

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
