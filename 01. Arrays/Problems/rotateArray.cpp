#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int k)
{
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        int newIndex = (i + k) % n;
        ans[newIndex] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 3;
    rotateArray(arr, n, k);

    cout << "Printing" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}