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
void updateBalance(int accountNumber, double newBalance);
bool findAccount(int accountNumber);};
void Bank::input(){
cout << "Enter customer name: ";
cin.ignore();
getline(cin, name);
cout << "Enter account type: ";
getline(cin, accountType);
cout << "Enter account number: ";
cin >> accountNumber;
cout << "Enter balance: ";
cin >> balance;
storeBankData();}
void Bank::storeBankData(){
ofstream fout("Bankdata8.txt", ios::app);
if (!fout){
    cout << "Error opening file." << endl;
    return;}
fout << "Name: " << name << endl;
fout << "Account Type: " << accountType << endl;
fout << "Account Number: " << accountNumber << endl;
fout << "Balance: " << balance << endl << endl;
cout << "Data stored successfully." << endl;
fout.close();}
void Bank::viewBankData(){
ifstream fin("Bankdata8.txt");
if (!fin) {
    cout << "Error opening file." << endl;
    return;  }
cout << "--- Bank Data ---" << endl;
string line;
while (getline(fin, line)) {
    cout << line << endl;   }
fin.close();}
void Bank::deposit() {
int accountNumber;
double amount;
cout << "Enter account number: ";
cin >> accountNumber;
if (!findAccount(accountNumber)) {
    cout << "Account not found." << endl;
    return;    }
cout << "Enter deposit amount: ";
cin >> amount;
balance += amount;
cout << "Amount deposited successfully. Current balance: " << balance << endl;
updateBalance(accountNumber, balance);}
void Bank::withdraw() {
int accountNumber;
double amount;
cout << "Enter account number: ";
cin >> accountNumber;
if (!findAccount(accountNumber)) {
    cout << "Account not found." << endl;
    return;}
cout << "Enter withdrawal amount: ";
cin >> amount;
if (amount > balance) {
    cout << "Insufficient balance." << endl;
    return; }
balance -= amount;
cout << "Amount withdrawn successfully. Current balance: " << balance << endl;
updateBalance(accountNumber, balance);}
void Bank::updateBalance(int accountNumber, double newBalance) {
 ifstream fin("Bankdata8.txt");
 ofstream fout("temp.txt");
 if (!fin || !fout) {
     cout << "Error opening file." << endl;
     return;    }
 string line;
 while (getline(fin, line)) {
    if (line.find("Account Number: " + to_string(accountNumber)) != string::npos) {
           fout << "Balance: " << newBalance << endl << endl;
      } else {
         fout << line << endl;        }    }
fin.close();
 fout.close();
 rename("temp.txt", "Bankdata8.txt");
}
bool Bank::findAccount(int accountNumber) {
ifstream fin("Bankdata8.txt");
if (!fin) {
    cout << "Error opening file." << endl;
    return false;  }
string line;
while (getline(fin, line)) {
    if (line.find("Account Number: " + to_string(accountNumber)) != string::npos) {
        fin.close();
        return true;       }   }
fin.close();
return false;}
int main(){
Bank b;
int choice;
char cont;
do {
    cout << "\n1. Input customer data\n";
    cout << "2. View bank data\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
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
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
    }
    cout << "Do you want to continue? (y/n): ";
    cin >> cont;
} while (cont == 'y' || cont == 'Y');
return 0;
}
