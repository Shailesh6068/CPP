#include<iostream>
#include<stack>
#include <algorithm> 
using namespace std;
int main()
{
    stack<string> output;
    string str;
    cout<<"Enter the String :";
    cin>>str; 
    reverse(str.begin() , str.end());
    for (int i = 0; i < str.size(); i++)
    {      
        if (isdigit(str[i]))
        {
            output.push(to_string(str[i] - '0'));          // str[i] - 0 == convert char to int.(Ascii of char - Asci of 0)
                                                           // to_string()  == convert into string
        }    
        else
        {
            string v1 = output.top();
            output.pop();
            string v2 = output.top();
            output.pop();
            string res = v1+v2+str[i];
            output.push(res);
        }                                           
    }
    cout<<"In Postfix :"<<output.top();

    return 0;
    


}