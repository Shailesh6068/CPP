#include<iostream>
using namespace std;
class  stati
{
    int a , b ;
    

    public:
    int static  z;
    void input(int d , int f ,int c)
    {
        cout<<endl<<"z1: "<<stati::z<<endl;
        a = d;
        b = f;
        z = c;

    }
    void output()
    {
        cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"z: "<<z<<endl;

    }

};
int stati::z = 5 ;  //when you declare this automaticaly 'z' become '5' at starting the code.
int main()
{
  stati s1;
  stati s2;

  cout<<endl<<"z1: "<<stati::z<<endl;
  s1.input(5,6,8);
  
  s2.input(1,7,9);
  s1.output();
  s2.output();
  cout<<endl<<"z1: "<<stati::z;
return 0;

}