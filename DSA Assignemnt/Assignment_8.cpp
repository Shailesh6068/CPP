#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack(){
        top = -1;
    }

    void push(int x) {
        if (top < MAX - 1) {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return 0; // Return 0 if stack is empty
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        return 0; // Return 0 if stack is empty
    }

    bool isEmpty() {
        return top == -1;
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void infixToPostfix(const char infix[], char postfix[]) 
{
    Stack s;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char c = infix[i];

        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) 
        { // If operand, add to postfix
            postfix[j++] = c;
        }
        else if (c == '(') 
        { // If '(', push to stack
            s.push(c);
        }
        else if (c == ')') 
        { // If ')', pop from stack until '('
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); // Pop the '('
        }
        else 
        { // If operator
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                postfix[j++] = s.pop();
            }
            s.push(c); // Push current operator to stack
        }
    }

    // Pop the remaining operators in the stack
    while (!s.isEmpty()) 
    {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}
void reverse(char str[]) 
{
    int length = 0;
    while (str[length] != '\0') length++; // Find length of string
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
void infixToPrefix(const char infix[], char prefix[]) {
    char reversed[MAX];
    int i = 0;

    // Manually copy the infix to reversed
    while (infix[i] != '\0') {
        reversed[i] = infix[i];
        i++;
    }
    reversed[i] = '\0'; // Null-terminate the reversed string
    reverse(reversed);  // Reverse the infix expression

    Stack s;
    int j = 0;
    for (int i = 0; reversed[i] != '\0'; i++) 
    {
        char c = reversed[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) { // If operand, add to prefix
            prefix[j++] = c;
        }
        else if (c == ')') { // If ')', push to stack
            s.push(c);
        }
        else if (c == '(') { // If '(', pop from stack until ')'
            while (!s.isEmpty() && s.peek() != ')') {
                prefix[j++] = s.pop();
            }
            s.pop(); // Pop the ')'
        }
        else { // If operator
            while (!s.isEmpty() && precedence(c) < precedence(s.peek())) {
                prefix[j++] = s.pop();
            }
            s.push(c); // Push current operator to stack
        }
    }

    // Pop the remaining operators in the stack
    while (!s.isEmpty()) {
        prefix[j++] = s.pop();
    }

    prefix[j] = '\0'; // Null-terminate the prefix string
    reverse(prefix);  // Reverse the result to get prefix
}

int performOperation(char op, int val1, int val2) {
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': return val1 / val2;
        default: return 0; // Return 0 for unsupported operations
    }
}

int evaluatePostfix(const char postfix[]) {
    Stack s;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        }
        else { // Operator
            int val2 = s.pop();
            int val1 = s.pop();
            s.push(performOperation(c, val1, val2));
        }
    }
    return s.pop(); // Return the final result
}

int evaluatePrefix(const char prefix[]) {
    Stack s;
    int length = 0;

    // Find the length of the prefix string without using strlen
    while (prefix[length] != '\0') length++;

    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        }
        else { // Operator
            int val1 = s.pop();
            int val2 = s.pop();
            s.push(performOperation(c, val1, val2));
        }
    }
    return s.pop(); // Return the final result
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];
    int choice;

    cout << "\nMenu:\n";
    cout << "1. Convert Infix to Postfix\n";
    cout << "2. Convert Infix to Prefix\n";
    cout << "3. Evaluate Postfix Expression\n";
    cout << "4. Evaluate Prefix Expression\n";
    cout << "5. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an infix expression (operands as single digits): ";
                cin >> infix;
                infixToPostfix(infix, postfix);
                cout << "Postfix expression: " << postfix << endl;
                break;

            case 2:
                cout << "Enter an infix expression (operands as single digits): ";
                cin >> infix;
                infixToPrefix(infix, prefix);
                cout << "Prefix expression: " << prefix << endl;
                break;

            case 3:
                cout << "Enter a postfix expression for evaluation: ";
                cin >> postfix;
                cout << "Postfix evaluation result: " << evaluatePostfix(postfix) << endl;
                break;

            case 4:
                cout << "Enter a prefix expression for evaluation: ";
                cin >> prefix;
                cout << "Prefix evaluation result: " << evaluatePrefix(prefix) << endl;
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
