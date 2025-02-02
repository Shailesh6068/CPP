#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v(6);

    for(int i = 0 ; i<= 5;i++)
    {
        cin>>v[i];
    }

    int count = -1;
    int x;
    cout<<"Write X: ";
    cin>>x;

    for(int  i = 0; i <= v.size(); i++)
    {
       if(v[i] == x)
        {
            count = i;
        }
    }

    cout<<endl;
    cout<<"The Element is at position: "<<count;
    return 0;
    
}

