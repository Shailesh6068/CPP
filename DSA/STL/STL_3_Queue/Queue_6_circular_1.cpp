#include<iostream>
using namespace std;
int main()
{
    int ts = 5;
    for(int i = 0; i < 5; i++)
    {
        int back = (back+1)%ts;
        cout<<back<<"  ";
    }
    return 0;
}