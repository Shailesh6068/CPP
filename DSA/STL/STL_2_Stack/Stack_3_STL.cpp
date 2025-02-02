#include<iostream>
#include<stack>
#include<list>
using namespace std;
void display(stack<int> s)
{
    while (!s.empty())    //also use not s.empty()
    {
        int curr = s.top();
        s.pop();
        cout<<curr<<endl; 
    } 
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    display(s);
    s.pop();
    cout<<"After Pop :\n";
    display(s);
    cout<<"\n element at top: "<<s.top()<<endl;
    cout<<"Is empty :"<<s.empty();

    return 0;
}