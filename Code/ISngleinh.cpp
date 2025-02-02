#include<iostream>
using namespace std;

class Parent
{
    public:
        Parent()
            {
                cout<<"Parent"<<endl;
            }


};
class child:public Parent
{
    public:
        child()
             {
                cout<<"Child";
             }

};
int main()
{
    child c;//he lihalyashivay constructor use hot nahi.

    return 0;
}