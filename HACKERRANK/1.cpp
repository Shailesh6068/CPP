#include <iostream>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr[i]=new int[k];
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    } 
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<arr[l][r]<<endl;
        
    }
    return 0;
}