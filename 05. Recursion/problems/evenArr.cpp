#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void solve(int arr[], int size, int index, vector<int> &ans){
    if(index >= size){
        return;
    }
    if(arr[index] % 2 == 0){
        ans.push_back(arr[index]);
    }
    solve(arr, size, index+1, ans);
}

int main() {
        int arr[] = {1,2,3,4,5};
        int size = 5;
        int index = 0;
        vector<int> ans;
        solve(arr, size, index, ans);
        for(int num : ans){
            cout << num << endl;
        }
   return 0;
}