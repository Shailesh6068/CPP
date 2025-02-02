#include<iostream>
using namespace std;
template <class T>
class sample {
   // T x, y;
public:
    void sum(T x, T y); // Declaration of the sum method
};
// Definition of the sum method outside the class
template <class T>
void sample<T>::sum(T x, T y) {
    T q = x + y;
    cout << "The addition is: " << q << endl;
}

int main() {
    sample<float> s1, s2, s3;
    s1.sum(10, 5);
    s3.sum(10, 5);

    return 0;
}
