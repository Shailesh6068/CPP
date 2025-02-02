#include<iostream>
#include<stack>
using namespace std;
void insert_at_idx(stack<int> &st,int idx , int val)
{
    stack<int> temp;
    int count =0;
    int size = st.size();
    while(count < size-idx)
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
        count++;
    }
    st.push(val);
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
    insert_at_idx(st,2,55);
    cout<<"After the insert at index:"<<endl;
    while(!st.empty())
    {  
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    return 0;
}