#include<iostream>
using namespace std;

// Function to partition the array with middle element as pivot
int partition(int arr[], int first, int last) {
    int middle = first + (last - first) / 2; // Find the middle index
    int pivot = arr[middle];  // Choose middle element as pivot

    // Swap the middle element with the last element
    swap(arr[middle], arr[last]);

    int i = first - 1;  // Position of the smaller element
    int j = first;      // Start from the first element

    for (; j < last; j++) {
        if (arr[j] < pivot) {  // If the element is less than the pivot
            i++;
            swap(arr[i], arr[j]);  // Swap elements
        }
    }
    swap(arr[i + 1], arr[last]);  // Place the pivot at its correct position
    return i + 1;  // Return the index of the pivot
}

// Function to perform QuickSort
void QuickSort(int arr[], int first, int last) {
    if (first >= last) {
        return;  // Base case: if the array has one or no elements
    }

    int pi = partition(arr, first, last);  // Get the pivot index
    QuickSort(arr, first, pi - 1);  // Sort the left part
    QuickSort(arr, pi + 1, last);   // Sort the right part
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int arr[n];  // Declare the array

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "----------- Sorted Array -----------" << endl;
    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
