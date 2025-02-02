#include<iostream>
using namespace std;
int main()
{
    int arr[4];
    cout<<"Enter number:"<<endl;
    for (int i = 0; i < 7; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int *ptr3 = &arr[3];
    int *ptr4 = &arr[4];
    int *ptr5 = &arr[5];

    cout<<"&arr[3]: "<<&arr[3]<<"     &arr[4]: "<<&arr[4]<<"    &arr[5]: "<<&arr[5]<<"    &arr[6]: "<<&arr[6];
    
    return 0;
}