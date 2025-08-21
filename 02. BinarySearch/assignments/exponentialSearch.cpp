#include <iostream>
#include <algorithm> // for min()
using namespace std;

// Standard Binary Search
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;  // found

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

// Exponential Search
int exponentialSearch(int arr[], int n, int x) {
    // Check first element
    if (arr[0] == x)
        return 0;

    // Find range by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    // Call binary search in the found range
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = exponentialSearch(arr, n, x);

    if (result == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index " << result << "\n";

    return 0;
}
