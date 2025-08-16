class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i]; 
            if(seen.count(complement)){
                ans.push_back(seen[complement]);
                ans.push_back(i);
            }
            seen[nums[i]] = i;
        }
        return ans;
    }
};

// https://leetcode.com/problems/two-sum/