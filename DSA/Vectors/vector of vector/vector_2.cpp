#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50}; // Initialize a vector with values

    // Declare an iterator for the vector
    vector<int>::iterator it;

    // Initialize the iterator to point to the beginning of the vector
    for (it = v.begin(); it != v.end(); ++it) {
       // cout<<"it :"<<it;
        cout << *it << " "; // Dereference it to access the value and print it
    }
    cout << endl;

    // Modify values using the iterator
    for (it = v.begin(); it != v.end(); ++it) {
        *it += 5; // Add 5 to each element
    }

    // Print modified values
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << " "; // Print each modified element
    }
    cout << endl;

    return 0;
}
