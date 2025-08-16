class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != nums[start]){
                start++;
                nums[start] = nums[i];
            }
        }
        return start + 1;
    }
};