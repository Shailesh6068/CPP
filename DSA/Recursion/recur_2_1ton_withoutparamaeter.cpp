#include<iostream>
using namespace std;
void increas(int n)
{
    if(n == 0)
    {
        return;
    }
    increas(n-1);
    cout<<n<<" ";
    return;
}
int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;
    increas(n);
    return 0; 
}