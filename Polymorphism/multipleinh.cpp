#include<iostream>
using namespace std;
class parent1
 {
        public:
         parent1()
         {
            cout<<"Parent1"<<endl;

         }
         void show()
         {
            cout<<"resolve the Ambiguity 1. "<<endl;
         }
 };
class parent2
{
        public:
         parent2()
          {
                cout<<"Parent2"<<endl;

          }
         void show()
         {
            cout<<"Resolve the ambiguity 2."<<endl;
         }
};
class child:public parent1,public parent2   // kiti  pan inherited karu shakto.
{
        public:
            child()
             {

                cout<<"Child"<<endl;
             }
}; 

int main()
{
   child c;
   c.parent1::show();  //if function name is same in differnt class.to call use them
   c.parent2::show();
    return 0;
}