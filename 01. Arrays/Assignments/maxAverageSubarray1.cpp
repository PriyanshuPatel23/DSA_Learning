class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int vals = 0;
        for(int i = 0; i < k; i++){
            vals += nums[i];
        }
        int maxVals = vals;
        for(int i = k; i < nums.size(); i++){
            vals = vals - nums[i-k] + nums[i];
            maxVals = max(maxVals, vals);
        }
        return (double)maxVals / k;
    }
};