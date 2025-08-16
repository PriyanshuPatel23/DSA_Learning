class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int num : nums) {
            sum += num;
        }
        int totalSum = (n) * (n + 1) / 2;
        int ans = totalSum - sum;
        return ans;
    }
};