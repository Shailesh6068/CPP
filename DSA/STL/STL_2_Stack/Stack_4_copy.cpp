#include<iostream>
#include<stack>
using namespace std;
void display(stack<int> st)
{
    while(not st.empty())
    {
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;    
    }
}
stack<int> copy_stack(stack<int> &input)
{
    stack<int> temp;
    while(not input.empty())
    {
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    stack<int> result;
    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    display(st);
    cout<<"Stack after Copy :"<<endl;
    stack<int> res =  copy_stack(st);        // copy stack st into the res
    // while(not res.empty())
    // {
    //     int curr = res.top();
    //     res.pop();
    //     cout<<curr<<endl;    
    // }
    display(res);
   return 0; 
}