#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class Bank
{
private:
    string name;
    string accountType;
    long long int ph_num;
    int accountNumber;
    int accountNumber1;
    int balance;
    int balance1;
    string str,str1;

public:
    void input();
    void storeBankData();
    void viewBankData();
    void Error();
    void deposit();
    void withdraw();
    void update();
};
void Bank::input()
{
    cout<<endl;
    cout << "Enter customer name: ";
    cin.ignore();                                         
    getline(cin, name);
    cout<<"Enter the Mobile Number:";
    cin>>ph_num;
    Error();
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
    else
    {
        fout <<"Name: " << name << endl;
        fout <<"Phone Number: "<<ph_num<<endl;
        fout <<"Account Type: " << accountType << endl;
        fout <<"Account Number: " << accountNumber << endl;
        fout <<"Balance: " << balance << endl
            << endl;
    }
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
    cout <<endl<<"--- Bank Data ---" << endl;
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
}
void Bank::Error()
{
    int count = 0;
    long long int newph_num = ph_num;
    while(newph_num > 0)
    {
        newph_num = newph_num / 10;
        count++;
    }
    try
    {
        if (count > 10 || count < 10 )
        {
            throw(0);
        }   
    }
    catch(int a)
    {
        cout<<"Error:The number Entered by you is Incorrect."<<endl;
        cout<<"Rewrite Correct Phone Number : ";
        cin>>ph_num;
        Error();    
    }
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
    
    char numStr[15];

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
            str = to_string(balance);
            cout << "The present balance is: " << balance << endl;
            balance1 = balance + amount;
            cout << "Balance After the Deposit : " << balance1 << endl;
        }
    }

    str1 = to_string(balance1);
    fin.seekg(0,ios::beg);  // Move the file pointer to the beginning
    fin.close();
    
    string filePath = "Bankdata10.txt";
    ifstream fileIn(filePath); // Open the original file for reading
    string tempFilePath = "temp.txt"; // Temporary file
    ofstream fileOut(tempFilePath); // Open the temporary file for writing

    if (!fileIn.is_open() || !fileOut.is_open()) 
    {
        cerr << "Error opening files!" << endl;
        return;
    }

    line;
    while (getline(fileIn, line)) 
    {
        size_t pos = 0;
        // Replace all occurrences of the old word in the line
        while ((pos = line.find(str, pos)) != string::npos) 
        {
            line.replace(pos, str.length(), str1);
            pos += str1.length();
        }
        fileOut << line << endl;
    }

    fileIn.close();
    fileOut.close();

    // Remove the original file and rename the temporary file to the original file name
    remove(filePath.c_str());
    rename(tempFilePath.c_str(), filePath.c_str());

}
void Bank::withdraw()
{
    cout << "Enter the Account Number: ";
    cin >> accountNumber1;

    int amount;
    cout << "Enter withdraw amount: ";
    cin >> amount;

    fstream fin("Bankdata10.txt");

    string line;
    char a;
    char c;
    
    char numStr[15];

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
            str = to_string(balance);
            cout << "The present balance is: " << balance << endl;
            balance1 = balance - amount;
            cout << "Balance After the Deposit : " << balance1 << endl;
        }
    }
    str1 = to_string(balance1);
    
    fin.seekg(0,ios::beg);  // Move the file pointer to the beginning
    fin.close();
    
    string filePath = "Bankdata10.txt";
    ifstream fileIn(filePath); // Open the original file for reading
    string tempFilePath = "temp.txt"; // Temporary file
    ofstream fileOut(tempFilePath); // Open the temporary file for writing

    if (!fileIn.is_open() || !fileOut.is_open()) 
    {
        cerr << "Error opening files!" << endl;
        return;
    }
    line;
    while (getline(fileIn, line)) 
    {
        size_t pos = 0;
        // Replace all occurrences of the old word in the line
        while ((pos = line.find(str, pos)) != string::npos) 
        {
            line.replace(pos, str.length(), str1);
            pos += str1.length();
        }
        fileOut << line << endl;
    }

    fileIn.close();
    fileOut.close();

    // Remove the original file and rename the temporary file to the original file name
    remove(filePath.c_str());
    rename(tempFilePath.c_str(), filePath.c_str());
}
int main()
{
    Bank b;
    int choice;
    char cont;
    int count = 0;

    while (count == 0)
    {
        cout<<"\nThe choices are : "<<endl;
        cout << "1. Input customer data\n";
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
