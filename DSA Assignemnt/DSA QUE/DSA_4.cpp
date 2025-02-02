#include<iostream>
using namespace std;
string insertion_sort(string s)
{
    for (int  i = 1; i < s.length() ; i++)                           
    {
        int current_element = s[i];
        int j = i - 1;
        while (s[j] > current_element && j >= 0)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = current_element;        
    }

    return s;
}
int main()
{
    string s1,s2, s3,s4;
    cout<<"Enter S1 And S2 :";
    cin>>s1>>s2;
    s3 = insertion_sort(s1);
    s4 = insertion_sort(s2);
    cout<<s3<<" "<<s4<<endl;

    int i =0;
    int  j = 0;

    while(i < s3.length() && j <s4.length())
    {
        if (s3[i] != s4[j])
        {
           cout<<"Not Anagram\n";
           exit(0);
        }
        i++;
        j++;
    }
    cout<<"Anagram";

    return 0;
    


    
}