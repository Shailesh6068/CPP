#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

    cout<<"X :"<<*x<<"  "<<"Y :"<<*y<<endl;
}
int main()
{
    int x,y;

    cout<<"X :";
    cin>>x;
    cout<<"Y :";
    cin>>y;

    int *ptrx = &x;
    int *ptry = &y;
    swap(ptrx , ptry);
    cout<<"X :"<<*ptrx<<"  "<<"Y :"<<*ptry<<endl;

    return 0;
}