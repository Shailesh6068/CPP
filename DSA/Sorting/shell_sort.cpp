#include<iostream>
using namespace std;
void shell_sort(int arr1[] , int n)
{
    for (int gap = n / 2 ; gap >= 1 ; gap =gap/2)
    {
        for (int i = gap ; i < n ; i++)
        {
            int current_ele =arr1[i];
            int j = i - gap;
            while (j >= 0 && arr1[j] > current_ele)
            {
                arr1[j + gap] = arr1[j];
                j =j-gap;           
            }
            arr1[j+gap] = current_ele;
        }   
    }

    // int arr[n];
    // for (int i = 0; i < n ; i++)
    // {
    //    // cout <<arr1[i]<<' ';
    //     arr[i] = arr1[i];
    // }
}
int main()
{
    int n;
    cout<<"Enter the size of numbers :"<<endl;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    shell_sort(arr , n);
    cout<<'\n'<<"The number after sorted :"<<'\n';
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}