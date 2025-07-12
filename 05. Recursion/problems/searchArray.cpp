#include <iostream>
using namespace std;

bool searchArray(int arr[], int size, int index, int target){
    if(index >= size){
        return false;
    }
    if(arr[index] == target){
        return true;
    }
    bool aageKaAns = searchArray(arr, size, index + 1, target);
    return aageKaAns;
}

int main() {
        int arr[] = {10,20,30,40,50};
        int size = 5;
        int index = 0;
        int target = 30;                                
        cout << searchArray(arr, size, index, target);
   return 0;
}