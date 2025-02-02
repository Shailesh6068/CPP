#include <iostream>
#include <climits>
using namespace std;

void countsort(int arr[], int n, int pos) {
    const int base = 10;
    int freq[base] = {0};  // Initialize frequency array with zeros

    // Count occurrences
    for (int i = 0; i < n; i++) {
        freq[(arr[i] / pos) % base]++;
    }

    // Compute cumulative frequency
    for (int i = 1; i < base; i++) {
        freq[i] += freq[i - 1];
    }

    // Place elements in sorted order
    int* ans = new int[n];  // Dynamically allocate memory for the sorted array
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(arr[i] / pos) % base]] = arr[i];
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }

    delete[] ans;  // Free the dynamically allocated memory
}

void radixsort(int arr[], int n) {
    if (n <= 0) return;

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Perform counting sort for each digit
    for (int pos = 1; max / pos > 0; pos *= 10) {
        countsort(arr, n, pos);
    }
}

int main() {
    int n;
    cout << "How many numbers: ";
    cin >> n;
    if (n <= 0) {
        cout << "The array size must be positive." << endl;
        return 1;
    }

    int* arr = new int[n];  // Dynamically allocate memory for the array
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The numbers you entered: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixsort(arr, n);

    cout << "The numbers after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Free the dynamically allocated memory

    return 0;
}
