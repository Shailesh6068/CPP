#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nge(int arr[],int n)
{
    vector<int> output(n,-1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[i] > arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    // for (int i = 0; i < n; i++)
    // {
    //    cout<<output[i]<<" ";
    // }
    return output;
}
int main()
{
    int n;
    cout<<"Enter the size :";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    //cout<<endl;
    vector<int> res;
    res = nge(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}