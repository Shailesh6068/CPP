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
    int balance;

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

    int amount;
    cout << "Enter deposit amount: ";
    cin >> amount;

    fstream fin("Bankdata10.txt");

    string line;
    char a;
    char c;
    
    char numStr[4];

    while (getline(fin, line))
    {
        if (line == "Account Number: " + to_string(accountNumber1))
        {
            while (a != ' ')
            {
                a = fin.get();
            }
            char ch;
            int i = 0;
            while (ch != '\n')
            {
                ch = fin.get();
                numStr[i] = ch;
                i++;
            }

            balance = atoi(numStr);
            cout << "The present balance is: " << balance << endl;
            balance = balance + amount;
            cout << "Balance After the Deposit : " << balance << endl;
            // Update the balance in the file
            // ...
        }
    }
    string str = to_string(balance);
    
    // Move the file pointer to the beginning
    fin.seekg(0,ios::beg);
    fin.close();
    
    string line1;
    fstream fin1("Bankdata10.txt",ios::in|ios::out);
    char arr1[4];
    // Read the file again to print the updated balance
    while (getline(fin1, line1))
    {
        if (line1 == "Account Number: " + to_string(accountNumber1))
        {
            
            while (c != ' ')
            {
                c = fin1.get();
                cout << c;
            }

            fin1<<str<<endl;
            
           // int i = 0;

            // char ca;
            // while (ca != '\n')
            // {
            //     ca = fin1.get();
            //     //cout<<ca;
            //     arr1[i] = ca;
            //     cout<<arr1[i];
            //     i++;
                
            // }


        }
    }
}
void Bank::withdraw()
{
    cout << "Enter the Account Number: ";
    cin >> accountNumber1;

   int amount;
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
