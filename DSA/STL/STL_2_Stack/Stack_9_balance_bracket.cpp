#include<iostream>
#include<stack>
using namespace std;
bool is_balance(string n)
{
    stack<char> st;
    
    for (int i = 0; i < n.size() ; i++)
    {
        char ch = n[i];
        if(ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')' and !st.empty() and st.top() == '(' )
            {
                st.pop();
            }
            else if (ch == ']' && !st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else if (ch == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }          
        }        
    }
    return st.empty();  // when we write here true instead of st.empty() then "(()" jevha aapan hi string
                        //  input takli tevha ")" jevha he aal tevha "(" he pop zal.
                        // aani tyamule condition false xali nahi aani tari tyane return true kel.
}                       
int main()
{   
    string n;
    cout<<"Enter the string :";
    cin>>n;
    cout<<is_balance(n);
    
    return 0;
}