#include<iostream>
using namespace std;
int stairpath(int n)
{
    if(n==1){return 1;}
    if(n==2){return 2;}
    int totalway = stairpath(n-1) + stairpath(n-2);
    return totalway;
}
int main()
{
    int n;
    cout<<"Enter the number of stairs :";
    cin>>n;
    int total_path = stairpath(n);
    cout<<"Total number of Ways :"<<total_path;

}