/*** 
Name - Shailesh Pawar
Roll no - SYCOD230
PRN - 123B1B230
Div - D(1)

Assignment No. : 1

Tittle : Consider a student database of SY COMP class (at least 15 records). Database contains different 
fields of every student like Roll No, Name and SGPA. 
a. Design a roll call list, arrange list of students according to roll numbers in ascending order 
using Insertion Sort
b. Arrange list of students alphabetically using shell sort
c. Arrange list of students to find out first ten toppers from a class using Radix sort
***/

#include<iostream>
#include<climits>
using namespace std;
class student
{
    string name;
    int roll_no;
    float sgpa;

    public:
    void read();
    void display();
    void insertion();

    friend void insertion_sort(student s[20],int n);
    friend void shell_sort(student[],int n);
    friend void radix_sort(student s[20] , int n);
    friend void count_sort(student[] ,int pos ,int n );
};
void insertion_sort(student s[20], int n)
{
    for (int i =1 ; i < n ; i++)
    {
        student X = s[i];
        int j = i - 1;
        while ( j >=0 && s[j].roll_no > X.roll_no)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = X;
    } 
}
void shell_sort(student s[20], int n)
{
    for (int gap = n/2 ;gap >= 1 ; gap = gap/2 )
    {
        for(int i = gap ; i < n ; i++)  
        {
            student X = s[i];
            int j = i - gap;
            while (j >=0 && s[j].name > X.name)
            {
                s[j+gap] = s[j];
                j = j - gap;
            }
        s[j+gap ] = X;
        }
    } 
}
void count_sort(student s[], int pos, int n)
{
    int freq[10] = {0}; 

    for (int i = 0; i < n; i++)
    {
        int digit = ((int)(s[i].sgpa * 100) / pos) % 10;
        freq[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }

    student *ans = new student[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = ((int)(s[i].sgpa * 100) / pos) % 10;
        ans[--freq[digit]] = s[i];
    }

    for (int i = 0; i < n; i++)
    {
        s[i] = ans[i];
    }

    delete[] ans; 
}
void radix_sort(student s[], int n)
{
  
    float max_sgpa = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa > max_sgpa)
        {
            max_sgpa = s[i].sgpa;
        }
    }

    int max = (int)(max_sgpa * 100);
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        count_sort(s, pos, n);
    }
}

void student::read()
{
    cout<<"Enter the name :";
    cin>>name;
    cout<<"Roll No:";
    cin>>roll_no;
    cout<<"Enter the sgpa:";
    cin>>sgpa; 
}
void student::display()
{
    cout<<"Name of the student:"<<name<<endl;
    cout<<"Roll No:"<<roll_no<<endl;
    cout<<"sgpa:"<<sgpa<<endl;   
    cout<<"----------------------------------------------\n";
}
void displayAll(student s[], int n)
{
    cout << "Data after sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }
}
int main()
{
    int n;
    student sobj[20];
    cout<<"Enter the Number of Student :";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        sobj[i].read();   
    }
    cout<< "Choose sorting method:" << endl
        << "1.Sorting by roll number using Insertion Sort. " << endl
        << "2.Sorting by name using Shell Sort." << endl
        << "3.Finding top 10 students by SGPA using Radix Sort. " << endl
        << "4.Display sorted list" << endl
        << "5.Exit" << endl;

    int choice;
    while (true)
    {   
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            insertion_sort(sobj ,n); 
            cout << "Sorted by roll number." << endl;
            break;
        case 2:
            shell_sort(sobj ,n); 
            cout << "Sorted by name." << endl;
            break;
        case 3:
            radix_sort(sobj ,n); 
            cout << "Sorted by SGPA." << endl;
            break;
        case 4:
            displayAll(sobj, n);
            break;
        case 5:
            cout << "Exiting the Program!!" << endl;
            return 0; // Exit the program
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
       }
    }  
    return 0;
}