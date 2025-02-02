#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a;
    cout<<"Enter the Number:"<<endl;
    cin>>a;

    if( a%2 == 0)
        {
            goto even;
        }
    else
        {
            goto odd;
        }

    even:
        cout<<"\n The no. is Even.";
        //exit(0);  1st way
        //return 0;  2nd way        HE takan imp asat.karan he nahi takla tar even chya khali je kahi aahe te prin hote.

    odd:
        cout<<"\n The no. is Odd.";
        //exit(0);   1st way
        //return 0;  2nd way

//return 0;  1st way
}