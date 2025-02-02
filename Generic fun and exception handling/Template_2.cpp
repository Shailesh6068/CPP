#include<iostream>
using namespace std;
class sample
{   public:
    template <class T,class Z>
    void sum(T x, Z y)
    {
        T q = x + y;
        cout << "The addition is: " << q << endl;
    }
    template <class T,class Z>
    void show(T x, Z y); // Declaration of the show method
};
// Definition of the show method outside the class
template <class T,class Z>
void sample::show(T x,Z y)
{
    cout << "X is: " << x << endl << "Y is: " << y << endl;
}
int main()
{
    sample s1, s2,s3;
    s1.sum(10.5, 5.);
    s3.sum(10, 5.6);
    s2.sum(13, 5);
    s1.show(4, 5);
    s1.show(10.5, 5.2); // Added a semicolon here
    return 0;
}