#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l = {1,2,3,4};
    auto itr = l.begin();
    cout<<*itr<<endl;

    advance(itr,2);
    cout<<*itr<<endl;           // move two places

}