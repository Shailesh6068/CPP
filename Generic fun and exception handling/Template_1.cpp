#include<iostream>
using namespace std;
class sample
{   public:
    template <class T>
    void sum(T x, T y)
    {
        T z = x + y;
        cout << "The addition is: " << z << endl;
    }
    template <class T>
    void show(T x, T y); // Declaration of the show method
};
// Definition of the show method outside the class
template <class T>
void sample::show(T x, T y)
{
    cout << "X is: " << x << endl << "Y is: " << y << endl;
}
int main()
{
    sample s1, s2;
    s1.sum(10, 5);
    s2.sum(13.3, 5.5);
    s1.show(4, 5);
    s1.show(10.5, 5.2); // Added a semicolon here
    return 0;
}