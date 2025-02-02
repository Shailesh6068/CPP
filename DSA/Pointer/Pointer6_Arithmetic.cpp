#include<iostream>
using namespace std;
int main()
{
    int x = 20;
    double y = 9.78;

    int *ptr = &x;
    double *ptrd = &y;

    cout<<"Size of x :"<<sizeof(x)<<"\n";
    cout<<"Size of y :"<<sizeof(y)<<"\n";

    cout<<ptr<<"   "<<(ptr+1)<<"\n";
    cout<<ptrd<<"   "<<(ptrd+1)<<"   "<<(ptrd+2)<<"   "<<(ptrd+3)<<"  "<<(ptrd-1)<<"\n";
    
}