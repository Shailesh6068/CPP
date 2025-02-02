#include <iostream>
using namespace std;

// Function to sort the array based on frequency and value using Insertion Sort
void sortByFrequency(int arr[], int n) {
    int freq[1000] = {0};  // Frequency array (assuming the elements are in the range 0 to 999)
    
    // Step 1: Count the frequency of each element
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Step 2: Perform Insertion Sort based on frequency and value
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than the key (according to sorting rules)
        // to one position ahead of their current position
        while (j >= 0 && (freq[arr[j]] >freq[key] || (freq[arr[j]] == freq[key] && arr[j] < key))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Main function to test the sorting
int main() {
    int arr[] = {4, 3, 3, 2, 1, 4, 4, 2, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortByFrequency(arr, n);

    cout << "Sorted array by frequency: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
