#include<iostream>
#include<fstream>
using namespace std;
int main()
{   
    ofstream A;
    A.open("First.txt");
    if(!A)
    {
        cout<<"The file is not exist."<<endl;
    }
    else
    {
        A<<"The data is not for you.\n this is for the write the data.";
    }
    A.close();

    ifstream R;
    R.open("First.txt");
    ofstream copy1;
    copy1.open("copy1.txt");
    string ch;
    while(!R.eof())
    {
        R.getline(ch);
        copy1.put(ch);

    }
    
    return 0;

}