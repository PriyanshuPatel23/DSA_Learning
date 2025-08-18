class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> seen;

        for(char ch : s){
            seen[ch]++;
        }

        for(char ch2 : t){
            seen[ch2]--;
        }

        for(auto pair:seen){
            if(pair.second != 0){
                return false;
            }
        }

        return true;
    }
};