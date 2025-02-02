#include <iostream>
using namespace std;

// Class to represent a node in the linked list
class ListNode {
public:
    int value;     // Value of the node
    ListNode* next; // Pointer to the next node

    // Constructor
    ListNode(int x) : value(x), next(nullptr) {}
};

// Class to represent a singly linked list
class LinkedList {
public:
    ListNode* head; // Head pointer to the linked list

    // Constructor for an empty list
    LinkedList() : head(nullptr) {}

    // Function to add a new node at the end of the list
    void append(int value) {
        if (!head) {
            head = new ListNode(value); // If list is empty, create the head node
        } else {
            ListNode* temp = head;
            while (temp->next) {
                temp = temp->next; // Traverse to the end of the list
            }
            temp->next = new ListNode(value); // Add the new node at the end
        }
    }

    // Function to partition the list around the value x
    void partition(int x) {
        // Create two dummy nodes for the start of the smaller and greater lists
        ListNode* smaller_head = new ListNode(0); // Dummy node for smaller list
        ListNode* greater_head = new ListNode(0); // Dummy node for greater or equal list

        // Tail pointers to build the two lists
        ListNode* smaller = smaller_head;
        ListNode* greater = greater_head;

        // Traverse the original list
        ListNode* current = head;
        while (current != nullptr) {
            if (current->value < x) 
            {
                // Add to the smaller list
                smaller->next = current;
                smaller = smaller->next;
            } 
            else
            {
                // Add to the greater list
                greater->next = current;
                greater = greater->next;
            }
            current = current->next; // Move to the next node
        }

        // End the greater list
        greater->next = nullptr;

        // Connect the smaller list to the greater list
        smaller->next = greater_head->next;

        // Update the head to the start of the smaller list
        head = smaller_head->next;

        // Clean up the dummy nodes
        delete smaller_head;
        delete greater_head;
    }

    // Function to print the linked list
    void printList() const {
        ListNode* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a linked list
    LinkedList list;
    list.append(3);
    list.append(5);
    list.append(8);
    list.append(5);
    list.append(10);
    list.append(2);
    list.append(1);

    cout << "Original list: ";
    list.printList();

    // Partition the list around the value 5
    list.partition(5);

    cout << "Partitioned list: ";
    list.printList();

    return 0;
}