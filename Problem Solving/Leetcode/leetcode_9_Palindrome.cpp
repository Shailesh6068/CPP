#include <iostream>
#include <string>
using namespace std;
    bool isPalindrome(int x) {
        // Negative numbers आणि शेवटी 0 असलेले numbers palindrome नसतात (except 0)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reverse = 0;
        while (x > reverse) {                // here we use only one variable. Not Use another variable.
            int rem = x % 10;
            reverse = reverse * 10 + rem;
            x = x / 10;
        }
         
        //  cout<<reverse;
        //  cout<<x;
        // Even आणि odd digit संख्या दोन्हीसाठी योग्य चेक
        return (x == reverse) || (x == reverse / 10);
    }
int main() 
{ 
    int x;
    cout<<"Eneter X:";
    cin>>x;
    isPalindrome(x);
    
    return 0;
}
