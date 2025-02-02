#include<iostream>
using namespace std;
template <class T>
class node
{
    public:
    T val;
    node* next;
    node(T data)
    {
        val = data;
        next = nullptr;
    }
};
int main()
{
    node<int>* n1 = new node<int> (3);
    cout<<n1->val<<endl;
    
    node<char>* n2 = new node<char> ('a');
    cout<<n2->val;

    return 0;
}