#include <iostream>
#include <algorithm>
using namespace std;


void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i -1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }        
        }   
    }
} 

void selectionSort(int arr[], int n ){
    for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    swap(arr[i], arr[minIndex]);
  }
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
    int arr[] = {44,33,55,22,11};
    int n = 5;
    bubbleSort(arr, n);
    cout << "Printing after bubble sort" << endl;
    print(arr, n);
    selectionSort(arr, n);
    cout << "Printing after selection sort" << endl;
    print(arr, n);
    insertionSort(arr, n);
    cout << "Printing after insertion sort" << endl;
    print(arr, n);
    
    return 0;
}