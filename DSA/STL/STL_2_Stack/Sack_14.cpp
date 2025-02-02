#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string> output;
    string str;
    cout << "Enter the String (infix expression without spaces): ";
    cin >> str;

    // Process the string from left to right (no need to reverse here)
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            // If it's a digit, push it directly onto the stack
            output.push(string(1, str[i]));
        }
        else
        {
            // If it's an operator, pop two operands and create a postfix expression
            string v1 = output.top();
            output.pop();
            string v2 = output.top();
            output.pop();
            
            // Form postfix by combining the two operands and the operator
            string res = v2 + v1 + str[i];
            output.push(res);
        }                                           
    }

    cout << "In Postfix: " << output.top() << endl;

    return 0;
}
