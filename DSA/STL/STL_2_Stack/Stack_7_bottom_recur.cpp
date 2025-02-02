#include<iostream>  /*  T.C = O(n)     or     S.C. = O(n)  */
#include<stack> 
using namespace std;
void insert_at_bottom(stack<int> &st,int a)
{
    if(st.empty())
    {
        st.push(a);
        return;
    }
    int curr = st.top();
    st.pop();
    insert_at_bottom(st,a);
    st.push(curr);    
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insert_at_bottom(st,5);

    cout<<"After the Add at Bottom :"<<endl;
    while(!st.empty())
    {  
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
}