#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion
int solveUsingRec(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return solveUsingRec(n - 1) + solveUsingRec(n - 2);
}

// 2. Memoization
int solveUsingMemo(int n, vector<int>& dp) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(dp[n] != -1) return dp[n];
    
    dp[n] = solveUsingMemo(n - 1, dp) + solveUsingMemo(n - 2, dp);
    return dp[n];
}

// 3. Tabulation (Bottom-Up DP)
int solveUsingTab(int n) {
    if(n == 0) return 0;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 4. Space Optimized Tabulation
int solveUsingTabulationSO(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int prev = 0, curr = 1, ans;
    for(int i = 2; i <= n; i++) {
        ans = curr + prev;
        prev = curr;
        curr = ans;
    }
    return curr;
}

// Main function to choose method
int fib(int n, int method = 4) {
    if(method == 1) {
        return solveUsingRec(n);
    }
    else if(method == 2) {
        vector<int> dp(n + 1, -1);
        return solveUsingMemo(n, dp);
    }
    else if(method == 3) {
        return solveUsingTab(n);
    }
    else {
        return solveUsingTabulationSO(n);
    }
}

int main() {
    int n = 7;
    int method = 1; // Change 1-4 to choose method
    int ans = fib(n, method);
    cout << "Fibonacci(" << n << ") = " << ans << endl;
    return 0;
}
