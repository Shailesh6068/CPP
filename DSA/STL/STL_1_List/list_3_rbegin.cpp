#include<iostream>
#include<list>
using namespace std;
int main()
{   
    list<int> l = {1,2,3,4};         
    auto itr1 = l.rbegin();            // reverse and first element
    cout<<"*itr1 :"<<*itr1<<endl;
    // list<int> l = {1,2,3,4};         
    // auto itr1 = l.rend();            // reverse and last element
    // cout<<"*itr1 :"<<*itr1<<endl;
    
    
    return 0;
}