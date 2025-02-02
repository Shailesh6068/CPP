#include<iostream>
using namespace std;
int main()
    {
     int a = 4;
     cout<<sizeof(a)<<"\n";

     char _4 = 'a';
     cout<<sizeof(_4)<<endl;

     bool flag;
     a == _4? flag =true: flag = false;
     cout<<flag<<endl;
     
     cout<<(&a)<<endl;


    return 0;

    }