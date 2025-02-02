#include<iostream>
using namespace std;
int main()
{  
    int x, y ;
    cout<<"Enter X and Y :"<<endl;
    cin>>x>>y;

    int *ptrx = &x;
    int *ptry = &y;
    int result;
    int *ptrresult = &result;
    *ptrresult = *ptrx + *ptry;
    cout<<"X + Y : "<<result<<endl;
    cout<<"X + Y : "<<*ptrresult;
}