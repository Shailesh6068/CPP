#include<iostream>
using namespace std;
int main()
{

int day;
cout<<"Write the number of day: "<<endl;
cin>>day;


switch(day)
    {
        case 1:
        cout<<"Monday"<<endl;
        break;

        case 2:
        cout<<"Tuesday"<<endl;
        break;

        case 3:
        cout<<"Wedneseday"<<endl;
        break;

        case 4:
        cout<<"Thursaday"<<endl;
        break;

        case 5:
        cout<<"Friday"<<endl;
        break;


        case 6:
        cout<<"Saturday"<<endl;
        break;


        case 7:
        cout<<"Sunday"<<endl;
        break;


        default:
        cout<<"This number day is not present.";
    }

    return 0;

}