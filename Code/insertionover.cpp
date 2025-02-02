#include<iostream>
using namespace std;
class sample
{   
    int a;
    string name;

    public:
   // friend ostream& operator<<(ostream &out , sample &s1);
    friend void operator<<(ostream &out ,sample &s3)
    {
        out<<"Write the name and the Roll No. :"<<endl;
    }
    friend istream& operator>>(istream &in , sample &s2);
    void output()
    {
        cout<<"The name and Roll No is: "<<endl<<name<<"     "<<a;
    }
};
// ostream &operator<<(ostream &out , sample &s1)
// {
//     out<<"Write the name and Roll No. : "<<endl;

// }
istream &operator>>(istream  &in , sample &s2)
{
    in>>s2.name>>s2.a;
} 
int main()
{
    sample s;
    cout<<s;
    cin>>s;
    s.output();

    return 0;

}