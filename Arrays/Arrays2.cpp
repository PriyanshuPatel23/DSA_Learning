#include <iostream>
using namespace std;

void solve(int &a)
{
    a++;
    cout << "Print inside Solve Function " << a << endl;
}

void solve(int arr[], int n)
{
    arr[1] = 100;
}

int main()
{
    // -> Printing Combinations

    //     int arr[] = {1,2,3,4};
    //   int n = 4;

    //   for(int i=0; i<n; i++ ) {
    //     for(int j=0; j<n; j++) {
    //       for(int k=0; k<n; k++) {
    //         cout << arr[i] <<" " << arr[j] << " " << arr[k] << endl;
    //       }
    //     }
    //   }

    // -> Printing Two Combinations

    // int arr[] = {10,20, 30};
    // int n = 3;

    // for(int i=0; i<n; i++) {
    //  for(int j=0; j<n; j++) {
    //    cout << arr[i] <<", " << arr[j] << endl;
    //  }
    // }

    // -> passing as a value
    // int arr[] = {1,2,4};
    // int size = 3;
    // solve(arr, size);

    // for(int i = 0; i < size; i++){
    //     cout << arr[i] << " ";
    // }

    // -> Refrence and a pointer
    // int a = 50;
    // cout << a << endl;
    // int *b = &a;
    // cout << b << endl;
    // int& c = a;
    // cout << c << endl;
    // c = c + 1;
    // cout << a << endl;

    // -> passing as a refrence variable

    // int a = 5;
    // solve(a);

    // cout << "Print inside main function " << a;

    return 0;
}