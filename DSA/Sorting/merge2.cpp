#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high) 
{
    
    int size = high - low + 1;
    cout<<"You are in merge loop :SIZE :"<<size<<"  mid:"<<mid<<"   high:"<<high<<" low:"<<low<<endl;
    int* temp = new int[size]; // Dynamically allocate memory for temp array

    int left = low;
    int right = mid + 1;
    int i = 0;

    // Merge the two halves into temp[]
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
             temp[i++] = arr[left++];
        } else {
            temp[i++] = arr[right++];
        }
    }

    // Copy remaining elements from the left half, if any
    while (left <= mid) {
        temp[i++] = arr[left++];
    }

    // Copy remaining elements from the right half, if any
    while (right <= high) {
        temp[i++] = arr[right++];
    }

    // Copy sorted elements from temp[] back to arr[]
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
        cout<<arr[i]<<" ";
    }
    cout<<endl;

   delete[] temp; // Free the dynamically allocated memory
}
void mergeSort(int arr[], int low, int high) 
{
    if (low < high) { // Fix condition to ensure proper division
        int mid = low + (high - low) / 2;
        cout<<"mid :"<<mid<<"   low :"<<low<<"   high :"<<high<<endl;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main() 
{
    int arr[] = {10, 28, 24, 6, 3,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
