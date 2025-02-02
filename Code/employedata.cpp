#include<iostream>
using namespace std;
class employe
    {                                                                 
   

        public:

        string employe_name , emp_id ;
        int salary , age;

            void input()
                { 
                    cout<<"Write the name of employe: "<<endl;
                    cin>>employe_name;
                    cout<<"Write employe ID.:"<<endl;
                    cin>>emp_id;
                    cout<<"Write the salary: "<<endl;
                    cin>>salary;
                    cout<<"Write the age: "<<endl;
                    cin>>age;

                }
            
            void output()
                {
                    cout<<"The name of employe : "<<endl;
                    cout<<employe_name<<endl;
                    cout<<"The employe ID.:"<<endl;
                    cout<<emp_id<<endl;
                    cout<<"The salary is : "<<endl;
                    cout<<salary<<endl;
                    cout<<"The age is : "<<endl;
                    cout<<age<<endl;


                }    

            employe()
                {
                    employe_name = "Shailesh";
                    emp_id = 230;
                    salary = 95000;
                    age = 19;


                }
            
            employe(employe& r)
            {   employe_name = r.employe_name;
                emp_id = r.emp_id;
                salary = r.salary;
                age = r.age;


            }

            ~employe()
                {
                    cout<<"this is destructor: "<<endl;
                }
        
            
    };
int main()
    { 
        employe s1,s2;
        s1.input();
        s1.output();
        s2.output();

        employe s3(s2);
        s3.output();
        
        cout<<s1.emp_id; //this is another method of calling the value from class.
        return 0;

    }