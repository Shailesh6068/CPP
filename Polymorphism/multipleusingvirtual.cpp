#include<iostream>
using namespace std;
class student
{
    protected:
    int roll;
    string name;

    public:
    void input()
    {
        cout<<"Enter the name and Roll No. :"<<endl;
        cin>>name>>roll;
    }
};
class test:virtual public student
{
    public:
    float m1,m2;

    void mark()
    {
        cout<<"Enter the Marks:"<<endl;
        cin>>m1>>m2;
    }
};
class sport:public virtual student
{
    public:
    float sp;
    void mark()
    {
        cout<<"Enter the sport mark:"<<endl;
        cin>>sp;
    }
};
class result:public test,public sport
{
    public:
    void add()
    {
        cout<<"Total marks is : "<<m1+m2+sp;
    }
};
int main()
{
    result r;
    r.input();

    return 0;
}