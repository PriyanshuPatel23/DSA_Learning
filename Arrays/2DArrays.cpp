#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{

    // -> 2d array
    // int arr[3][3];

    // iniitialse
    //  int arr[3][4] = {
    //  {1,2,3,4},
    //  {5,6,7,8},
    //  {9,10,1,11}
    //  };

    // int brr[] = {1,2,3,4};

    // int crr[][4] = {
    // {1,2,3,4},
    // {5,6,7,8},
    // {9,10,1,11}
    // };

    // int drr[][4] = {
    // {1,2,3,4},
    // {5,6,7,8},
    // {9,10,1,11}
    // };

    // -> taking input in an array

    // int arr[3][3];
    // int row = 3;
    // int col = 3;

    //  for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         cout << "Enter the Row Index " << i << " column index " << j << endl;
    //         cin >> arr[i][j];
    //     }
    // }

    // -> vector demo

    // int arr[5];

    // vector<int> arr;
    // vector<int> arr(5);
    // vector<int> arr(5,101);

    // arr.push_back(4);
    // arr.push_back(8);
    // arr.push_back(12);
    // arr.push_back(11);
    // arr.push_back(4);

    // cout << arr.size() << endl;

    // cout << arr.empty() << endl;

    // cout << "size of Vector" << arr.size();

    // cout << endl << "printing vector" << endl;

    // for(int i = 0; i < arr.size(); i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // -> Jagged Array

    // vector<vector<int>>arr(5, vector<int>(10,-1));
    // for(int i = 0; i < arr.size(); i++){
    //     for(int j = 0 ; j < arr[i].size(); j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // -> 2d array using vector

    // vector<vector<int>>brr;
    // vector<int> vec1(10,2);
    // vector<int> vec2(5,1);
    // vector<int> vec3(7,0);
    // vector<int> vec4(8,1);
    // vector<int> vec5(20,0);

    // brr.push_back(vec1);
    // brr.push_back(vec2);
    // brr.push_back(vec3);
    // brr.push_back(vec4);
    // brr.push_back(vec5);

    // for(int i = 0; i < brr.size(); i++){
    //     for(int j = 0; j<brr[i].size(); j++){
    //         cout << brr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}