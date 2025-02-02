#include<iostream>
using namespace std;
template<class T>
class search
{
    T n;
    public:
    T a[10];

    void input()
    {
        cout<<"Enter the Element : "<<endl;
        for(int i = 0 ; i < 10 ;i++)
        {
            cin>>a[i];
        }      
    }

    void output()
    {
        for(int i = 0 ; i < 10 ;i++)
        {
            cout<<a[i]<<" ";
        }

        cout<<endl;
        cout<<"Enter the Element which you wan't Search:"<<endl;
        cin>>n;
    }

    void search1()
    {
        for(int i = 0 ; i <10;i++)
        {
            if(n==a[i])
            {
                cout<<"The number is found at "<<i+1<<" Position."<<endl;
                break;
            }

        }

    }


};
int main()
{

    search<int> s1;
    search<char> s2;
    s1.input();
    s1.output();
    s1.search1();
    s2.input();
    s2.output();
    s2.search1();
    return 0;
}