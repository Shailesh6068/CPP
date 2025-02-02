#include<iostream>
using namespace std;
template <class T,class Z>
class sample
{   T x;
    Z y;
    public:
    int data;
    sample(int val)
    {
        data = val;
    }
    void sum(T x, T y)
    {
        T q = x + y;
        cout << "The addition is: " << q << endl;
    }

};
int main()
{
    sample<int,float>* s1 = new sample<int,float> (5);
    s1->sum(4,5);
    cout<<s1->data;


    return 0;
}