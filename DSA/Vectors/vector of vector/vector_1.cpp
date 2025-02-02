#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v;
    v.push_back({1, 2, 3});
    v.push_back({33, 56});
    v.push_back({90, 56, 3, 21});

    // for (int i = 0; i < v.size(); i++) {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //          cout<<v[i][j]<<" ";
    //     }    
    //     cout << endl;
    // }

    // or

    vector<int> :: iterator it;
    for(int i = 0; i < v.size(); i++)
    {   // vector<int> :: iterator it;         also run this
        for(it = v[i].begin() ; it != v[i].end() ; it++)
        {
            cout<<*it<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
