#include <iostream>
#include <fstream>
using namespace std;
class MyClass {
public:
    int a;
    double b;

    void writeToFile(ofstream& fout) {
        fout.write((char*)this, sizeof(*this));
    }
};

int main() {
    MyClass obj;
    obj.a = 10;
    obj.b = 20.5;

    ofstream fout("ax.txt", ios::app);
    obj.writeToFile(fout);
    fout.close();

    string line;
    ifstream fin("ax.txt");   
    while(getline(fin, line))
    {
        cout<<line;
    }
    

    return 0;
}
