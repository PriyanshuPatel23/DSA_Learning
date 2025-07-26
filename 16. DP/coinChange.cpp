#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solveUsingRecursion(vector<int>& coins, int amount){
    if(amount == 0){
        return 0;
    }
    int mini = INT_MAX;
    for(int i = 0; i <coins.size(); i++){
        if(amount - coins[i] >= 0){
            int recAns = solveUsingRecursion(coins, amount - coins[i]);
            
            if(recAns != INT_MAX){
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
    }
    return mini;
}

int solveUsingMemo(vector<int>& coins, int amount, vector<int>& dp){
    if(amount == 0){
        return 0;
    }
    if(dp[amount] != -1){
        return dp[amount];
    }
    int mini = INT_MAX;
    for(int i = 0; i <coins.size(); i++){
        if(amount - coins[i] >= 0){
            int recAns = solveUsingMemo(coins, amount - coins[i], dp);
            
            if(recAns != INT_MAX){
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
    }
    dp[amount] = mini;
    return dp[amount];
}

int solveUsingTabulation(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for( int value = 1; value<=amount; value++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
            
                if(value - coins[i] >= 0) {
                    int recursionKaAns = dp[value - coins[i] ];
                    
                    if(recursionKaAns != INT_MAX) {
                        
                        int ans = 1 + recursionKaAns;
                        mini  = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    
    int amount = 11;
    // int ans = solveUsingRecursion(coins, amount);
    // cout << ans << endl; 
    vector<int> dp(amount+1, -1);
    int ans = solveUsingMemo(coins, amount, dp);
    cout << ans << endl;
    
    return 0;
}