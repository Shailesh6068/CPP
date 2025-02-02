#include<iostream>
using namespace std;

class employe {
public:
    string employe_name, emp_id;
    int salary, age;

    void input() {
        cout << "Write the name of employe: " << endl;
        cin >> employe_name;
        cout << "Write employe ID: " << endl;
        cin >> emp_id;
        cout << "Write the salary: " << endl;
        cin >> salary;
        cout << "Write the age: " << endl;
        cin >> age;
    }

    void output() {
        cout << "The name of employe: " << endl;
        cout << employe_name << endl;
        cout << "The employe ID: " << endl;
        cout << emp_id << endl;
        cout << "The salary is: " << endl;
        cout << salary << endl;
        cout << "The age is: " << endl;
        cout << age << endl;
    }
};

int main() {
    int Q;

    cout << "Write the number of employe: " << endl;
    cin >> Q;

    employe s[Q]; // Use an array of employe objects

    for (int i = 0; i < Q; i++) {
        s[i].input();
        s[i].output();
    }

    return 0;
}
