#include<iostream>
using namespace std;
int main()
{
    string name;
    int roll_no;
    float sgpa;
    
    cout << "Enter the name: ";
    cin.ignore(); // मागील इनपुटमधून उरलेले न्यूलाइन कॅरक्टर साफ करा
    getline(cin, name); // नावासाठी पूर्ण ओळ वाचा, स्पेससह
    cout << "Roll No: ";
    cin >> roll_no;
    cout << "Enter the sgpa: ";
    cin >> sgpa;
}
