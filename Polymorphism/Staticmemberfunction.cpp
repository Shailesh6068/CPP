#include<iostream>
using namespace std;
class static1
{
    int x = 5;
    static int y;

    public:

    void output();

    static void show()
    {
        cout<<"Static Y : "<<y<<endl;

    }
    static void show2();

};
int static1::y=1;
void static1::output()
    {
        cout<<"It can access the static and simple variable:"<<endl;
        cout<<" X : "<<x<<" \n Y : "<<y<<endl;
        y = y+1;
    }
void static1::show2()
    {
        cout<<"Static function when Declared in outside the class:"<<endl;
        cout<<" Y : "<<y<<endl;
    }
int main()
    {
        static1 s1;
        s1.output();
        s1.show();         // 1st  way of calling
        static1::show2();  // 2nd way of calling
        
        return 0;
    }
