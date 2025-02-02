#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int key;
    Node* next;
    
    Node(int k) : key(k), next(nullptr) {}
};

// Hash Table class
class HashTable {
private:
    Node** table; // Array of pointers to linked lists
    int capacity; // Size of the hash table
    
    // Hash function
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor
    HashTable(int size) {
        capacity = size;
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr; // Initialize all buckets as empty
        }
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        
        // Insert at the beginning of the linked list
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        
        while (curr) {
            if (curr->key == key) {
                return true; // Key found
            }
            curr = curr->next;
        }
        return false; // Key not found
    }

    // Delete a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        Node* prev = nullptr;
        
        while (curr) 
        {
            if (curr->key == key) 
            {
                // Key found, remove the node
                if (prev == nullptr) 
                {
                    table[index] = curr->next; // Remove head node
                } else 
                {
                    prev->next = curr->next; // Bypass the node
                }
                delete curr; // Free memory
                cout << "Key " << key << " deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Key " << key << " not found.\n";
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            Node* curr = table[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp; // Free memory
            }
        }
        delete[] table; // Free array
    }
};

// Main function
int main() {
    HashTable ht(7); // Create a hash table with 7 buckets

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    cout << "Hash Table:\n";
    ht.display();

    cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 50: " << (ht.search(50) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "\nHash Table after deleting 15:\n";
    ht.display();

    return 0;
}
