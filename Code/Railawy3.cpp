#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
using namespace std;
class railway {
    string name, ty_seat, ac, Type;
    int a, b, c, count;
    float bal;
    int z = 0;
    int x = 0;
    int v = 0;
    int tic_no;
    long long int ph;
    int searchtic_no1;
public:
    static int q;
    void input();
    void phonenum();
    void Balance();
    void storedata();
    void search();
    void deleteTicket();
    static void ReadlastTicket();
    static void WritelastTicket();
};
int railway::q = 780;
void railway::input() 
{
    cout << "Ticket No.: MAH00" << q << endl;
    cout << "Write the Passenger Name: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Write the Phone Number : " << endl;
    cin >> ph;
    phonenum();
    cout << "Select the Seat type (General / Reserve: Extra 50 rs cost on all types of seats.): " << endl;
    cin >> ty_seat;
    if (ty_seat == "Reserve") 
    {
        cout << "Enter the type (AC / Non-AC): ";
        cin >> Type;
    } 
    else 
    {
        Type = "";
    }
    cout << "Write the number of Passenger Members:" << endl;
    cout << "Adult: ";
    cin >> a;
    cout << "Child: ";
    cin >> b;
    cout << "Senior citizen: ";
    cin >> c;
}
void railway::storedata() 
{
    ofstream fout;
    fout.open("Railwaydatafile.txt", ios::app);
    if (!fout) 
    {
        cout << "Error opening file." << endl;
        return;
    } 
    else 
    {
        fout << "Ticket No.: MAH00" << q << endl;
        q++;
        WritelastTicket();
        fout << "Name: " << name << endl;
        fout << "Phone Number: " << ph << endl;
        fout << "Type of Seat: " << ty_seat << " ";
        if (ty_seat == "Reserve") 
        {
            fout << "( " << Type << " )" << endl;
        } 
        else 
        {
            fout << Type << endl;
        }
        fout << "Number of Passenger: " << endl;
        fout << "Adult: " << a << "          Child: " << b << "          Senior citizen: " << c << endl;
        fout << "Total Payable Amount: " << bal << endl << endl;
    }
    fout.close();
}
void railway::ReadlastTicket() 
{
    ifstream fin("LastTicket.txt");
    if (fin) 
    {
        fin >> q;
    }
    fin.close();
}
void railway::WritelastTicket()
{
    ofstream fout("LastTicket.txt");
    if (fout) 
    {
        fout << q;
    }
    fout.close();
}
void railway::search() 
{
    int searchtic_no;
    int flag = 0;
    cout << "Enter the ticket No. (MAH00***): ";
    cin >> searchtic_no;
    cout << endl;
    cout << "                ||| Maharashtra Railway Seva |||           " << endl << endl;
    ifstream fin("Railwaydatafile.txt");
    string line;
    while (getline(fin, line)) 
    {
        if (line == "Ticket No.: MAH00" + to_string(searchtic_no)) 
        {
            flag = 1;
            cout << line << endl;
            while (!line.empty()) 
            {
                getline(fin, line);
                cout << line << endl;
            }
        }
    }
    if(flag == 0)
    {
        cout<<"MAH00" + to_string(searchtic_no);
        cout<<" this Ticket Number is Not Present."<<endl;
    }
    else
    {
        cout << "            *** Have a wonderful trip, Bon Voyage! ***           " << endl;
    }
    fin.seekg(0, ios::beg);
    fin.close();
}
void railway::phonenum() 
{
    count = 0;
    long long int temp = ph;
    while (temp > 0) 
    {
        temp = temp / 10;
        count++;
    }
    if (count != 10) 
    {
        try 
        {
            if (count > 10) 
            {
                throw(0);
            }
            if (count < 10) 
            {
                throw('a');
            }
        } 
        catch (int x) 
        {
            cout << "Error: The Number of Digits in Phone Numbers is greater than 10." << endl;
            cout << "Rewrite Correct Phone Number: ";
            cin >> ph;
            phonenum();
        } 
        catch (char y) 
        {
            cout << "Error: The Numbers of Digits in Phone Number is less than 10." << endl;
            cout << "Rewrite Correct Phone Number: ";
            cin >> ph;
            phonenum();
        }
    }
}
void railway::Balance() 
{
    if (a == 0 && b == 0 && c == 0) 
    {   cout << "                ||| Maharashtra Railway Seva |||           " << endl << endl;
        cout << "             * The amount is refunded in 2-3 hours * " << endl;
        cout << "          *** Sorry for inconvenience, Visit again! *** " << endl;
    } 
    else 
    {
        a = a - z;
        b = b - x;
        c = c - v;
        if (ty_seat == "Reserve") 
        {
            bal = 200 * a + 150 * b + 100 * c;
            z = x = v = 0;
            //cout << bal << endl;
        } 
        else 
        {
            bal = 150 * a + 100 * b + 50 * c;
            z = x = v = 0;
            //cout << bal << endl;
        }
    }
}
void railway::deleteTicket() 
{
    int count1 = 0;
    int choice;
    cout << "Which type of seat you want to delete: " << endl
         << "1: For Adult." << endl
         << "2: For Children." << endl
         << "3: For Senior citizen." << endl
         << "4: Cancel all tickets." << endl
         << "5: For Exit." << endl
         << endl;

    while (count1 == 0) 
    {
        cout << "For Delete, Enter choice number: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Adult: ";
                cin >> z;
                Balance();
                break;

            case 2:
                cout << "Children: ";
                cin >> x;
                Balance();
                break;

            case 3:
                cout << "Senior citizen: ";
                cin >> v;
                Balance();
                break;

            case 4:
                a = 0;
                b = 0;
                c = 0;
                ty_seat = "NA";
                Balance();
                break;

            case 5:
                count1 = 1;
                break;

            default:
                cout << "Enter a valid option." << endl;
                break;
        }
    }
}
int main() 
{
    railway::ReadlastTicket();
    railway b1;
    int r = 0;
    int ch;
    cout << "Welcome to Maharashtra Railway Seva....." << endl;
    cout << "The choices number are as following: " << endl
         << "1: For Input." << endl
         << "2: For Delete." << endl
         << "3: For Storedata." << endl
         << "4: For Display the Ticket." << endl
         << "5: For Exit." << endl
         << endl;

    while (r == 0) 
    {
        cout << "For Profile, Enter the choice: ";
        cin >> ch;
        cout << endl;

        switch (ch) 
        {
            case 1:
                b1.input();
                break;

            case 2:
                b1.deleteTicket();
                break;

            case 3:
                b1.Balance();
                b1.storedata();
                break;

            case 4:
                b1.search();
                break;

            case 5:
                r = 1;
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}
