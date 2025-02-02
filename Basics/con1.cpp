#include<iostream>
using namespace std;

class parent
{
public:
 parent()    //Default consrtuctor :- no arguments pass.
 { 
   cout<<"the parent"<<endl;
 }
 int show()
 {
    return 5;
 }
};
class child:public parent
{
    public:
    child()
    {
    cout<<"The child"<<endl;
    }
    void multiply()
    {
      cout<<"Multiply is :"<<6*show();
    }
};
int main()
{
    child c;
    c.multiply();
    return 0;
}