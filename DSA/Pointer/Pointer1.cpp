#include<iostream>
using namespace std;
int main()
{
    int x = 10;
    cout<<"The Aadress of X is : "<<&x<<endl;

    int *ptr = &x;
    cout<<"The Aadress of X is : "<<ptr<<endl;
    cout<<"The value is :"<<*ptr<<endl;

    x = 23;
    //int *ptrf = &x;
    //cout<<"The Aadress of new X is: "<<ptrf<<" instead of "<<ptr<<endl;
    cout<<"The new X is: "<<*ptr<<endl;

    *ptr = 50;
    cout<<"The Value of X is :"<<x<<endl;

    int z = *ptr;
    cout<<"The value of z is :"<<z<<endl;
    
    return 0;
}