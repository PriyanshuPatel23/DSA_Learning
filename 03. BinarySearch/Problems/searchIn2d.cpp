#include <iostream>
using namespace std;

int searchIn2d(int arr[][4], int target, int row, int col){
    int n = row*col;
    int s = 0;
    int e = n - 1;
    
    while( s <= e ){
        
    int mid = s + (e - s) / 2;
        int rowIndex  = mid/col;
        int colIndex = mid%col;
        int curr = arr[rowIndex][colIndex];
        if(curr == target){
            return true;
        }
        else if(curr < target){
            s = mid + 1;
        }
        else {
            e = mid - 1;
        } 
    }
    return false;
}

int main() {
    int arr[3][4] = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };
    int target = 3;
    int row = 3;
    int col = 4;
    cout << (searchIn2d(arr, target, row, col) ? "Found" : "Not Found");
    return 0;
}