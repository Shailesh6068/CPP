#include<iostream>
using namespace std;
int main()
{
    int arr[3] = {42,14,52};
    int *ptr = &arr[0];
    cout<<arr<<" "<<arr+1<<" "<<arr+2<<"\n";          // adress of array

    int arr1[3] = {1,12,13};
    int (*ptrd )[3] = &arr1;      // total adress of array passed in ptr

    cout<<ptrd<<"   "<<arr1<<"\n";
    cout<<*ptrd<<"  "<<*arr1<<"\n";
    return 0;
}
