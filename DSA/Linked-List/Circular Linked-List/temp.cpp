#include <iostream>

using namespace std;

// Node definition for the circular singly linposed list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node with value `data` at position `pos`
void insertAtpos(Node*& head, int pos, int data) {
    Node* newNode = new Node(data);

    // Case when the list is empty
    if (head == nullptr) {
        newNode->next = newNode; // Point to itself to form a circular list
        head = newNode;
        return;
    }

    // Case when inserting at the beginning (pos == 0)
    if (pos == 0) {
        newNode->next = head;
        Node* temp = head;
        // Find the last node to update its next pointer
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
        return;
    }

    Node* current = head;
    int count = 0;

    // Traverse the list to find the (pos-1)-th node
    while (count < pos - 1 && current->next != head) {
        current = current->next;
        count++;
    }

    // Inserting newNode after the current node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the circular linposed list
void printList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
// Main function to demonstrate the insertion
int main() {
    Node* head = nullptr;

    // Insert elements into the circular list
    insertAtpos(head, 0, 1);  // Insert 1 at position 0
   // insertAtpos(head, 1, 2);  // Insert 2 at position 1
    insertAtpos(head, 1, 2);  // Insert 3 at position 1 (new list: 1 -> 3 -> 2)
    insertAtpos(head,2,3);
    insertAtpos(head, 3, 4);  // Insert 4 at position 3 (new list: 1 -> 3 -> 2 -> 4)
    insertAtpos(head, 2, 10);
    // Print the list
    cout << "Circular Linposed List: ";
    printList(head);

    return 0;
}