#include<iostream>
using namespace std;

class rectangle{
public:
int l ;
int b ;          //name of constructor same as classroom

 rectangle()    //Default consrtuctor :- no arguments pass.
 { 
    l = 8;
    b = 6;
 }

 rectangle(int x , int y)
 {
   l = x;     //parameterized constructor
   b = y;


 }

 rectangle(rectangle& r)  //copy cosnstructor
    {
        l = r.l;
        b =r.b;
      

    }

  ~rectangle()
    {

        cout<<"I am a Destructor"<<endl; //Destructor function.

    }
 

};
int main()
{

rectangle r1;
cout<<r1.l<<" "<<r1.b<<endl;



rectangle r2(5,6);
cout<<r2.l<<" "<<r2.b<<endl;

rectangle r3(r2);
cout<<r3.l<<" "<<r3.b<<endl;

rectangle *r4 =new rectangle(); //rectangle* r4 =new rectangle(); donhi barobar aahe.
cout<<r4->l<<" "<<r4->b<<endl;
delete r4;


}
