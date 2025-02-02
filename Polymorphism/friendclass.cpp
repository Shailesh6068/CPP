#include<iostream>
using namespace std;
class B;
class A
{   
    int x = 5;
    int y = 6;
    public:
    void output(B w);
    void subtract(B m);           //khalil class che member use kel tar he function chi mahiti aat lihayachi nasate ti baher lihavi lagate. 
    friend class B;                       

};
class B
{   
    int res;
    int z = 7;

    public:

    friend class A; 

    void sum(A q)
    {
        res = q.x + q.y +z;
        cout<<"Addition of three term : "<<res<<endl; 
    }

};
void A::output(B w)
{
    cout << "Result accessed from A: " << w.res << endl;
}
void A::subtract(B m)
{
    {
        cout<<"Substraction : "<< x - y - m.z;
    }

}
int main()
{
   A a1;
   B b1;
   b1.sum(a1);
   a1.output(b1);
    a1.subtract(b1);

   return 0;
}