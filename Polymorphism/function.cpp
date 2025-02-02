#include<iostream>
using namespace std;
void add(int x ,int y )
{
   cout<<"Addition is:"<<x+y<<endl;

}
void sum(float x ,float y )
{
   cout<<"Addition is:"<<x+y;

}
int addi(int b, int z)
{
    return b+z;

}

int main()
{
     add(5.6,4.4);
     sum(6.5,8.9);
   //int a =  addi(9,8);
   cout<<endl<<"The sum of numbers is: "<<addi(9,8);
     return 0;

}