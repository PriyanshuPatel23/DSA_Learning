#include <iostream>
#include <vector>
using namespace std;

int binSearch(int arr[], int s, int e, int target) {
	if(s > e ){
		return -1;
	}

	int mid = s + (e-s)/2;
	if(arr[mid] == target) {
		return mid;
	}
	if(arr[mid] < target) {
		return binSearch(arr,mid+1,e, target);
	}
	else {
		return binSearch(arr,s,mid-1, target);
	}
	
}



int main() {
   int arr[] = {10,20,30,40,50,60,70,80};
	int size = 8;
	int start = 0;
	int end = size - 1;
	int target = 60;

	int foundIndex = binSearch(arr, start, end, target);

	if(foundIndex != -1) {
		cout << "target found at: " << foundIndex << endl;
	}
	else {
		cout << "target not found"<< endl;
	}
	
    return 0;
}