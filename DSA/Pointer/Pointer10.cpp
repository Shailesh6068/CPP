#include<iostream>
using namespace std;
int main()
{
    int arr[5] = {1,35,30,40,50};
    int *ptr = &arr[2];

    cout<<*ptr<<"\n";
    *ptr++;
    cout<<*ptr<<"\n";
    return 0;
}