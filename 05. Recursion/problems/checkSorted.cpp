#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

bool checkSorted(int arr[], int size, int index){
    if(index >= size){
        return true;
    }
    if(arr[index] > arr[index - 1]){
        bool recAns = checkSorted(arr, size, index + 1);
        return recAns;
    }
    else{
        return false;
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int index = 0;
    
    bool isSorted = checkSorted(arr, size, index);
    if(isSorted){
        cout << "Array is Sorted" << endl;
    }
    else {
        cout << "Array is not Sorted" << endl;
    }
   return 0;
}