#include<iostream>
using namespace std;
int Sum(int n)
{
    if( n == 1)
    {   return 1; 
    }
    return n+Sum(n-1);
}
int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;

    int fact = Sum(n);
    cout<<"Sum is:"<<fact;
}