/***
Name - Shailesh Pawar
Roll no - SYCOD230
PRN - 123B1B230
Div - D(1)

Assignment No. : 2
Tittle : Consider Employee database of PCCOE (at least 20 records). Database contains different fields of 
every employee like EMP-ID, EMP-Name and EMP-Salary. 
a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort
b. Arrange list of Employee alphabetically using Merge Sort 
*/
#include <iostream>
using namespace std;
class Employe
{ 
    string name;
    int Emp_id;
    long long int Salary;

public:
    void read();
    void display();

    friend void merge(Employe arr[], int low, int mid, int high);
    friend void merge_Sort(Employe arr[], int low, int high);
    friend void QuickSort(Employe arr[], int low, int high);
    friend int Partition(Employe arr[], int low, int high);
};
void Employe::read()
{
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter Employe Id: ";
    cin >> Emp_id;
    cout << "Enter the Salary: ";
    cin >> Salary;
}
void Employe::display()
{
    cout << "Employe Name: " << name << endl;
    cout << "Employe Id: " << Emp_id << endl;
    cout << "Salary: " << Salary << endl;
}
void merge(Employe arr[], int low, int mid, int high) 
{
    int size = high - low + 1;
    Employe* temp = new Employe[size]; 
    int left = low;
    int right = mid + 1;
    int i = 0;

    while (left <= mid && right <= high) {
        if (arr[left].name <= arr[right].name) {
            temp[i++] = arr[left++];
        } else {
            temp[i++] = arr[right++];
        }
    }

    while (left <= mid) {
        temp[i++] = arr[left++];
    }

    while (right <= high) {
        temp[i++] = arr[right++];
    }

    for (int i = 0; i < size; i++) {
        arr[low + i] = temp[i];
    }

    delete[] temp;
}
void merge_Sort(Employe arr[], int low, int high) 
{
    if (low < high) 
    {
        int mid = low + (high - low) / 2;
        merge_Sort(arr, low, mid);
        merge_Sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int Partition(Employe arr[], int low, int high)
{
    int pivot = arr[low].Emp_id; // Considering first element as pivot
    int i = low;
    int j = high;

    // Partition the array around the pivot
    while (i < j)
    {
        do
        {
            i++;
        } while (i <= high && arr[i].Emp_id <= pivot);

        do
        {
            j--;
        } while (arr[j].Emp_id > pivot);

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with arr[j]
    swap(arr[low], arr[j]);
    return j;
}

// Quick Sort Function (for sorting by Employee ID)
void QuickSort(Employe arr[], int low, int high)
{
    if(low < high)
    {
        int pos = Partition(arr, low, high + 1);  // Get partition position
        QuickSort(arr, low, pos - 1);             // Recursively sort left half
        QuickSort(arr, pos + 1, high);            // Recursively sort right half
    }
}
int main()
{
    Employe Eobj[30];
    int n;
    cout << "Enter the Number of Employe: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Eobj[i].read();   
    }

    cout << "\nChoose sorting method:" << endl;
    cout << "1. Quick Sort (Sort Employee ID)." << endl;
    cout << "2. Merge Sort (Sort Employee Name)." << endl;
    cout << "3. Exit" << endl;
    int choice;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            QuickSort(Eobj, 0, n - 1);
            cout << "\nEmployee data after sorting by Employee ID:" << endl;
            for (int i = 0; i < n; i++)
            {
                Eobj[i].display();
            }
            break;

        case 2:
            merge_Sort(Eobj, 0, n - 1);
            cout << "\nEmployee data after sorting by Employee Name:" << endl;
            for (int i = 0; i < n; i++)
            {
                Eobj[i].display();
            }
            break;

        case 3:
            cout << "Exiting program..." << endl;
            exit(0);

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }
    return 0;
}
