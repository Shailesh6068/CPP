#include <iostream>
using namespace std;
#define size 10
class Employee
{
    int Emp_id;
    string Emp_name;
    float salary;

public:
    int getEmp_id()
    {
        return Emp_id;
    }

    void readData()
    {
        cout << "\nEnter Employee id: ";
        cin >> Emp_id;
        cout << "Enter Employee name: ";
        cin >> Emp_name;
        cout << "Enter Employee salary: ";
        cin >> salary;
    }
    void showData()
    {
        cout << "\nEmp_id is: " << Emp_id;
        cout << "\nEmployee name is: " << Emp_name;
        cout << "\nEmployee salary is: " << salary;
        cout << endl;
    }
};
class Hashtable
{
    Employee E[size];
    int flag[size];

public:
    int HashFunction(int id)
    {
        return id % size;
    }

    Hashtable()
    {
        for (int i = 0; i < size; i++)
        {
            flag[i] = 0;
        }
    }

    void insertEmployee()
    {
        Employee newR;
        newR.readData();
        int id = newR.getEmp_id();
        int pos = HashFunction(id);

        if(flag[pos] == 0)
        {
            E[pos] = newR;
            flag[pos] = 1;
        }
        else
        {
            for(int i = 0; i < size; i++)
            {
                pos = (pos + i) % size;
                if (flag[pos] == 0)
                {
                    E[pos] = newR;
                    flag[pos] = 1;
                    break;
                }
            }
        }
    }
    
    void displayTable()
    {
        for (int i = 0; i < size; i++)
        {
            if (flag[i] == 1)
            {
                cout << "\nPosition " << i << ": ";
                E[i].showData();
            }
            else
            {
                cout << "\nPosition " << i << " is Empty." << endl;
            }
        }
    }
    
    void SearchEmployee()
    {
        int id;
        cout << "\nEnter Employee id you want to search: ";
        cin >> id;
        int pos = HashFunction(id);

        for(int i = 0; i < size; i++)
        {
            int si = (pos + i) % size;
            if (flag[si] == 1 && E[si].getEmp_id() == id)
            {
                cout << "Employee " << id << " is found at position " << si << endl;
                return;
            }
        }
        cout << "Employee " << id << " not found.\n";
    }
};
int main()
{
    Hashtable ht;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ht.insertEmployee();

            break;

        case 2:
            ht.SearchEmployee();
            break;

        case 3:
            ht.displayTable();
            break;

        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}