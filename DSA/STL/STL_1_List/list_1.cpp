#include<iostream>
#include<list>
using namespace std;
int main()
{   
    // list<int> l1 = {6,7,8,9};
   // list<int>::iterator itr;  
    list<int> l = {1,2,3,4};         //
    auto itr1 = l.begin();            // if the datatype is known   .. store the adress of first element
    // l.end()              :-  iterator pointing to the memory location after 4
    cout<<"*itr1 :"<<*itr1<<endl;
   // cout<<*itr1+1;
    
    return 0;
}