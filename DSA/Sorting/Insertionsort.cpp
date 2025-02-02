#include<iostream>
using namespace std;
int main()
{
    // int arr[10];
    int n;
    cout<<"How many Number :"<<endl;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
                                                                                                                  
    cout<<"The numbers written by you :"<<endl;
    for(int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    for (int  i = 1; i < n; i++)                           
    {
        int current_element = arr[i];
        int j = i - 1;
        while (arr[j] > current_element && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current_element;        
    }
     
    cout<<endl;
    cout<<"The numbers sorted by you :"<<endl;
    for(int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }    
}