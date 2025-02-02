#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int Arithmetic(int v1 , int v2 , char op)
{
    if(op == '^') return pow(v1,v2);
    if(op == '*') return v1*v2;
    if(op == '/') return v1/v2;
    if(op == '+') return v1+v2;
    if(op == '-') return v1-v2;
    return -1;
}
int precedence(int op)
{
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
int main()
{
    string str;
    stack<int> num;
    stack<char> ops;
    cout<<"Enter the Oeration:";
    cin>>str;

    for(int i = 0; i < str.size() ; i++)
    { 
        char ch = str[i];
        if(isdigit(ch))
        {
           num.push(ch-'0'); 
        }
        else if(ch == '(')
        {
            ops.push(ch);
        }
        else if(ch == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {   char op = ops.top();
                ops.pop();

                int v1 = num.top();
                num.pop();
                int v2 = num.top();
                num.pop();
                num.push(Arithmetic(v2, v1, op));
            }
            if(!ops.empty())
            {
                ops.pop();
            } 
        }
        else
        {
            while(!ops.empty() && precedence(ops.top()) >= precedence(ch))
            {
                char op = ops.top();
                ops.pop();

                int v1 = num.top();
                num.pop();
                int v2 = num.top();
                num.pop();
                num.push(Arithmetic(v2, v1, op));
            }
            ops.push(ch); 
        }  
    }

    while(!ops.empty())
        {   char ch = ops.top();
            ops.pop();

            int v1 = num.top();
            num.pop();
            int v2 = num.top();
            num.pop();
            num.push(Arithmetic(v2,v1,ch));
        } 

    cout<<"The answer of arithmetic Operation is :"<<num.top();
    return 0;
}