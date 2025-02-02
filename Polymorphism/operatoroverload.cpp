#include<iostream>
using namespace std;
class sum
{
  string name;
  int Roll_No;
  static int a;

  public:
  void input();
  void operator=(sum c2);
  int operator+(sum c3);
  void output();
};
int sum::a = 1;
void sum::input()
{
    cout<<"Write the name:"<<endl;
    cin>>name;
    cout<<"Write roll no.:";
    cin>>Roll_No;
}
void sum::operator=(sum c2)
{
   name = c2.name;
   Roll_No =   c2.Roll_No;

}
int sum::operator+(sum c2)
{
    Roll_No = Roll_No + c2.Roll_No;
    return Roll_No;

}
void sum::output()
{
    cout<<"name "<<a<<": "<<name<<endl;
    cout<<"Roll No "<<a<<": "<<Roll_No<<endl;
    a = a+1;
}
int main()
{
 sum c1,c2;
 c1.input();
 c1.output();
 c2=c1;          /*in operator " = " overloading jar aplayala c2 madhye c1 copuy karayacha asel tar "c1=c2 "  n 
                    lihat "c2 = c1 " karan asignment operator right side to left side jate.*/
 c2.output();
 c1+c2;
 c2.output();

return 0;
}
