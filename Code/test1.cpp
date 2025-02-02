#include<iostream>
#include<fstream>
using namespace std;
int main()
{   
    char arr[10];
    char p;
    ifstream fin("file.txt");
    int i = 0;
    while(!fin.eof())
    {   
        p = fin.get();
        //cout<<p;
        arr[i] = p;
        i++;
    }
    for ( i = 0; i < 10; i++)
    {
        cout<<arr[i];
    }
    fin.seekg(0,ios::beg);
    fin.close();
    char brr[] = {'a','j','a','y',' ', ' ',' ',' ',' ',' '};
    ofstream fout("file.txt");
    for( i = 0; i < 10; i++)
    {
        fout<<brr[i];
    }
    

    return 0;
}