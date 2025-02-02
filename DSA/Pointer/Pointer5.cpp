#include<iostream>
using namespace std;
void find(string s,char ch ,int *first ,int *last)
{
    for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == ch)
            {
                *first = i;
                break;
            }
        }
    
    for(int i = s.size() ; i > 0  ; i--)
        {
            if(s[i] == ch)
            {
                *last = i;
                break;
            }
        }
}
int main()
{
    string s = "aabcdan";
    int first = -1;
    int last = -1;
    char ch = 'a';

    cout<<"s[0] : "<<s[0]<<"    s[2] :"<<s[2]<<endl;
    int *fi = &first;
    int *la = &last;
    //cout<<"fi :"<<fi<<"  "<<"la :"<<la;
    for(int i = 0 ; i < s.size() ; i++)
        {
        cout<<s[i];
        }
    
    cout<<endl;

    find(s,ch,fi,la);
    cout<<"The first position :"<<*fi<<endl;
    cout<<"The last position :"<<*la<<endl;

}