#include<iostream>
using namespace std;
class base
{
    public:
    int a = 5;
    int b = 10;

    void show()
    {
        cout<<"Class base :"<<a<<b<<endl;
    }
};
class Derived:public base
{
    public:
    void show()
    {
        cout<<"Derived class.";
    }
};
int main()
{
    base bobj;
    Derived dobj;
    bobj = dobj;
    bobj.show();
}