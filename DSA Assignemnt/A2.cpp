#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top < MAX - 1) {
            arr[++top] = x;
        }
    }

    char pop(){
        if(top >= 0) {
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
int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
bool isdigit(char ch){
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
}
bool isoperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
void display(Stack& ans) {
    Stack reverse;
    // Reverse stack content to display in correct order
    while(!ans.isempty()) {
        reverse.push(ans.pop());
    }
    while(!reverse.isempty()) {
        cout << reverse.pop();
    }
    cout << endl;
}
void infixtopostfix(string s) {
    Stack operators;
    Stack postfix;
    int length = s.length();

    for (int i = 0; i < length; i++) {
        if (s[i] == '(') {
            operators.push(s[i]);
        }
        else if (isdigit(s[i])) { // If operand, add to postfix
            postfix.push(s[i]);
        }
        else if (s[i] == ')') { // Pop until '(' is found
            while (!operators.isempty() && operators.peek() != '(') {
                postfix.push(operators.pop());
            }
            operators.pop(); // Pop the '('
        }
        else if (isoperator(s[i])) { // Operator encountered
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

    display(postfix);
}

int main() {
    string s;
    cout << "Enter Infix: ";
    cin >> s;

    infixtopostfix(s);
    return 0;
}
