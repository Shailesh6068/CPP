#include<iostream>
#include<vector>
using namespace std;
int main()
{
        vector<int> arr = {12,35, 1, 10, 34, 1};
        
        int max = -1;
        int secondmax = -1;

        if(arr.size() == 1)
        {
            cout<<-1;
        }
        else
        {
            for(int i = 0 ; i < arr.size() ; i++)
            {
                if(max < arr[i])
                {
                    secondmax = max;
                    max = arr[i];
                }
                cout<<endl<<max<<endl;
            }
        }
        
        if(max == secondmax)
        {
            cout<<-1;
        }
        else
        {
            cout<<secondmax;
        }
}
