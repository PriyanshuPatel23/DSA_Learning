#include <iostream>
using namespace std;

string removeDuplicate(string s){
    string ans = "";
    int index = 0;
    while(index < s.length()){
        if(ans.length() && ans[ans.length() -1] == s[index]){
            ans.pop_back();
        }
        else{
            ans.push_back(s[index]);
        }
        index++;
    }
    return ans;
}


int main() {
    string s = "abbaca";
    string result = removeDuplicate(s);
    cout << result;
    return 0;
}