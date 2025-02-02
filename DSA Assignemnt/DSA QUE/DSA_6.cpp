#include<iostream>
using namespace std;

class Stack {
private:
    char arr[100];  // Array to store stack elements
    int top;  // Index for the top of the stack

public:
    Stack() {
        top = -1;  // Initialize stack as empty
    }

    // Push an element onto the stack
    void push(char element) {
        if (top < 99) {  // Ensure there's space in the stack
            arr[++top] = element;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    // Pop an element from the stack
    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack Underflow\n";
            return -1;  // Return -1 if stack is empty
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Function to reverse a string using a stack
string reverseString(string str) {
    Stack stack;

    // Push each character of the string onto the stack
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }

    // Pop characters from the stack and form the reversed string
    int i = 0;
    while (i<str.length() && !stack.isEmpty()) {
        str[i]= stack.pop();
        i++;
    }

    return str;
}

int main() {
    string input;

    // Take string input
    cout << "Enter a string: ";
    cin >> input;

    // Call function to reverse the string
    string reversed = reverseString(input);

    // Output the reversed string
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
