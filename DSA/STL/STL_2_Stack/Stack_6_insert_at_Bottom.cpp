#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(stack<int> &st,int a)
{
    stack<int> temp;
    while(!st.empty())
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(a);               // temp.push(a)

    while(!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }

}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
   // stack<int> res = st;      // directly copy stack
    // while(!res.empty())
    // {  
    //     int curr = res.top();
    //     res.pop();
    //     cout<<curr<<endl;
    // }
    insert_at_bottom(st,5);

    cout<<"After the Add at Bottom :"<<endl;
    while(!st.empty())
    {  
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}