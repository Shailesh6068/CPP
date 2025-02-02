#include<iostream>
using namespace std;
class sample2;
class sample1
{
    int x = 15;
    string z = "Ram";

    public:
    friend void swap(sample1, sample2);

};

class sample2
{
    int c = 45;
    string v ="Shailesh";

    public:
    friend void swap(sample1 , sample2);


};
void swap(sample1 s1, sample2 s2)
{
    int temp = s1.x;
    s1.x = s2.c;
    s2.c = temp;

    cout<<s1.x<<" "<<s2.c<<endl;


    string temp1 = s1.z;
    s1.z = s2.v;
    s2.v = temp1;

    cout<<s1.z<<" "<<s2.v<<endl;




}
int main()
{
    sample1 s1;
    sample2 s2;

    swap(s1,s2);


    return 0;



}


