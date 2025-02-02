// #include<iostream>
// #include<iomanip> 
// using namespace std; 
// int main()
// {   cout<<"Alexa"<<setw(9)<<"999"<<endl <<"Orio"<<setw(12)<<"12349"<<endl <<"Elsa"<<setw(13)<<"459860";    
//  return 0; 
// } 




// #include<iostream>
// using namespace std; int main()
// {      
//     float gallon;  
//     double cufeet;    
//     cout<<"Enter the value of gallon : ";    
//     cin>>gallon;      
//     cufeet = gallon/7.481;   
//     cout<<"The value in Cufeet :"<<cufeet;    
//     return 0; 
// } 

#include <iostream>
using namespace std;
int main() 
{
    int n, m, flag=0;
    cout<<"enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"enter numbers: ";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"enter the number that you want to search: ";
    cin>>m;
    for(int i=0; i<n; i++)
    {
        if(m == a[i])
        {
            cout<<"the number is found at position:"<<i+1;
            flag=1;
            exit(0);
        }
    }
    if(flag==0)
    {
        cout<<"number not found:";
    }
    return 0;
}
