#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int mid = (start+end)/2;
    while(start<=end){
        if(arr[mid] == target){
            return mid;
        }
        else if(target >arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,6,7,8};
    int n = 8;
    int k = 3;
    
    cout << binarySearch(arr,n,k) << endl;
    return 0;
}