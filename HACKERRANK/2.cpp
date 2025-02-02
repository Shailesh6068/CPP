#include <iostream>
#include <sstream>
using namespace std;

class Student { 
public:
    int age, standard;
    string first_name, last_name;

    void set_age(int age1) {
        age = age1;
    }

    void set_standard(int standard1) {
        standard = standard1;
    }

    void set_first_name(string first) {
        first_name = first;
    }

    void set_last_name(string last) {
        last_name = last;
    }

    int get_age() {
        return age;
    }

    string get_last_name() {
        return last_name;
    }

    string get_first_name() {
        return first_name;
    }

    int get_standard() {
        return standard;
    }

    string to_string() {
        // Correcting the string formatting
        stringstream s;
        s << age << "," << first_name << "," << last_name << "," << standard;
        return s.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
