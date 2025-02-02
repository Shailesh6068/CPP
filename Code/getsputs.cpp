#include <iostream>
#include <cstdio> // For gets() and puts()
#include<string>
#include <cstring>  //for length

using namespace std;

class Student {
    char name[50];
    int age;

public:
    void input() {
        cout << "Enter name: ";
        gets(name); // Input name
        cout << "Enter age: ";
        cin >> age; // Input age
        cin.ignore(); // Ignore the newline character left in the input buffer
    }

    void display() 
        {
        cout << "Name: ";
        puts(name); // Output name
        cout << "Age: " << age << endl; // Output age

        int length = strlen(name); 
        cout<<"lengt :"<<strlen(name);
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
