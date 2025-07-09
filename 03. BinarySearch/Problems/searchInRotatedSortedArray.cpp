#include <iostream>
using namespace std;

int findPivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e - s) / 2;
    
   while(s <= e){
       if(s == e){
           return s;
       }
        if(mid + 1 < n && arr[mid] > arr[mid + 1]){
        return mid;
    }
    else if(mid - 1 >= 0 && arr[mid] < arr[mid - 1]){
        return mid - 1;
    }
    else if(arr[mid] < arr[s]){
        e = mid - 1;
    }
    else {
        s = mid + 1;
    }
    mid = s + (e - s) / 2;
   }
    
    return -1;
}

 int binarySearch(int arr[], int s, int e, int target) {
        int mid = s + (e-s)/2;
        while(s<=e) {
            if(arr[mid] == target) {
                return mid;
            }
            if(target > arr[mid]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = 7;
    int pivot = findPivot(arr, n);
    int target = 0;
    int ans = -1;
    
    if(target >= arr[0] && target <= arr[pivot]){
        ans = binarySearch(arr, 0, pivot, target);
    }else{
        ans = binarySearch(arr, pivot+1, n-1, target);
    }
    cout << "Target found at index: " << ans << endl;
    return ans;
}