#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

bool findTarget(int arr[][4], int row, int col, int target)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                // if found, return true
                return true;
            }
        }
    }
    return false;
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

    cout << "Found or Not: " << findTarget(arr, row, col, target) << endl;
}