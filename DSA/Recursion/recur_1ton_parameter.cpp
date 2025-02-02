#include<iostream>
using namespace std;
void increas(int x,int n)
{
    if(x>n)
    {
        return;
    }
    cout<<x<<" ";
    increas(x+1,n);
}
int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;
    increas(1,n);
    return 0; 
}