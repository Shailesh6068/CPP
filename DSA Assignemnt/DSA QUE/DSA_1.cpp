#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Size: ";
    cin >> n;

    int score[n];
    int indices[n];

    // Input the scores
    for (int i = 0; i < n; i++) {
        cin >> score[i];
        indices[i] = i; // Store the original indices
    }

    // Insertion Sort with original indices
    for (int i = 1; i < n; i++) {
        int X = score[i];
        int originalIndex = indices[i];  // Store the original index
        int j = i - 1;
        
        // Move elements of score[] that are less than X
        while (j >= 0 && score[indices[j]] < X) {
            indices[j + 1] = indices[j];  // Move index to the right
            j--;
        }
        
        indices[j + 1] = originalIndex; // Place the original index at the correct position
    }

    // Create an array to store ranks
    string rank[n];
    
    // Assign ranks based on sorted order
    for (int i = 0; i < n; i++) {
        if (i == 0) rank[indices[i]] = "Gold Medal";
        else if (i == 1) rank[indices[i]] = "Silver Medal";
        else if (i == 2) rank[indices[i]] = "Bronze Medal";
        else rank[indices[i]] = to_string(i + 1); // For other ranks
    }

    // Output the ranks in the original order
    for (int i = 0; i < n; i++) {
        cout << rank[i] << endl;
    }

    return 0;
}
