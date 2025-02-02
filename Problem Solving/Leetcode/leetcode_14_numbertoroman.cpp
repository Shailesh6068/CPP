#include<iostream>
using namespace std;
    int romanToInt(string s) {

        int len = s.size();
        int result = 0;

        for(int i = 0 ; i < len ; i++)
        {
            if(s[i] == 'I')
            {
                if(s[i+1] =='V')
                {
                    result += 4;
                    i++;
                }
                else if(s[i+1] =='X')
                {
                    result += 9;
                    i++;
                }
                else
                {
                    result = result+1;
                }
                
            }
            else if(s[i] =='V')
            {
                result = result+5;
            }
            else if(s[i] == 'X')
            {
                if(s[i+1] =='L')
                {
                    result += 40;
                    i++;
                }
                else if(s[i+1] =='C')
                {
                    result += 90;
                    i++;
                }
                else
                {
                    result = result+10;
                }
            }
            else if(s[i] == 'L')
            {
                result = result + 50;
            }
            else if(s[i] =='C')
            {
                if(s[i+1] =='D')
                {
                    result += 400;
                    i++;
                }
                else if(s[i+1] =='M')
                {
                    result+= 900;
                    i++;
                }
                else
                {
                    result = result+100;
                }
            }
            else if(s[i] =='D')
            {
                result = result + 500;
            }

            else if(s[i] =='M')
            {
                result = result + 1000;
                //cout<<result;
            }

        }

        return result;
    }
int main()
{
    string s;
    cout<<"String :";
    cin>>s;
    cout<<"\nAns :"<<romanToInt(s);
}