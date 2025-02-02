#include<iostream>
using namespace std;

class ABC {
public:
    // ABC() {
    //     cout << "Constructor Called A." << endl;
    // }

    ~ABC() {
        cout << "Destructor Called A." << endl;
    }
};

int main() {
    ABC A;
    return 0;
}
