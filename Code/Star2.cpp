#include<iostream>
using namespace std;
int main()
{
    int n;

    cout<<"Enter the size :"<<endl;
    cin>>n;
    int a = n;
    for(int i = 1 ; i <=n ; i++)
    {          
        for(int k =1; k <= a ; k++)
        {
            cout<<" ";
        }
        a--;
        for (int  j = 1; j <= 2*i-1; j++)
        {
             cout<<"*";
        }      
       cout<<endl;
    }
}