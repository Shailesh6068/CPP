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
    void display();
};

void Bank::input() {
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter account type: ";
    getline(cin, accountType);
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter balance: ";
    cin >> balance;
}

void Bank::storeBankData() {
    ofstream fout("BANKDATA2.txt", ios::app);
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
    ifstream fin("BANKDATA2.txt");
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

void Bank::display() {
    cout << "Name: " << name << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}

int main() {
    Bank b;
    int choice;
    char cont;
    int count = 0;

    while(count == 0)
    {
        cout << "\n1. Input customer data\n";
        cout << "2. Store customer data\n";
        cout << "3. View bank data\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                b.input();
                break;
            case 2:
                b.storeBankData();
                break;
            case 3:
                b.viewBankData();
                break;
            case 4:
                b.deposit();
                break;
            case 5:
                b.withdraw();
                break;
            case 6:
                b.display();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
