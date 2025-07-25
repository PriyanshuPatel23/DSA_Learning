#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int solveUsingRecursion(string a, string b, int i, int j) {
        //basecase
        if( i >= a.length()) {
            return 0;
        }
        if(j >=b.length()) {
            return 0;
        }

        //recursive call
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1 + solveUsingRecursion(a,b, i+1, j+1);
        }
        else {
            ans = 0 + max(solveUsingRecursion(a,b, i, j+1),
                        solveUsingRecursion(a,b, i+1, j));
        }
        return ans;
    }
    int solveUsingMem(string& a, string& b, int i, int j,vector<vector<int> >& dp) {
        //basecase
        if( i >= a.length()) {
            return 0;
        }
        if(j >=b.length()) {
            return 0;
        }

        //check if ans already exists
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        //recursive call
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1 + solveUsingMem(a,b, i+1, j+1,dp);
        }
        else {
            ans = 0 + max(solveUsingMem(a,b, i, j+1,dp),
                        solveUsingMem(a,b, i+1, j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveUsingTabulation(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            for(int j_index=b.length()-1; j_index>=0; j_index--) {
                    int ans = 0;
                    if(a[i_index] == b[j_index]) {
                        ans = 1 + dp[i_index+1][j_index+1];
                    }
                    else {
                        ans = 0 + max(dp[i_index][j_index+1],dp[i_index+1][j_index]);         
                    }
                    dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }
    int solveUsingTabulationNoLoopChange(string a, string b) {
        //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
        vector<int> currRow(b.length()+1,0);
        vector<int> nextRow(b.length()+1, 0);

        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            for(int j_index=b.length()-1; j_index>=0; j_index--) {
                    int ans = 0;
                    if(a[i_index] == b[j_index]) {
                        ans = 1 + nextRow[j_index+1];
                    }
                    else {
                        ans = 0 + max(currRow[j_index+1],nextRow[j_index]);         
                    }
                    currRow[j_index] = ans;
            }
            //shoiftingh
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int solveUsingTabulationSO(string a, string b) {
        //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
        vector<int> curr(a.length()+1, 0);
        vector<int> next(a.length()+1, 0);

    for(int j_index=b.length()-1; j_index>=0; j_index--) {
        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            
                    int ans = 0;
                    if(a[i_index] == b[j_index]) {
                        ans = 1 + next[i_index+1];
                    }
                    else {
                        ans = 0 + max(next[i_index],curr[i_index+1]);         
                    }
                    curr[i_index] = ans;
            }
            //shifting
            next= curr;
        }
        return next[0];
    }


int main() {
    string word1 = "abcde";
    string word2 = "ace";

    int i = 0;
    int j = 0;

    int ans = solveUsingRecursion(word1, word2, i, j);
    cout << ans << endl;

    return 0;
}