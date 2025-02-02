#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;

class Stack {
    int top;
    char arr[MAX]; // Using char array for operators and operands

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top < MAX - 1) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0'; // Return null character if stack is empty
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        }
        return '\0'; // Return null character if stack is empty
    }

    bool isempty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void display(Stack& stack) {
    Stack reverse;
    while (!stack.isempty()) {
        reverse.push(stack.pop());
    }
    while (!reverse.isempty()) {
        cout << reverse.pop();
    }
    cout << endl;
}

void infixToPostfix(string s) {
    Stack operators;
    Stack postfix;

    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == '(') {
            operators.push(s[i]);
        }
        else if (isOperand(s[i])) {
            postfix.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!operators.isempty() && operators.peek() != '(') {
                postfix.push(operators.pop());
            }
            operators.pop(); // Pop the '('
        }
        else if (isOperator(s[i])) {
            while (!operators.isempty() && precedence(s[i]) <= precedence(operators.peek())) {
                postfix.push(operators.pop());
            }
            operators.push(s[i]);
        }
    }

    // Pop remaining operators in the stack
    while (!operators.isempty()) {
        postfix.push(operators.pop());
    }

    cout << "Postfix Expression: ";
    display(postfix);
}

void infixToPrefix(string s) {
    // Step 1: Reverse the infix expression
    reverse(s.begin(), s.end());

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    // Step 3: Convert modified infix to postfix and store in prefix stack
    Stack operators;
    Stack prefix;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            operators.push(s[i]);
        }
        else if (isOperand(s[i])) {
            prefix.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!operators.isempty() && operators.peek() != '(') {
                prefix.push(operators.pop());
            }
            operators.pop(); // Pop the '('
        }
        else if (isOperator(s[i])) {
            while (!operators.isempty() && precedence(s[i]) <= precedence(operators.peek())) {
                prefix.push(operators.pop());
            }
            operators.push(s[i]);
        }
    }

    // Pop remaining operators in the stack
    while (!operators.isempty()) {
        prefix.push(operators.pop());
    }

    // Step 4: Reverse prefix stack for correct order
    cout << "Prefix Expression: ";
    while (!prefix.isempty()) {
        cout<<prefix.peek();
        prefix.pop();
    }   
}

int main() {
    string s;
    cout << "Enter Infix Expression: ";
    cin >> s;

    // Convert to postfix
    infixToPostfix(s);

    // Convert to prefix
    infixToPrefix(s);

    return 0;
}
