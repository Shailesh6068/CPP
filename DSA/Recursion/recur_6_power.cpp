#include<iostream>
using namespace std;
int power(int base , int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    return base*power(base,pow-1);
}
int main()
{
    int p;
    int b;
    cout<<"Enter Base :";
    cin>>b;
    cout<<"Enter Power :";
    cin>>p;
    int po = power(b,p);
    cout<<"Ans :"<<po;
}