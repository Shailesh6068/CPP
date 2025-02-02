#include<iostream>
using namespace std;
class employe
{
int emp_id , age,DA,HRA,count;
float salary;
long long int ph;
string name ,Depart;

public:
void getdata();
void putdata();
int excepion();
};
void employe::getdata()
{
    cout<<"Enter the information of Employe : "<<endl<<endl;
    cout<<"Name :"<<endl;
    cin>>name;
    cout<<"Employe ID :"<<endl;
    cin>>emp_id;
    cout<<"Departement :"<<endl;
    cin>>Depart;
    cout<<"Age :"<<endl;
    cin>>age;
    cout<<"Phone Number :"<<endl;
    cin>>ph;
    cout<<"DA and HRA :"<<endl;
    cin>>DA>>HRA;
}
int employe::excepion()
{   
    count = 0;
    long long int temp = ph;
     while(temp > 0)
    {
        temp = temp/10;
        count++;
    }
    
    if (count != 10)
    {    
        try
        {
            if (count > 10 )
            {
            throw(0);
            }
            if (count < 10)
            {
                throw('a');
            }
        }
        catch(int x)
        {
            cout<<"Error : The Number of Digits in Phone Numbers is greater than 10.";
            exit(0);
        }
        catch(char y)
        {
            cout<<"Error : The Numbers of Digits in Phone Number is less than 10.";
            exit(0);
        }
    }
    else return ph;
   
}
void employe::putdata()
{
    cout<<"Enter the information of Employe : "<<endl<<endl;
    cout<<"Name :"<<endl;
    cout<<name<<endl;
    cout<<"Employe ID :"<<endl;
    cout<<emp_id<<endl;
    cout<<"Departement :"<<endl;
    cout<<Depart<<endl;
    cout<<"Age :"<<endl;
    cout<<age<<endl;
    cout<<"Phone Number :"<<endl;  
    cout<<excepion()<<endl;
    salary = DA + HRA;
    cout<<"Salary :"<<endl;
    cout<<salary<<endl;
}
int main()
{
employe e1;
e1.getdata();
e1.putdata();

return 0;
}