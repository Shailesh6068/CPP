#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {1,2,3,4,5,6};
    list<int> l1 = {6,7,8,9};
    auto itr1 = l1.begin();
    
    // Print the elements of l1
    for (auto it = l1.begin(); it != l1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
