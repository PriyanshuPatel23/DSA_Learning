class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        
        long long sum = 0;
        unordered_map<int,int> seen;
        int duplicate = -1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int val = grid[i][j];
                sum += val;
                seen[val]++;
                if(seen[val] == 2) duplicate = val;
            }
        }
        
        long long expected = 1LL * N * (N + 1) / 2;
        int missing = expected - (sum - duplicate);
        
        return {duplicate, missing};
    }
};
