#include<iostream>
#include<stack>
using namespace std;
void copy_Stack(stack<int> &st,stack<int> &result)
{
    if(st.empty())
    {
        return;
    }
    
    int curr = st.top();
    st.pop();
    copy_Stack(st,result);
    result.push(curr);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // display(st);
    cout<<"Stack after Copy :"<<endl;
    stack<int> res;
    copy_Stack(st,res);
    while(not res.empty())
    {
        int curr = res.top();
        res.pop();
        cout<<curr<<endl;    
    }
    
   return 0; 
}