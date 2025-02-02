#include<iostream>
#include<climits>
using namespace std;
void countsort(int arr[] ,int n , int pos)
{
    int freq[10] = {0};
    for(int i = 0; i < n; i++)
    {
        freq[(arr[i]/pos)%10]++;
    }
    
    for(int i = 1; i < 10; i++)
    {
        freq[i] += freq[i-1];
    }
    
    int ans[n];
    for(int i = n-1 ; i >= 0; i--)
    {
        ans[--freq[(arr[i]/pos)%10]] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }

    //cout<<endl;

    // cout<<"The numbers after sorted :"<<endl;
    // for(int  i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
}
void radixsort(int arr[] ,int n)
{
    int max = INT_MIN;
    for(int i = 0 ; i< n ; i++)
    {
        if( arr[i] > max )
        {
            max = arr[i];
        }
    }

    for(int pos = 1; max/pos > 0 ;pos *= 10)
    {
        countsort( arr , n,pos );    
    }
}
int main()
{
    int n;

    cout<<"How many Number :"<<endl;
    cin>>n;

    cout<<"Enter the number:"<<endl;

    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // cout<<"The numbers written by you :"<<endl;
    // for(int  i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    radixsort(arr , n);

    cout<<"The numbers after sorted :"<<endl;
    for(int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}