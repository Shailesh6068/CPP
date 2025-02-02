#include<iostream>
#include <climits> 
using namespace std;
void countsort(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if( arr[i] >= max)
        {
            max = arr[i];
        } 
    }

    int freq[max+1 ] = {0};
    for (int i = 0 ; i < n; i++)
    {
        freq[arr[i]]++;           //   0 1 2 3 4 
    }

    // cout<<endl;
    // for (int i = 0 ; i < max+1 ; i++)
    // {   
    //     cout<<i <<" :";
    //     cout<<freq[i]<<endl; 
    // }

    for (int i = 1 ; i <= max ; i++)
    {
        freq[i] += freq[i-1];
    }

    // cout<<endl;
    // for (int i = 0 ; i < max+1 ; i++)
    // {   
    //     cout<<i <<" :";
    //     cout<<freq[i]<<endl;
    // }

    int arr1[n];
    for (int i = n-1; i >= 0 ; i--)
    {
        arr1[--freq[arr[i]]] = arr[i]; 
    }

    cout<<endl;
    cout<<"The array sorted is:"<<endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
        cout<<arr[i]<<" ";
    }
}
int main()
{
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

    countsort(arr , n);
    
}