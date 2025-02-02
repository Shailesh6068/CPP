#include<iostream>
#include<stack>
using namespace std;
// 4 3 9 1 6 8 2
void next_greater_elem(int arr[],int n)
{
    int output[n]= {-1};
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                output[i] = arr[j];
                break;
            }       
        }
    }  
    cout<<"Answer :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<output[i]<<"   ";
    }
}
int main()
{
    int n;
    cout<<"Enetr the Size :";
    cin>>n;
    int arr[n];
    cout<<"Enter the array element :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    next_greater_elem(arr , n);
    return 0;
}