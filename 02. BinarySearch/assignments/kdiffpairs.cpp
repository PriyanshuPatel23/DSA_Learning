class Solution {
public:
    bool binarySearch(vector<int>& nums, int start, int target) {
        int low = start, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0; 

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = nums[i] + k;
            if (binarySearch(nums, i + 1, target)) {
                count++;
            }
        }
        return count;
    }
};