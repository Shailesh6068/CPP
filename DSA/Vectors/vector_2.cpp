#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    // vector<int> v(5);     METHOD 2 it is nesescary
    int ele;
    for(int i = 0 ; i< 5;i++)
    {
        cin>>ele;
        v.push_back(ele);       
        //cin>>v[i];   Asa lihal tari chalel Pan varati size mention karayali lagati.Karan jar aapan size 
        //             jar aapn size varati mention nahi keli yacha arth index tyacha 0 Aah.tyamule V[i] meaningless Asate.
    }
// METHOD 2  For Input
    // for (int  i = 0; i < 5; i++)
    // {
    //     cin>>v[i];
    // }
    
// Method 1 For Read
    for (int  i = 0; i < v.size(); i++)
    {
       cout<<v[i]<<" ";
    }
    cout<<endl;

    v.insert(v.begin()+2,6);

// Method 2 , For each loop 
    cout<<"After Insert :"<<endl;
    for(int element:v)
    {
       cout<<element<<" ";
    }
    cout<<endl;
// Method 3, While loop
    v.erase(v.end()-2);
    cout<<"After Erase :"<<endl;
    int idx = 0;
    while(idx < v.size())
    {
        cout<<v[idx++]<<" ";
    }
    cout<<endl;
    return 0;
}