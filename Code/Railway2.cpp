#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for atoi

using namespace std;

class railway
{
    string name,ty_seat,ac,Type;
    int a,b,c,count;
    float bal;
    int z =0;
    int x =0;
    int v = 0;
    int tic_no;
    long long int ph;
    int searchtic_no1;
    int aftadultdel;

public:   
    static int q;
    void input();
    void excepion(); 
    void del();
    void storedata();
    void search();
    void searchadult();
    void del1();
    static void readLastTicketNumber();
    static void writeLastTicketNumber();
};
int railway::q=1;
void railway::input()
{
    cout<<"Ticket No.:MAH00"<<q<<endl;
    cout << "Write the Passenger Name: " << endl;
    cin.ignore();
    getline(cin,name);
    cout << "Write the Phone Number : " << endl;
    cin >> ph;
    excepion();
    cout <<"Selct the Seat type ( General / Reserve:- Extra 50 rs cost on all type of seats.) : " << endl;
    cin >> ty_seat;
    if( ty_seat == "Reserve")
        {
            cout<<"Enter the type (AC / Non-AC) :";
            cin>>Type;
        }
    else
        { 
            Type = "";
        }
    cout << "Write the number of Passenger Members :" << endl;
    cout<<"Adult :";
    cin >>a;
    cout<<"Child :";
    cin>>b;
    cout<<"Senior citizen :";
    cin>>c;
}
void railway::storedata()
{   
   // del1();
    ofstream fout;
    fout.open("Railwaydata4.txt",ios::app);
    if(!fout)
    {
        cout<<"Error opening file."<<endl;
    }
    else
    {   
        fout<<"Ticket No.: MAH00"<<q<<endl;
        q++;
        writeLastTicketNumber();
        fout<<"Name: "<<name<<endl;
        fout<<"Phone Number: "<<ph<<endl;
        fout<<"Type of Seat: "<<ty_seat<<" ";
        if( ty_seat == "Reserve")
        {
            fout<<"( "<<Type<<" )"<<endl;          
        }
        else
        { 
            fout<<Type<<endl;
        }
        fout<<"Number of Passenger: "<<endl;
        fout<<"Adult: "<<a<<"       Child: "<<b<<"      Senior citizen: "<<c<<endl;
        fout<<"Total Payable Amount: "<<bal<<endl;
        fout<<endl;
    }
    fout.close();
}
void railway::readLastTicketNumber() {
    ifstream fin("last_ticket_number.txt");
    if (fin) {
        fin >> q;
    }
    fin.close();
}
void railway::writeLastTicketNumber() {
    ofstream fout("last_ticket_number.txt");
    if (fout) 
    {   q++;
        fout << q;
    }
    fout.close();
}
void railway::search()
{   
    int searchtic_no;
    cout<<"Enter the ticket No. :";
    cin>>searchtic_no;
    cout<<endl;
    cout<<"                   ||| Maharashtra Railway Seva |||              "<<endl<<endl;
    ifstream fin("Railwaydata4.txt");
    string line;
    while(getline(fin,line))
    {
        if (line == "Ticket No.:MAH00"+to_string(searchtic_no))
        {
            cout<<line<<endl;
            while(!line.empty())
            {
                getline(fin,line);
                cout<<line<<endl;  
            }
        }
    }
    cout<<"              ***  Have a wonderful trip, Bon Voyage!  ***"<<endl;
    fin.seekg(0,ios::beg);
    fin.close();
}
void railway::del1()
{
    if(a==0&&b==0&&c==0)
        {   cout<<"* The amount is refunded in 2-3 hours * ";
            cout<<endl;
            cout<<"              ***  Sorry for inconvinence , Visit again !  ***"<<endl;
        }
    else
        {
            a = a - z;
            b = b - x;
            c = c - v;
            if(ty_seat == "Reserve")
                {
                    bal =200*a+150*b+100*c;
                    cout << "The Payable Amount :";
                    cout <<bal<<endl;
                }
            else
                {
                    bal =150*a+100*b+50*c;
                    cout << "The Payable Amount :";
                    cout <<bal<<endl;
                }
                    cout<<endl;
                    cout<<"              ***  Have a wonderful trip, Bon Voyage!  ***";
        }
        cout<<endl;


}
void railway::del()
{   
    int count1 = 0; 
    int q;
    cout<<endl;

    cout << "Which type of seat you wan't delete : " << endl
         << "1:For Adult." << endl
         << "2:For Children." << endl
         << "3:For Senior citizen." << endl
         << "4:Cancel all ticket."<<endl
         << "5:For Exit."<<endl<<endl;

    while( count1 == 0)
        {   cout<<endl;
            cout<<"For Delete : Enter choice number :";
            cin>>q;

            switch (q)
            {               
                case 1:
                    cout<<"Adult :";
                    cin>>z;
                    del1();
                    break;

                case 2:
                    cout<<"Children :";
                    cin>>x;
                    del1();
                    break;
                
                case 3:
                    cout<<"Senior citizen :";
                    cin>>v;
                    del1();
                    break;
                
                case 4:
                    a = 0;
                    b = 0;
                    c = 0;
                    ty_seat = "NA";
                    del1();
                    //exit(0);
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
int main()
{
    railway::readLastTicketNumber();
    railway b1;
    int r = 0;
    int ch;
    cout<<"Welcome ! To Maharashtra Railway Seva....."<<endl;
    cout << "The choices number are as following: " << endl
         << "1:For Input." << endl
         << "2:For Delete." << endl
         << "3:For Storedata."<<endl
         << "4:For Display the Ticket."<<endl
         << "5:For Exit."<<endl<<endl;

    while(r == 0)
    {
        cout << "Profile : Enter the choice : ";
        cin >> ch;
        cout<<endl;
    
        switch (ch)
        {
            case 1:
                b1.input();
                break;

            case 2:
                b1.del();
                break;

            case 3:
                b1.del1();
                b1.storedata();

            case 4:
                b1.search();
                break;

            case 5:
                r =1;
                break;

            default:
                cout << "The choice selected by you is invalid.";
        }
        cout<<endl;
    }
    return 0;
}