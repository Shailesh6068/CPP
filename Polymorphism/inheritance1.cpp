#include<iostream>
using namespace std;
class A
{
    int x;

    protected:
    int y;

    public:
    void input()
    {
        cout<<"Enter a no.:"<<endl;
        cin>>y;

    }
    int getx()
    {

        cout<<"Enter the value of x :"<<endl;            //thi funcion made to access the private variable
        cin>>x;

        return x;
    }

};
class B:public A
{  

    int z;

    public:
    void inp()
    {
        cout<<"Enter he value of z"<<endl;
        cin>>z;
    }
    void add()
    {
        cout<<"The addition of number is: "<<z+y<<endl;
    }
    void sum()
    {
        cout<<" x + y + z :"<<getx()+y+z;
    }

};
int main()
{

    B aa;
    aa.input();
    aa.inp();
    aa.add();
    aa.sum();

    return 0;

}