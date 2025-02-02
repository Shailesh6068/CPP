#include<iostream>
using namespace std;
class A
{
    public:
    int a;
    void putdata(int a)
    {
         this->a = a;                 // it give random value to solve this use this keyworld
    }                                //this keyword create a instance of the object.

    // A & putdata(int a)
    // {
    //     this->a = a;                 // Another method  = 2
    //     return *this;
    // }     

    void show()
    {
        cout<<"Value of a:"<<a;
    }
};
int main()
{
    A a;
    a.putdata(6);
  //  a.putdata(6).show();          // call method = 2
    a.show();
}