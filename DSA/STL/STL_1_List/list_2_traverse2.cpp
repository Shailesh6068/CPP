#include <iostream>
#include <list>
using namespace std;

int main() 
{
    list<int> l1 = {6,7,8,9};
    auto itr1 = l1.begin();
    
    // Print the elements of l1   
    // M1 :range-based loop
    for (auto num:l1)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    // M2 : Using Iterator
    for (auto itr = l1.begin() ; itr != l1.end() ; itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;

    // reverse traverse
    for(auto itr = l1.rbegin() ; itr != l1.rend() ; itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    
   



    return 0;
}
