#include<iostream>
using namespace std;
class A
{
    public:
    void message()
    {
        cout<<"It is Inheritance."<<endl;
    }
};
class B:public A
{
    public:
    void Display()
    {
        cout<<"It is a class B member function."<<endl;
    }

};
class C:public A
{
    public:
    void putdata()
    {
    cout<<"It is a class of C member function."<<endl;
    }
};
int main()
{
    B bb;
    C cc;
    bb.message();
    bb.Display();
    cc.message();
    cc.putdata();
    cc.message();

    return 0;

}