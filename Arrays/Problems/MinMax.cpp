#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int findMin(int arr[][4], int row, int col)
{
    int minAns = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < minAns)
            {
                minAns = arr[i][j];
            }
        }
    }
    return minAns;
}

int findMax(int arr[][4], int row, int col)
{
    int maxAns = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > maxAns)
            {
                maxAns = arr[i][j];
            }
        }
    }
    return maxAns;
}

int main()
{
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 70, 8},
        {9, 10, 1, 11},
        {12, 24, 46, 89}};
    int row = 4;
    int col = 4;
    int target = 89;

    cout << "Printing the max No. : " << findMax(arr, row, col) << endl;
    cout << "Printing the min No. : " << findMin(arr, row, col) << endl;
}