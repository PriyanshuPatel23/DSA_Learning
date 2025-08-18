class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() - 1;
        string vowels = "aeiouAEIOU";
        while (start <= end) {
            if (vowels.find(s[start]) != string::npos &&
                vowels.find(s[end]) != string::npos) {
                swap(s[start], s[end]);
                start++;
                end--;
            } else if (vowels.find(s[start]) == string::npos) {
                start++;
            } else if (vowels.find(s[end]) == string::npos) {
                end--;
            }
        }
        return s;
    }
};