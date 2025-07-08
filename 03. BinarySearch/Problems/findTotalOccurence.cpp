#include <iostream>
using namespace std;

int findFirstOccurence(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while(start<=end){
        if(arr[mid] == target){
            ans = mid;
            end = mid -1;
        }
        else if(target >arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;  
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}


int findLastOccurence(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while(start<=end){
        if(arr[mid] == target){
            ans = mid;
            start = mid + 1;
        }
        else if(target >arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;  
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int findTotalOccurence(int arr[], int n, int k){
  int firstOcc = findFirstOccurence(arr, n, k);
  int lastOcc = findLastOccurence(arr, n, k);
  int total = lastOcc - firstOcc + 1 ;
  return total;
}

int main() {
    int arr[] = {1,2,2,2,4};
    int n = 5;
    int k = 2;
    
    cout << findTotalOccurence(arr,n,k) << endl;
    return 0;
}