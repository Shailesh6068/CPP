#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float d;
    double e;
    
    cout << "Enter a float and a double: ";
    cin >> d >> e; 

    // Without 'fixed'
    cout << "Without fixed:" << endl;
    cout << setprecision(3) << d << endl;   // Display float with 3 decimal places
    cout << setprecision(8) << e << endl;   // Display double with 8 decimal places
    
    // With 'fixed'
    cout << "With fixed:" << endl;
    cout << fixed << setprecision(3) << d << endl;   // Display float with 3 decimal places
    cout << fixed << setprecision(8) << e << endl;   // Display double with 8 decimal places
    
    return 0;
}
