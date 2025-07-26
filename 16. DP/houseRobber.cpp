#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solveUsingRecursion(vector<int>& nums, int index){
    if(index >=  nums.size()){
        return 0;
    }
    int include = nums[index] + solveUsingRecursion(nums, index+2);
    int exclude = 0 + solveUsingRecursion(nums, index+1);
    int ans = max(include, exclude);
    return ans;
}

int solveUsingMemo(vector<int>& nums, int index, vector<int>& dp){
    if(index >=  nums.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
   int include = nums[index] + solveUsingMemo(nums, index+2, dp);
    int exclude = 0 + solveUsingMem(nums, index+1, dp);
    dp[index] = max(include, exclude);
    return dp[index];
}
  
   int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        //step1
        vector<int> dp(n, -1);
        //step2
        dp[n-1] = nums[n-1];
        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = dp[index+2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

     int solveUsingTabulationSO(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        int next = 0;
        int curr;

        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;
            curr = max(include, exclude);

            //bhul jata hu
            next = prev;
            prev = curr;
        }
        return prev;
    }


int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-1);
    
    int index = 0;
    // int ans = solveUsingRecursion(nums, index);
    // cout << ans << endl; 
    vector<int> dp(nums.size()+1, -1);
    int ans = solveUsingMemo(nums, index, dp);
    cout << ans << endl;
    int ans = solveUsingTabulationSO(nums);
    cout << ans << endl;
    return 0;
}