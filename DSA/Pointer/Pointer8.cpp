#include<iostream>
using namespace std;
int main()
{
    int arr[3] = {1,35,30};
    int *ptr = &arr[0];

    // cout<<*++ptr<<"  "<<*++ptr<<"  "<<"\n";      sometimes it give differen value such as "30  35"    
    cout<<*++ptr<<"  ";                           //to solve this write seperate them
    cout<<*++ptr<<"  ";
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
    return 0;
}