#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int evenIndex = 0;
        int oddIndex = 1;
        int index = 0;

        while (index < n) {
            if (nums[index] > 0) {
                ans[evenIndex] = nums[index];
                evenIndex += 2;
            }
            index++;
        }

        index = 0;

        while (index < n) {
            if (nums[index] < 0) {
                ans[oddIndex] = nums[index];
                oddIndex += 2;
            }
            index++;
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        return ans;
    }

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(-2);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-4);
    rearrangeArray(nums);
    return 0;
}