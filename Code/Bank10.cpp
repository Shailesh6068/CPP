#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank
{
private:
    string name;
    string accountType;
    int accountNumber;
    int accountNumber1;
    double balance;

public:
    void input();
    void storeBankData();
    void viewBankData();
    void deposit();
    void withdraw();
    void update();
};
void Bank::input()
{
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter account type: ";
    getline(cin, accountType);
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter balance: ";
    cin >> balance;

    storeBankData();
}
void Bank::storeBankData()
{
    ofstream fout("Bankdata10.txt", ios::app);
    if (!fout)
    {
        cout << "Error opening file." << endl;
        return;
    }
    fout << "Name: " << name << endl;
    fout << "Account Type: " << accountType << endl;
    fout << "Account Number: " << accountNumber << endl;
    fout << "Balance: " << balance << endl
         << endl;
    cout << "Data stored successfully." << endl;
    fout.close();
}
void Bank::viewBankData()
{
    ifstream fin("Bankdata10.txt");
    if (!fin)
    {
        cout << "Error opening file." << endl;
        return;
    }
    cout << "--- Bank Data ---" << endl;
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
}
void Bank::deposit()
{
    cout << "Enter the Account Number: ";
    cin >> accountNumber1;

    // double amount;
    // cout << "Enter deposite amount: ";
    // cin >> amount;

    fstream fin("Bankdata10.txt");
    string line;

    char numStr[4];
    while(getline(fin, line))
    {

        if (line == "Account Number: " + to_string(accountNumber1))
        {
            cout<<"Account number is found"<<endl;
            char ch;
           
            char c = fin.tellg();
            cout<<"c :"<<c<<endl;
            fin.seekg(7, ios::beg);
            char d = fin.tellg();
            cout<<"d :"<<d<<endl;
            //int i = 0;
            while(ch != '\n')
            {
                ch = fin.get();
                cout<<ch;
            }
            // while (ch != '\n')
            // {
            //     ch = fin.get();
            //     cout<<ch;
            //     //numStr[i] = ch; 
            //     //i++;              
            // }
            // int num = atoi(numStr);
            // cout<<"The balance is: "<<num;
            // result = result + amount;
            // cout << "Balance:" << result;
            // cout << "Amount deposite successfully.";
        
        }
    }
}
void Bank::withdraw()
{
    cout << "Enter the Account Number: ";
    cin >> accountNumber1;

    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    fstream fin("Bankdata10.txt");
    string line;

    while (getline(fin, line))
    {
        if (line == "Account Number: " + to_string(accountNumber1))
        {
            balance = balance - amount;
            fin << "Balance:" << balance;
            cout << "Amount withdrawn successfully. Current balance: ";
            exit(0);
        }
    }
}
int main()
{
    Bank b;
    int choice;
    char cont;
    int count = 0;

    while (count == 0)
    {
        cout << "\n1. Input customer data\n";
        cout << "2. View bank data\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << " 5.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b.input();
            break;

        case 2:
            b.viewBankData();
            break;

        case 3:
            b.deposit();
            break;

        case 4:
            b.withdraw();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
