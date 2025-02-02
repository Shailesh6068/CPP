#include<iostream>
using namespace std;

class Parent
    {
        public:
         int x = 4;




        protected:
         int y = 7;

        private:
         int z = 6;




    };
class child1 : public Parent
    {  //x public
       //y protected
       //z inaccsesible
    };

class child2 : protected Parent
    {//x protected
     // y protected
     // z inaccsible
    };

class child3 : private Parent
    {//x private
     // y private
     // z inaccsible
    };  


int main()
    {
     
 
        return 0;

    }