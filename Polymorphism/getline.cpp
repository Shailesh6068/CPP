#include <iostream>
#include <string> // For std::string
#include <cstring> // For strlen()

using namespace std;

class Student {
    string name;
    int age;

public:
    void input() {
        cout << "Enter name: ";
        getline(cin, name); // Input name using getline
        cout << "Enter age: ";
        cin >> age; // Input age
        cin.ignore(); // Ignore the newline character left in the input buffer
    }

    void display() {
        cout << "Name: " << name << endl; // Output name
        cout << "Age: " << age << endl; // Output age

        int length = name.length(); // Calculate length of name
        cout << "Length of name: " << length << endl;
    }
};

int main() {
    Student s;

    cout << "Enter student details: " << endl;
    s.input(); // Input student details

    cout << "Student details: " << endl;
    s.display(); // Output student details

    return 0;
}
