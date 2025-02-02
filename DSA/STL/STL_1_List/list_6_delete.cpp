#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l = {1,2,3,4};
    auto itr = l.begin();
    l.erase(itr);                                    //  delete itr
    for (auto it = l.begin(); it != l.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout<<endl;


    list<int> l1 = {1,2,3,4,5,6};

    auto si_itr = l1.begin();
    advance(si_itr , 1);         // point 2 nd element

    auto ei_itr = l1.begin();
    advance(ei_itr,4);          // point 5 th element

    l1.erase(si_itr,ei_itr);                                   
    for (auto it = l1.begin(); it != l1.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout<<endl;


}