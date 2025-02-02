#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& v, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1; // Start of the right half
    while (left <= mid && right <= high)
    {
        if (v[left] <= v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }
     
    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }
    
    while (right <= high)
    {
        temp.push_back(v[right]);
        right++;
    }

    
    for (int i = low; i <= high; i++)
    {
        v[i] = temp[i - low];
    }
}
void mergeSort(vector<int>& v, int low, int high)   // when we pass &v then it is pass as referrencce and 
{                                                   //change made in vector automaticaly udate to the old vector
    if (low >= high)
    { 
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
   // cout<<"Zatua :"<<endl;
}
int main()
{   
    int n;
    vector<int> v;
    cout << "Enter the size: ";
    cin >> n;

    v.resize(n); // Resize the vector to hold n elements

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    mergeSort(v, 0, n - 1); // Correct range for mergeSort
    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
