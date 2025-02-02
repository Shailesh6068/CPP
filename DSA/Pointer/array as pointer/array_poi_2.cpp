#include<iostream>
using namespace std;
int main()
{
    int arr[3] = {42,14,52};
    int *ptr = &arr[0];
    cout<<*(arr+1)<<" "<<*(arr+2)<<" "<<*(arr+3); // here address of array are present in the arr the arr act as 
    return 0;                                     // pointer therefore all operation of pointer are applicable on arr
}