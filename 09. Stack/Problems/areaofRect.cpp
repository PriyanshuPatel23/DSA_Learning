#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
int area = INT_MIN;

        for (int i = 0; i < heights.size(); i++)
        {
            int j = i;
            int k = i;
            int a = 1; // Reset 'a' for each histogram bar

            // Move left while the bar is higher
            while (j >= 0 && heights[j] >= heights[i])
            {
                a++;
                j--;
            }

            // Move right while the bar is higher
            while (k < heights.size() && heights[k] >= heights[i])
            {
                a++;
                k++;
            }

            int multi = heights[i] * a;
            area = std::max(area, multi);
        }

        return area;
    }


int main() {
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(4);
    heights.push_back(6);
    heights.push_back(8);
    
    cout << largestRectangleArea(heights) << endl;
    return 0;
}