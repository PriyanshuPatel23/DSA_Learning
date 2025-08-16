#include <bits/stdc++.h>
using namespace std;

void convertToWave(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i += 2) {
        if (i > 0 && arr[i] < arr[i - 1]) 
            swap(arr[i], arr[i - 1]);
        if (i < n - 1 && arr[i] < arr[i + 1]) 
            swap(arr[i], arr[i + 1]);
    }
}

int main() {
    vector<int> arr = {10, 90, 49, 2, 1, 5, 23};
    convertToWave(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
