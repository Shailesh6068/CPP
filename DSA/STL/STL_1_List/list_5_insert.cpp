#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l = {1,2,3,4};
    auto itr = l.begin();

    // inser at position
    l.insert(itr,5);                // insert element before the itr.
    for (auto it = l.begin(); it != l.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout<<endl;

    list<int> l1 = {1,2,3,4};
    auto itr1 = l1.begin();
    advance(itr1,2);
    l1.insert(itr1,  2,   5);        // insert value before the itr for "count" times
    //          (count) (value)
    for (auto it = l1.begin(); it != l1.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout<<endl;

    list<int> l2 = {1,2,3,4};
    auto itr2 = l2.begin();
    auto t = l2.begin();
    auto t2 = l2.begin();   
    advance(t2,2);               // t2 point 3
    l1.insert(itr2,  t,   t2);        // insert the value don vela parantu t2 chya aadhi (without t2 / before t2)
    //          (start ) (end )
    for (auto it = l2.begin(); it != l2.end(); ++it) 
    {
        cout << *it << " ";
    }


}