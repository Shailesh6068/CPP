#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr[3];
    arr[0].push_back(12);
    arr[0].push_back(45);
    arr[1].push_back(32);
    arr[2].push_back(67);
    arr[2].push_back(43);
    arr[2].push_back(89);

    for(int i = 0; i < 3; i++)
    {for(int j = 0; j < arr[i].size(); j++)
    {
        cout<<arr[i][j]<<"  ";
    }
    cout<<endl;
    }
    
}