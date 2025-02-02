#include <iostream>
using namespace std;
class railway
{
    string name,ty_seat,ac,Type;
    int a,b,c,count;
    int z =0;
    int x =0;
    int v = 0;
    long long int ph;
public:
    void del();
    void input();
    void display();  
    void excepion();
};
void railway::del()
{   
    int count1 = 0; 
    int q;
    
    cout << "Which type of seat you wan't delete : " << endl
         << "1:For Adult." << endl
         << "2:For Children." << endl
         << "3:For Senior citizen." << endl
         << "4:Cancel all ticket."<<endl
         << "5:For Exit."<<endl<<endl;
    while( count1 = 0)
        {
            cout<<"Enter choice number :";
            cin>>q;
            switch (q)
            {
               
            case 1:
                cout<<"Adult :";
                cin>>z;
                break;

            case 2:
                cout<<"Children :";
                cin>>x;
                break;
            
            case 3:
                cout<<"Senior citizen :";
                cin>>v;
                break;
            
            case 4:
                a = 0;
                b = 0;
                c = 0;
                break;
            
            case 5:
                count1 = 1;
                break;

            default:
                cout<<"Enter the valid option."<<endl;
                break;
            }
        }
    
}
void railway::excepion()
{   
    count = 0;
    long long int temp = ph;
     while(temp > 0)
    {
        temp = temp/10;
        count++;
    }
    
    if (count != 10)
    {    
        try
        {
            if (count > 10 )
            {
            throw(0);
            }
            if (count < 10)
            {
                throw('a');
            }
        }
        catch(int x)
        {
            cout<<"Error : The Number of Digits in Phone Numbers is greater than 10."<<endl;
            cout<<"Rewrite Correct Phone Number : ";
            cin>>ph;
            excepion();
            
          
        }
        catch(char y)
        {
            cout<<"Error : The Numbers of Digits in Phone Number is less than 10."<<endl;
            cout<<"Rewrite Correct Phone Number : ";
            cin>>ph;
            excepion();           
        }
    }  
}
void railway::input()
{
    cout<<endl;
    cout << "Write the Passenger Name: " << endl;
    cin >> name;
    cout << "Write the Phone Number : " << endl;
    cin >> ph;
    excepion();
    cout << "Selct the Seat type ( General / Reserve ) : " << endl;
    cin >> ty_seat;
    if( ty_seat == "Reserve")
    {
        cout<<"Enter the type (AC / Non-AC) :";
        cin>>Type;
    }
    else{ Type = "";}
    cout << "Write the number of Passenger Members :" << endl;
    cout<<"Adult :";
    cin >>a;
    cout<<"Child :";
    cin>>b;
    cout<<"Senior citizen :";
    cin>>c;
}
void railway::display()
{   
    cout<<endl;
    cout << "The customer name : ";
    cout << name<<endl;
    cout << "The Phone Number : ";
    cout << ph<<endl;
    cout << "The Seat type :";
    cout << ty_seat;
     if( ty_seat == "Reserve")
    {
        cout<<"( "<<Type<<" )";
      
    }
    cout<<endl;
    cout<<"Total fair(Adult + Children + citizen) :";
    cout<<a+b+c<<endl;
    if(a==0&&b==0&&c==0)
    {
        cout<<"Sorry for inconvinence , Visit again !"<<endl;
    }
    else
    {
    a = a - z;
    b = b - x;
    c = c - v;
    float bal =150*a+100*b+50*c;
    cout << "The Payable Amount :";
    cout <<bal<<endl;
    }
}
int main()
{
   railway b1;

    int r = 0;
    int ch;
    cout << "The choices number are as following: " << endl
         << "1:For Input." << endl
         << "2:For Delete." << endl
         << "3:For Display Information."<<endl
         << "4:For Exit."<<endl<<endl;

    while(r = 0)
    {
        cout << "Enter the choice: ";
        cin >> ch;
    
        switch (ch)
        {
        case 1:
            b1.input();
            break;

        case 2:
            b1.del();
            break;

        case 3:
            b1.display();
            break;

        case 4:
            r =1;
            break;

        default:
            cout << "The choice selected by you is invalid.";
        }
    }

    return 0;
}