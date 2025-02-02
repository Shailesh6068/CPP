// here we See the Use of Const keyword :
// 1 ) Use Const :( Read Only Mode)
//               he apalyala phak read or vaparata yete pan tyat kahi badal hot nahi.
// 2 ) Without Const : 
//               yat function madhye jar value madhye badal kela tar tyacha badal original valuet disun yeto
//
// khalil code madhye vector as refference pathavayachi garaj nahi phakt index s cha
// pathavava lagato.
#include<iostream>
#include<vector>
using namespace std;
void printVectorConst(const vector<int>& v) {
    for (int i : v) {
        cout << i << " "; // फक्त वाचत आहे.
    }
    // v[0] = 10; // Error! कारण `v` ला बदलता येत नाही.
}
void printVector(vector<int> &V2)
{
    V2[0] = 50;
}
int main()
{
    vector<int> v = {1,2,3,4,5,6,7};
    vector<int> v2 = {11,12,13,14,15,16};

    printVectorConst(v);
    printVector(v2);
    cout<<endl;

    for (int i = 0; i < v2.size(); i++)
    {
        cout<<v2[i]<<" ";   
    }
}