#include <iostream>
using namespace std;
class customer
{
    string name ,Day, Date;
    int Cu_ID ;
    int a,b,c;
    string q,w,e;
public:
    void input();
    void display();
    void shop();
  
};

void customer::input()
{
    cout << "Write the customer name: " << endl;
    cin>>name;
    cout << "Write the customer ID: " << endl;
    cin >> Cu_ID;
    cout << "Write the Date and Day :" << endl;
    cin >> Date>>Day;
} 
void customer::shop()
{
  
    
    cout << "Select item and Quantity of Drink : (Sprite /Fanta /coca-cola)" << endl;
    cin >> q;
    cin>>a;
    cout << "Select item and Quantity of Groceries: (Sugar/Tea powder/milk)" << endl;
    cin >> w;
    cin>>b;
    cout<<"Select Cosmetic item and Quantity (suncream/soap/haircream): "<<endl;
    cin>>e;
    cin>>c;
}

void customer::display()
{
    cout << "The customer name: " << endl;
    cout << name<<endl;
    cout << "The customer ID.:" << endl;
    cout << Cu_ID<<endl;
    cout << "The Date and Day : " << endl;
    cout <<Date<<Day<<endl;
    cout<<endl<<endl;
    cout<<q<<":"<<a<<endl;
    cout<<w<<":"<<b<<endl;
    cout<<e<<":"<<c<<endl;
    cout<<"The payable amount: "<<a+b+c<<endl;
    

}

int main()
{   customer c1;
    c1.input();
    
    int ch;

    string choice;
    
     cout<<"The choices number are as following: "<< endl;
     cout<<"1:For input customer name:"<<endl;
     cout<<"2:For show and selct item: " << endl;
     cout<<"3:For Display." << endl;

    do
    {
        cout << "Enter the choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            c1.input();
            break;

        case 2:
            c1.shop();
            break;

        case 3:
            c1.display();
            break;

        default:
            cout << "The choice selected by you is invalid.";
        }
        cout << "Do you wan't to continue again Yes/No:";
        cin >> choice;

    } while (choice == "Yes");

    return 0;
}