#include <iostream>
#include <fstream>
using namespace std;

class bank
{
    string name, type_ac;
    int AC_no;
    double bal;

public:
    void input();
    void display();
    void depo();
    void withd();
    
    void storebank()
    {
        ofstream fout;
        fout.open("Bank64.txt",ios::app);
        input();
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }
    
    void viewbankal()
    {
        ifstream fin;
        fin.open("Bank64.txt",ios::in|ios::binary);
        if(!fin)
        {
            cout<<"The file is not exist.";
        }
        else
        {
            fin.read((char*)this,sizeof(*this));  
             while(!fin.eof())
            {    display(); 
                fin.read((char*)this,sizeof(*this)); 
                 
                
                
                  
            }
            // fin.close();
            // while(fin.read((char*)this, sizeof(*this)))
            //     {
            //         display();
            //     }
            fin.close();

        }

    }
};
void bank::input()
{
    cout << "Write the customer name: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Write the Account type: " << endl;
    getline(cin, type_ac);
    cout << "Write account no. :" << endl;
    cin >> AC_no;
    cout << "Write the balance:" << endl;
    cin >> bal;
}

void bank::display()
{
    cout << "The customer name: " << endl;
    cout << name << endl;
    cout << "The Account type: " << endl;
    cout << type_ac << endl;
    cout << "The account no. :" << endl;
    cout << AC_no << endl;
    cout << "The balance:" << endl;
    cout << bal << endl;
}

void bank::depo()
{
    double dep;
    cout << "Write the amount you Deposite: " << endl;
    cin >> dep;
    bal += dep;
    cout << "The total amount is : " << bal << endl;
}

void bank::withd()
{
    double wit;
    cout << "Write the amount to withdraw: " << endl;
    cin >> wit;
    if (wit > bal)
    {
        cout << "Insufficient balance!" << endl;
    }
    else
    {
        bal -= wit;
        cout << "The amount present is: " << bal << endl;
    }
}

int main()
{
    bank b1;
    fstream obj;

    int ch;
    string choice;
    cout << "The choices number are as following: " << endl
         << "1: For Input." << endl
         << "2: For deposite money." << endl
         << "3: For withdraw money." << endl
         << "4: For Display Information." << endl
         << endl;

    do
    {
        cout << "Enter the choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
         
            b1.storebank();
            break;

        case 2:
            b1.depo();
            break;

        case 3:
            b1.withd();
            break;

        case 4:
            b1.viewbankal();
            break;

        default:
            cout << "The choice selected by you is invalid.";
        }
        cout << endl;
        cout << "Do you want to continue again Yes/No:";
        cin >> choice;
        cout << endl;

    } while (choice == "Yes");

    return 0;
}
