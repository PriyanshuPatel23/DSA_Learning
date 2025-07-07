#include <iostream>
using namespace std;

int missingNumber(int arr[], int n){
   int sum = 0;
   for(int i = 0; i < n; i++){
       sum = sum + arr[i];
   }
   int totalSum = (n * (n+1))/2;
   int ans =  totalSum - sum;
   return ans;
}
    
int main() {
    int arr[] = {3,0,1};
    int n = 3;
    cout << missingNumber(arr,n) << endl;
    return 0;
}