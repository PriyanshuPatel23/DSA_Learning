#include <bits/stdc++.h>
using namespace std;

// Function to perform standard binary search
int binarySearch(vector<int>& arr, int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // not found
}

// Function to search in an unknown sized array
int unboundedBinarySearch(vector<int>& arr, int x) {
    // Start with range [0,1]
    int low = 0, high = 1;

    // Expand range exponentially until we go beyond x
    while (high < arr.size() && arr[high] < x) {
        low = high;
        high = high * 2;
        if (high >= arr.size()) high = arr.size() - 1; // safeguard
    }

    // Now do binary search in the found range
    return binarySearch(arr, low, high, x);
}

int main() {
    vector<int> arr = {1, 3, 7, 15, 30, 45, 60, 90, 120, 200};
    int target = 90;

    int result = unboundedBinarySearch(arr, target);

    if (result != -1) 
        cout << "Element found at index " << result << endl;
    else 
        cout << "Element not found" << endl;

    return 0;
}
