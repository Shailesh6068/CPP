#include <iostream>
using namespace std;
class Person 
{
    public:
    
    string name;
    int age;

    // Constructor
    Person(string n, int a)
    {
        name  = n;
        age = a;
    }
    // Member function
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
 
    Person p("Alice", 30);                       // Creating an object of the class
    Person* ptr = &p;                           // Creating a pointer to the object

    // Accessing data members using the arrow operator
    cout << "Name using pointer: " << ptr->name << endl;
    cout << "Age using pointer: " << ptr->age << endl;

    // Calling a member function using the arrow operator
    ptr->display();
 
    return 0;
}
