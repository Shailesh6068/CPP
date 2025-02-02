#include<iostream>
using namespace std;
void process(int *arr , int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<*(arr+i)<<"  ";
    }
    cout<<endl;
    // OR 

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    int arr[3] = {12,3,5};
    process(arr,3);
    return 0;

}