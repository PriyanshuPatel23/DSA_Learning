#include <iostream>
using namespace std;

void shiftNegativeOneSide(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = 6;
    sortColors(arr, n);

    cout << "Printing" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}