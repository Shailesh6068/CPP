#include<iostream>
using namespace std;
int main()
{
    int arr[2] = {1 , 20};
    int *ptr = &arr[0];

    cout<<ptr<<" "<<*ptr<<'\n';                                             // 0x61ff04     1
    cout<<"ptr+1 :"<<ptr+1<<"       *(ptr+1) :"<<*(ptr+1)<<"\n";            // ptr+1 :0x61fef8      *(ptr+1) :20
    cout<<"*ptr+1 :"<<*ptr+1<<"\n";                                         // *ptr+1 :2
    cout<<"arr[0] :"<<arr[0]<<" "<<"            arr[1] :"<<arr[1]<<"\n";    // arr[0] :1            arr[1] :20
    cout<<"*ptr++ :"<<*ptr++<<"             ptr after++ :"<<*ptr<<"\n";      // *ptr++ :1             ptr after++ :20
    cout<<"ptr :"<<ptr<<" "<<"       *ptr :"<<*ptr<<"\n";                   // ptr :0x61fef8        *ptr :20
    cout<<"(*ptr)++ :"<<(*ptr)++<<"\n";                                     // (*ptr)++ :20        increase in value
    cout<<ptr<<" "<<*ptr<<'\n';                                             // 0x61fef8 21     
    
    return 0;
}