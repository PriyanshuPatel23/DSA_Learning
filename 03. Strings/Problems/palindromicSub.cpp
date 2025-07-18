#include <iostream>
using namespace std;

int expand(string s,int i, int j) {
        int count = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j] ) {
            count++;
            i--;
            j++;
        }
        return count;
}

int countSubstrings(string s) {
        int totalCount = 0;
        for(int i = 0; i < s.length(); i++ ) {
            int j = i;
            int oddKaAns = expand(s, i, j);
            j = i+1;
            int evenKaAns = expand(s, i, j);
            totalCount = totalCount + oddKaAns + evenKaAns;
        }
        return totalCount;
    }


int main() {
    string s = "abc";
    int ans = countSubstrings(s);
    cout << ans;
    return 0;
}