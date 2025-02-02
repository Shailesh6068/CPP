#include<iostream>
using namespace std;
class parent
{
public:
int x;
string name;
    parent()
    {cout<<"Parent class constructor."<<endl;    }
    ~parent()
    {cout<<"Parent class destructor.";}
};
class child:public parent
{
    public:
    child()
    {cout<<"Child class constructor."<<endl;}
    ~child()
    {cout<<"Child class destructor."<<endl;}

};
class child2:public child
{   public:
    child2()
    {cout<<"Child2 class constructor."<<endl;}
    ~child2()
    {cout<<"Child2 class destructor."<<endl;}


};
int main()
{
    child2 c;

return 0;
};