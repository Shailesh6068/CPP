#include<iostream>
using namespace std;
template <class T,class Z>
class sample
{   T x;
    Z y;
    public:
    void sum(T x, T y)
    {
        T q = x + y;
        cout << "The addition is: " << q << endl;
    }
    void show(T x,T y);

};
// Definition of the show method outside the class
 template <class T,class Z>
 void sample<T , Z> ::show(T x,T y)
 {
     cout << "X is: " << x << endl << "Y is: " << y << endl;
}
int main()
{
    sample <float,int > s1, s2,s3;
    s1.sum(10, 5);
    s3.sum(10, 5);

    return 0;
}