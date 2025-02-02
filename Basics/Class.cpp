#include<iostream>
using namespace std;

class Fruits
{

public:
    string name;
    string colour;

    
    };
int main()
{
    Fruits apple;
    apple.name = "Apple";
    apple.colour = "Red";

    Fruits *mango = new Fruits();
    mango->name = " Mango ";
    mango->colour = "Yellow";


    
cout<<apple.name<<" <<--->> "<<apple.colour<<endl;
cout<<mango->name<<" <<-->> "<<mango->colour;
}