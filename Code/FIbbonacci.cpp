#include<iostream>
using namespace std;
int main()
{
    long long int a = 0;
    long long int b = 1;
    long long int num;

    cout<<"Enter the nth term of fibonacci :"<<endl;
    cin>>num;

    cout<<"The fibonacci series is :"<<endl;
    cout<<a<<" "<<b<<" ";

    for(int i = 3 ; i<= num ; i++)
    {
        long long int sum = a+b;
        a = b;
        b = sum;

        cout<<sum<<" ";

    }

return 0;

}