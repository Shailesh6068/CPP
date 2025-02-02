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
    int rollno;
    string name;
    float sgpa;

    public:
    void read()
    {
        cout<<"Name :";
        cin>>name;
        cout<<"Roll No :";
        cin>>rollno;
        cout<<"sgpa :";
        cin>>sgpa;
    }
    void display()
    {
        cout<<name<<"  "<<rollno<<"     "<<sgpa<<endl; 
    }

    friend void insertion_sort(student s[] , int no)
    {
        for (int i = 1; i <no ; i++)
        {
            student X = s[i];
            int j  = i - 1;
            while (j >= 0 && s[j].rollno > X.rollno)
            {
                s[j+1] = s[j];
                j--;
            }
            s[j+1] = X; 
        } 
    }

    friend void shell_sort(student s[] , int no)
    {
       for (int gap = no /2; gap > 0; gap = gap/2)
       {
         for(int i = gap ; i < no ; i++)
         {
            student X = s[i];
            int j = i - gap;
            while(j >= 0 && s[j].name > X.name)         
            {
                s[j+gap] = s[j];
                 j = j-gap;
            }
            s[j+gap] = X;
         }
       }
    }

    friend void count_sort(student s[] , int pos , int no)
    { 
        int freq[10] = {0};

        for (int  i = 0; i < no ; i++)
        {
           int digit = ((int)(s[i].sgpa * 100) / pos) % 10;
          freq[ digit]++;
        }
        
        for(int i = 1 ; i < 10 ; i++)
        {
            freq[i] = freq[i] + freq[i-1];
        }
        
        student *temp = new student[no];
        for(int i = no-1 ; i >= 0 ; i--)
        {   int digit = ((int)(s[i].sgpa*100)/pos)%10;
            temp[--freq[digit]] = s[i];
        }
        
        for(int i = 0 ; i < no ; i++)
        {
            s[i]  = temp[i];
        }
        
        delete[] temp;
    }

    friend void radix_sort(student s[] , int n)
    {    
        float max = INT_MIN;
        for(int i = 0; i < n ; i++)
        {
            if(max < s[i].sgpa)
            {
                max = s[i].sgpa;
            }
        }
        
        int max_no = (int)(max* 100);
        for(int pos = 1 ; max_no/pos > 0 ; pos = pos * 10)
        {
            count_sort(s, pos , n);   
        }
    }
};
int main()
{
    student sob[20];
    int no;
    cout<<"No. of Student :\n";
    cin>>no;
    for (int i = 0; i < no ; i++)
    {
        sob[i].read();
    }
    int choice;
   while (true)
   { 
     cout<<"\n Choice : ";
     cin>>choice;
    switch (choice)
    {
    case 1:
        insertion_sort(sob , no);
        for (int i = 0; i < no ; i++)
        {
            sob[i].display();
        }
        break;
    
    case 2:
        shell_sort(sob , no);
        for (int i = 0; i < no ; i++)
        {
            sob[i].display();
        }
        break;
        
        
    case 3:
        radix_sort(sob , no);
        for (int i = 0; i < no ; i++)
        {
            sob[i].display();
        }
        break;
        
    case 4:
        exit(0);
        break;
        
    default:
        break;
    }
   }
   return 0;
}