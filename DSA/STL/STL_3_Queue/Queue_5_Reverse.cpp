#include<iostream>
#include<Queue>
#include<stack>
using namespace std;
int main()                 // For reverse = queue -> stack  -> queue
{
    stack<int> st;
    queue<int> q;
// 10 20 30 40 50
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while(!q.empty())
    {
        cout<<q.front()<<"  ";
        q.pop();
    }

    return 0;
}