#include <iostream>
#include <limits.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

void countZeroOne(int arr[], int size)
{
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    cout << "Zeros" << zeroCount << endl;
    cout << "Ones" << oneCount << endl;
}

int findMinimumInArray(int arr[], int size)
{
    int MIN_ANS = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < MIN_ANS)
        {
            MIN_ANS = arr[i];
        }
    }
    return MIN_ANS;
}

void reverseArray(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void extremePrint(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        if (left == right)
        {
            cout << arr[left] << endl;
        }
        else
        {
            cout << arr[left] << endl;
            cout << arr[right] << endl;
        }

        left++;
        right--;
    }
}

int main()
{
    // -> Function with arrays

    // Reverse print

    // int arr[6] = {10,20,30,40,50,60};
    // int size = 6;
    // reverseArray(arr, size);
    // extremePrint(arr, size);

    // Minimum in an Array

    // int arr[] = {10,8,31,4,3,1,-51};
    // int size = 7;

    // int minimum = findMinimumInArray(arr, size);
    // cout << "Minimum Number is " << minimum << endl;

    // Counting Zero and One

    // cout << INT_MIN << endl;
    // cout << INT_MAX << endl;

    // int arr[] = {0,0,0,1,1,0,1,0,1,0,1,0,1,1,1};
    // int size = 15;
    // countZeroOne(arr, size);

    // Linear search and printing

    // int arr[5] = {2,4,6,8,10};
    // int size = 5;
    // int target = 10;

    // bool ans = linearSearch(arr, size, target);
    // if(ans == 1){
    //     cout << "Target Found ";
    // }
    // else{
    //     cout << "Target Not Found";
    // }

    // printArray(arr, size);

    // -> Exploring the Arrays

    // array creation of different datatypes
    // int arr[101];
    // char ch[102];
    // bool flags[223];
    // long num[900];
    // short snum[1000];

    // cout << "Array Created Successfully " << endl;

    // int arr[100];

    // int a = 5;
    // cout << "Size of A is: " << sizeof(a) << endl;
    // cout << "Address of A is: " << &a << endl;

    // int arr[10];
    // cout << "Size of Array is: " << sizeof(arr) << endl;
    // cout << "Address of A is: " << &arr << endl;
    // cout << "Address of A is: " << arr << endl;

    // int arr[] = {2,3,4,56,6};

    // int brr[5] = {1,2,3,4,5};

    // int crr[5] = {2,3};

    // error
    //  int drr[2] = {1,2,3,44,5};

    // -> Taking input in array and printing it index wise

    // int brr[50] = {5,8,9,12,13};
    // int size = 5;

    // for(int i = 0; i < size; i++){
    //     cout << brr[i] << " " << endl;
    // }
    // cout << endl;

    // cout << brr[0] << endl;
    // cout << brr[1] << endl;
    // cout << brr[2] << endl;
    // cout << brr[3] << endl;
    // cout << brr[4] << endl;

    // int arr[5];
    // int n = 5;
    // for(int i = 0; i < n; i++){
    //     cout << "Enter the value for index " << i << endl;
    //     cin >> arr[i];
    //     cout << endl;
    // }

    // cout << "Printing the array" << endl;
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }

    // -> Double the Array in-place

    // int arr[5];
    // int n = 5;
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    // cout << "Printing after taking input" << endl;
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // for(int i = 0; i < n; i++){
    //     arr[i] = 2*arr[i];
    // }

    // cout << "Printing after doubling the array" << endl;
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }

    // -> Sum of An Array

    // int arr[5];
    // int n = 5;

    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }

    // int sum = 0;
    // for(int i = 0; i < n; i++){
    //     sum += arr[i];
    // }

    // cout << "Print Sum " << sum << endl;

    // ->  LinearSearch in array

    // int arr[5] = {2,4,6,8,10};
    // int target = 12;
    // int n = 5;

    // bool flag = 0;

    // for(int i = 0; i < n; i++){
    //     if(arr[i] == target){
    //         flag = 1;
    //         break;
    //     }
    // }

    // if(flag == 1){
    //     cout << "Target Found";
    // }
    // else{
    //     cout << "Target Not Found";
    // }
    return 0;
}