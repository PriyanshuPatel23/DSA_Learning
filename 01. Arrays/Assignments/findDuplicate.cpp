class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>seen;
        vector<int> ans;
        for(int i: nums){
            seen[i]++;
        }

        for(auto pair : seen){
            if(pair.second > 1){
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};