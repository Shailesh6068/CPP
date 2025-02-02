#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr[3];

    for (int i = 0; i < 3; i++)
    {
        int n;
        cout<<"How many numbers in "<<i+1<<" th row :";
        cin>>n;
        for (int j = 0; i < n; i++)
        {
            int a;
            cin>>a;
            arr[i].push_back(a);
        }
    }   
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
        
}
    
