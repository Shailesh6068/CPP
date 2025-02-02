#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank {
private:
    string name;
    string accountType;
    int accountNumber;
    double balance;

public:
    void input();
    void storeBankData();
    void viewBankData();
    void deposit();
    void withdraw();
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
void Bank::storeBankData() {
    ofstream fout("BANKDATA5.txt", ios::app);
    if (!fout) {
        cout << "Error opening file." << endl;
        return;
    }
    fout << "Name: " << name << endl;
    fout << "Account Type: " << accountType << endl;
    fout << "Account Number: " << accountNumber << endl;
    fout << "Balance: " << balance << endl << endl;
    cout << "Data stored successfully." << endl;
    fout.close();
}
void Bank::viewBankData() {
    ifstream fin("BANKDATA5.txt");
    if (!fin) {
        cout << "Error opening file." << endl;
        return;
    }
    cout << "--- Bank Data ---" << endl;
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}
void Bank::deposit() {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    balance += amount;
    cout << "Amount deposited successfully. Current balance: " << balance << endl;
}

void Bank::withdraw() {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance." << endl;
        return;
    }
    balance -= amount;
    cout << "Amount withdrawn successfully. Current balance: " << balance << endl;
}
int main() {
    Bank b;
    int choice;
    char cont;
    int count = 0;

    while(count == 0)
    {
        cout << "\n1. Input customer data\n";
        cout << "2. View bank data\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5.Exit\n";

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
            case 4 :
                b.withdraw();
                break;
            case 5:
                exit(0);
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
