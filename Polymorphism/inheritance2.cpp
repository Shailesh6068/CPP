#include<iostream>
#include<conio.h>
using namespace std;
class A
{
    int x;

    protected:
    int y;

    public:
    void input()
    {
        cout<<"Enter a y :"<<endl;
        cin>>y;

    }
    int getx()                                          //yala call karayachi garaj nasate karan he direct function call hot aahe
    {

        cout<<"Enter the value of x :"<<endl;            //this funcion made to access the private variable
        cin>>x;

        return x;
    }

};
class B
{  
    protected:
    int z;

    public:
    void inp()
    {
        cout<<"Enter he value of z"<<endl;
        cin>>z;
    }
  
   

};
class C:public A,public B
{   
    public:
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

    // A aa;
    // aa.input();
    // aa.getx();
    C cc;
    cc.input();
    cc.inp();
    cc.add();
    cc.sum();
    getch();    //this is present in conio header file.Therefore it is IMP to declare conio header file.



   

    return 0;

}