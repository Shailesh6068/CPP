#include<iostream>
#include<conio.h>
using namespace std;
inline int square(int a)
{
    if ( a > 0 )
    {
       cout<<"It is even."<<endl;
    }
    
    return a*a;
}

int main()
{
  cout<<"Square : "<<square(6)<<endl;
  //getch();         Hold the output console.
  return 0;
}