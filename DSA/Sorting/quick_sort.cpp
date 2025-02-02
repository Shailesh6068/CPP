#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &v,int first,int last)
{
    int i = first - 1;  // store the element less than the pivot
    int j = first;      // use to compare element to the pivote element
    int pivote = v[last];   
    for(; j < last ; j++)
    {
        if(v[j] < pivote)       //element is less than the pivote element
        {
            i++;                
            swap(v[i],v[j]);   // swap the element is less than the pivote element                          
        }
    } 
    swap(v[i+1],v[last]);       // i show the index number of element is less than the pivote element after that swap
    return i+1;                 // give the position of pivote element
}
void QuickSort(vector<int> &s,int first,int last)
{
    if (first >= last)
    {
        return;
    }
  
    int pi = partition(s,first,last);  
    QuickSort(s,first,pi-1);
    QuickSort(s,pi+1,last);
  //  cout<<"\n AAAAAAAA \n";
}
int main()
{
    int n;
    int q;
    vector<int> v;
    cout<<"Enter the size :";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
       cin>>q;
       v.push_back(q);
    }
    cout<<"----------- Sorted Array -----------"<<endl;
    QuickSort(v,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}