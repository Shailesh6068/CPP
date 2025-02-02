#include<iostream>
using namespace std;
void sum(int s,int n)
{
    if(n == 0)
    {
        cout<<"sum :"<<s;
        return;
    }
    sum(s+n,n-1);
    return;
}
int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;
    sum(0,n);
    return 0;
}