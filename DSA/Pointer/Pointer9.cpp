#include<iostream>
using namespace std;
int main()
{
    int arr[3] = {1,35,30};
    int *ptr = &arr[0];
    cout<<++*ptr<<"  "<<++*ptr<<"  "<<"\n";
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
    int *ptr3 = &arr[2];
    *ptr3 = 5;
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";

    return 0;
}