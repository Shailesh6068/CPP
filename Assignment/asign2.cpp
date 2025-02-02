// #include <iostream>
// using namespace std;
// int main()
//  {
//     int n,r,sum=0;
//     cout<<"enter the number: ";
//     cin>>n;
//     while(n!=0)
//     {
//         r=n%10;
//         sum=sum+r;
//         n=n/10;
//     }
//     cout<<"sum of digits of given number is:"<<sum;
//     return 0;
// }

#include <iostream>
using namespace std;
int main() {
    int n1, n2, n3, n;
    n1=0; n2=1;
    cout<<"how many terms do you want to generate?: ";
    cin>>n;
    cout<<"The fibonacci series is :";
    cout<<n1<<" "<<n2<<" ";
    for(int i=3; i<=n; i++){
        n3=n1+n2;
        cout<<n3<<" ";
        n1=n2;
        n2=n3;
    }
    return 0;
}