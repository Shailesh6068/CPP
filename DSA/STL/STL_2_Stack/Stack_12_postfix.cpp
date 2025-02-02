#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int Postfix(int v1,int v2,char op)
{
    if (op == '^')
    {
       return pow(v1,v2);
    }
    if (op == '*')
    {
        return v1*v2;
    }
    if (op == '-')
    {
        return v1-v2;
    }
    if (op == '+')
    {
        return v1+v2;
    }
    if (op == '/')
    {
        return v1/v2;
    }
}
int main()
{
    string str;
    stack<int> st;
    cout<<"Enter the String :"<<endl;
    cin>>str;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(isdigit(ch))
        {
            st.push(ch-'0');
        }
        else
        {
            int v2 =  st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(Postfix(v1,v2,ch));             
        }       
    }
    cout<<"The Answer is :"<<st.top();
    return 0;
}