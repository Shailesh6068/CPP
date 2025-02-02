#include <iostream>
#include <vector>
using namespace std;
class HashTable {
private:
    static const int TABLE_SIZE = 10; // Size of the hash table
    int keys[TABLE_SIZE];             // Array to store keys
    bool flag[TABLE_SIZE];        // Array to track flag slots
    // Hash function to calculate the index
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Constructor to initialize the hash table
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            flag[i] = false; // Mark all slots as empty
            keys[i] = -1;        // Use -1 as a placeholder for empty slots
        }
    }

    // Insert a key
    void insert(int key) 
    {
        int index = hashFunction(key);
        int originalIndex = index;

        while (flag[index]) 
        {
            // If key already exists, return
            if (keys[index] == key) {
                cout << "Key " << key << " already exists in the hash table." << endl;
                return;
            }

            // Linear probing to find the next free slot
            index = (index + 1) % TABLE_SIZE;

            // If we come back to the original index, the table is full
            if (index == originalIndex) {
                cout << "Hash table is full, cannot insert key: " << key << endl;
                return;
            }
        }

        // Insert the new key
        keys[index] = key;
        flag[index] = true;
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (flag[index]) {
            if (keys[index] == key) {
                return true; // Key found
            }

            // Linear probing
            index = (index + 1) % TABLE_SIZE;

            // If we come back to the original index, the key is not found
            if (index == originalIndex) {
                break;
            }
        }

        return false; // Key does not exist in the table
    }

    // Display the hash table
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (flag[i]) {
                cout << i << ": " << keys[i] << endl;
            } else {
                cout << i << ": [Empty]" << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Insert keys into the hash table
    hashTable.insert(10);
    hashTable.insert(30);
    hashTable.insert(20);
    hashTable.insert(15);
    hashTable.insert(25);

    // Search for keys
    cout << "Search for 10: " << (hashTable.search(10) ? "Found" : "Not Found") << endl;
    cout << "Search for 30: " << (hashTable.search(30) ? "Found" : "Not Found") << endl;

    // Display the hash table
    hashTable.display();

    return 0;
}
