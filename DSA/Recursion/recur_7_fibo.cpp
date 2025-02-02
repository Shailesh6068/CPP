#include<iostream>
using namespace std;
int fibo(int n)
{
    if( n == 1 || n == 2)
    {
        return 1;
    }
    return fibo(n-1) + fibo(n-2);

    //or

    // if( n <= 2)
    // {
    //     return n ;
    // }
    // return fibo(n-1) + fibo(n-2);
    
}
int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;
    int f = fibo(n);
    cout<<"Value is :"<<f;
}