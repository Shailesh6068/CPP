#include<iostream>
using namespace std;
int main()
{
    int n;

    cout<<"Enter the size :"<<endl;
    cin>>n;

    for(int i = 1 ; i <=n ; i++)
    {   
        for(int k =1; k <= n+1-i ; k++)
        {
            cout<<" ";
        }
        for (int  j = 1; j <= 2*i-1; j++)
        {
             cout<<"*";
        }
        
       cout<<endl;
    }
}