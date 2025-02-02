#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int nums[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Insertion Sort in descending order
    for (int i = 1; i < n; i++) {
        int temp = nums[i];
        int j = i - 1;

        // Move elements of nums[] that are smaller than temp to the right
        while (j >= 0 && nums[j] < temp) {
            nums[j + 1] = nums[j];
            j--;
        }

        // Place the current element in its correct position
        nums[j + 1] = temp;
    }

    // Find the third distinct maximum
    int distinctCount = 1; // The first number is the first distinct maximum
    int thirdMax = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {  // Check if it's a distinct number
            distinctCount++;
            if (distinctCount == 3) {
                thirdMax = nums[i];
                break;
            }
        }
    }

    // If we don't find a third distinct maximum, return the maximum number
    if (distinctCount < 3) {
        thirdMax = nums[0];
    }

    cout << "The third distinct maximum number is: " << thirdMax << endl;

    return 0;
}
