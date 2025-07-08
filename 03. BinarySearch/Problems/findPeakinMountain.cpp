#include <iostream>
using namespace std;

 int peakIndexInMountainArray(int arr[], int n) {
        int s = 0;
        int e = n-1;
            int mid = s + (e-s)/2;

        while(s < e) {
            if(arr[mid] < arr[mid+1] ){
                s = mid + 1;
            }
            else {
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return e;
    }


int main() {
    int arr[] = {0,1,0};
    int n = 3;
    
    cout << peakIndexInMountainArray(arr,n) << endl;
    return 0;
}