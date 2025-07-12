#include <iostream>
using namespace std;

int findMissingElement(int arr[], int n) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;
  int ans = -1;

  while(s <= e) {
    int diff = arr[mid] - mid;

    if(diff == 1) {
      s = mid+1;
    }
    else {
      ans = mid;
      e = mid - 1;
    }
     mid = s + (e-s)/2;
  }

  if(ans +1 == 0)
    return n+1;
  
  return ans+1;
}


int main() {
    int arr[] = {1,2,3,5,6};
    int n = 5;
    
    cout << findMissingElement(arr,n) << endl;
    return 0;
}