class Solution {
public:
    static bool compare(string& a, string& b) { return a + b > b + a; }
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int n : nums) {
            strs.push_back(to_string(n));
        }

        sort(strs.begin(), strs.end(), compare);

        string result;
        for (string& s : strs) {
            result += s;
        }

        if (result[0] == '0')
            return "0";

        return result;
    }
};