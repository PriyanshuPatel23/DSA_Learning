#include <iostream>
using namespace std;

void sortColors(int arr[], int n)
{
    int index = 0;
    int left = 0;
    int right = n - 1;

    while (index <= right)
    {
        if (arr[index] == 0)
        {
            swap(arr[index], arr[left]);
            index++;
            left++;
        }
        else if (arr[index] == 1)
        {
            index++;
        }
        else
        {
            swap(arr[index], arr[right]);
            right--;
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