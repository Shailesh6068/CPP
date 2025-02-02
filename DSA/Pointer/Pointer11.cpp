#include<iostream>
using namespace std;
int main()
{
    int arr[3] = {1,12,13};
    int (*ptr )[3] = &arr;      // total adress of array passed in ptr

    cout<<ptr<<"   "<<arr<<"\n";
    cout<<*ptr<<"  "<<*arr<<"\n";
    return 0;
}