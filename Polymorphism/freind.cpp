#include <iostream>
using namespace std;
class sample
{
    int x;
    int y;

public:
    void input();
    friend int sum(sample);
};

void sample::input()
{
    cout << "Write the value of x and y: " << endl;
    cin >> x >> y;
}
int sum(sample s2)
{

    return (s2.x + s2.y);
}
int main()
{
    sample s1;
    s1.input();
    cout << sum(s1);

    return 0;
}
