#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v;
    v.push_back({12, 32, 45});
    v.push_back({14, 54});
    v.push_back({34, 56, 78, 90});

    // Print the original 2D vector
    cout << "Original vector:\n";
    for (int i = 0; i < v.size(); i++) {
        for (auto aa = v[i].begin(); aa != v[i].end(); ++aa) { // Using 'aa' instead of 'it'
            cout << *aa << " ";
        }
        cout << endl;
    }

    cout << "\n--- After Insert ---\n";

    // Correctly initialize an iterator for the outer vector
    vector<vector<int>>::iterator outerAa = v.begin(); // Using 'outerAa' instead of 'outerIt'
    // Insert a new vector {45, 75} at position 1 in the outer vector
    v.insert(outerAa + 1, {45, 75});

    // Print the vector after insertion
    for (int i = 0; i < v.size(); i++) {
        for (auto aa = v[i].begin(); aa != v[i].end(); ++aa) { // Using 'aa' instead of 'it'
            cout << *aa << " ";
        }
        cout << endl;
    }

    cout << "\n--- After pop_back ---\n";
    // Remove the last vector from the outer vector
    v.pop_back();

    // Print the vector after pop_back
    for (int i = 0; i < v.size(); i++) {
        for (auto aa = v[i].begin(); aa != v[i].end(); ++aa) { // Using 'aa' instead of 'it'
            cout << *aa << " ";
        }
        cout << endl;
    }

    return 0;
}
