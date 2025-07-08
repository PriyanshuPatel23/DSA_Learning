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

int main() {
    int arr[] = {1,2,3,2,6,7,8};
    int n = 8;
    int k = 2;
    
    cout << findFirstOccurence(arr,n,k) << endl;
    return 0;
}