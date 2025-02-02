#include<iostream>
using namespace std;

class Parent
{
    public:
        Parent()
            {
                cout<<"Parent"<<endl;
            }
        void show()
        {
            cout<<"I am acsess the data parent by grandchild";
        }
        void sh()
        {
            cout<<"I am acsess the data parent by grandchild";
        }
};
class child:public Parent
{
    public:
        child()
             {
                cout<<"Child"<<endl;
             }

};
class grandchild:public child
{    public:
        grandchild()
              {
                 cout<<"Grandchild"<<endl;

              }
};
class grand:public grandchild
{    public:
        void grand1()
              {
                 cout<<"Grand"<<endl;
              }
};
int main()
{
   // child c;//he lihalyashivay constructor use hot nahi.
    grandchild g;
    g.show();
    grand g1;      
    g1.sh();           //it access the data.

    return 0;
}