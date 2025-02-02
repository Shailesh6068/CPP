#include<iostream>
#include<deque>
using namespace std;
void display(deque<int> de)
{  
    while(!de.empty())
    { 
        cout<<de.front()<<"  ";
        de.pop_front();
    }
    cout<<endl;
    
}
// METHOD 2 :(for print)
// void display(const deque<int>& de) {
//     // Create a copy to avoid modifying the original deque
//     deque<int> copy = de;

//     if (copy.empty()) {
//         cout << "Deque is empty." << endl;
//         return;
//     }

//     while (!copy.empty()) {
//         cout << copy.front() << "  ";
//         copy.pop_front();
//     }
//     cout << endl;
// }
int main()
{
    deque<int> de;
    de.push_back(1);
    de.push_back(2);
    de.push_front(3);
    de.push_back(4);
    display(de);
    de.pop_back();
    display(de);
    de.pop_front();
}