#include <iostream>
using namespace std;
class bank
{
    string name, type_ac;
    int AC_no;
    float bal;

public:
    void input();
    void display();
    void depo();
    void withd();
};

void bank::input()
{
    cout << "Write the customer name: " << endl;
    cin >> name;
    cout << "Write the Account type: " << endl;
    cin >> type_ac;
    cout << "Write account no. :" << endl;
    cin >> AC_no;
    cout << "Write the balance:"<<endl;
    cin >> bal;
}

void bank::display()
{
    cout << "The customer name: " << endl;
    cout << name<<endl;
    cout << "The Account type: " << endl;
    cout << type_ac<<endl;
    cout << "The account no. :" << endl;
    cout << AC_no<<endl;
    cout << "The balance:"<<endl;
    cout << bal<<endl;
}

void bank::depo()
{
    int dep;
    cout << "Write the amount you Deposite: " << endl;
    cin >> dep;
    cout << "The total amount is : " << bal + dep << endl;
}

void bank::withd()
{
    int wit;
    cout << "Write the amount to withadraw: " << endl;
    cin >> wit;
    cout << "The amount present is: " << bal - wit<<endl;
}
int main()
{
    bank b1;

    int ch;
    string choice;
    cout << "The choices number are as following: " << endl
         << "1:For Input." << endl
         << "2:For deposite money." << endl
         << "3:For withdraw money." << endl
         << "4:For Display Information."<<endl<<endl;
    do
    {
        cout << "Enter the choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b1.input();
            break;

        case 2:
            b1.depo();
            break;

        case 3:
            b1.withd();
            break;

        case 4:
            b1.display();
            break;

        default:
            cout << "The choice selected by you is invalid.";
        }
        cout << "Do you wan't to continue again Yes/No:";
        cin >> choice;

    } while (choice == "Yes");

    return 0;
}
