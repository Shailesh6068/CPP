#include<iostream>
#include<conio.h>
using namespace std;
class A
{
    protected:
    string name;
    int Roll_No;

    public:

    void input()
    {
        cout<<"Enter the name and Roll No.: "<<endl;
        cin>>name>>Roll_No;
    }
    void output()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Roll No :"<<Roll_No<<endl;
    }
};
class B:public A
{
    protected:
    int sub1,sub2;

    public:

    void marks()
    {
        cout<<"Enter the mark of both subject: "<<endl;
        cin>>sub1>>sub2;
    }
    void markshow()
    {

        cout<<"Subject 1 : "<<sub1<<endl<<"Subject 2 : "<<sub2<<endl;
    }
};
class C:public B
{
    protected:
    int sp;

    public:

    void sport()
    {
    cout<<"Enter the Sport marks: "<<endl;
    cin>>sp;
    }
    void sportshow()
    {
        cout<<"Sport Marks : "<<sp<<endl;

    }

    void callinput()
    {
        input();
        marks();
        sport();

    }
    void calldisplay()
    {
        output();
        markshow();
        sportshow();
        
    }
    void sum()
    {
        cout<<"The Total marks are:"<<endl<<sub1+sub2+sp;
    }

    
};
int main()
{
    C cc;
    //cc.input();
    // cc.callinput();        also we can use this to reduce calling time by object.
    cc.input();
    cc.marks();
    cc.sport();

    cc.calldisplay();
    cc.sum();
    getch();                  // hold the console.

    return 0;

}