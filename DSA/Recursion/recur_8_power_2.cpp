#include<iostream>
using namespace std;
int power(int b ,int p)
{   
    if(p == 0)
    {
        return 1;
    }
    int a = power(b,p/2);
    if(p%2 == 0)
    {
        return a*a;
    }
    else
    {
        return b*a*a;
    }
}
int main()
{
    int p,b;
    cout<<"Enter the Base and Power :";
    cin>>b>>p;
    int po = power(b,p);
    cout<<"The "<<p<<" th power of "<<b<<" is :"<<po;
}