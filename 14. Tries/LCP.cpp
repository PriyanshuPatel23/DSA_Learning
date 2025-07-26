#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;
        
        TrieNode(char val){
            this->value = val;
            for(int i = 0; i < 26; i++){
                children[i]=NULL;
            }
            this->isTerminal = false;
            this->childCount = 0;
        }
};

void insertWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
        root->childCount++;
    }
    
    insertWord(child, word.substr(1));
}

void findLCP( string& ans, TrieNode* root) {
        //base case
        if(root->isTerminal == true) {
            return;
        }

        ///abhi main root node pr hu 
        TrieNode* child;
        if(root->childCount == 1) {
            
            //child tk jao
            for(int i=0; i<26; i++) {
                if(root->children[i] != NULL) {
                    child = root->children[i];
                }
            }
            //ans me store karwao
            ans.push_back(child->value);
        }
        else {
            return;
        }
        //ab recursion ki baari 
        findLCP(ans, child);
    }

string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        //insert all strings
        for(auto str: strs) {
            insertWord(root, str);
        }
        string ans = "";
        //string str = strs[0];
        findLCP( ans, root);
        return ans;
}

    

int main() {
    vector<string> strs;
    string str1 = "flower";
    string str2 = "flight";
    string str3 = "flow";
    strs.push_back(str1);
    strs.push_back(str2);
    strs.push_back(str3);
    string ans = longestCommonPrefix(strs);
    cout << ans;
    
    return 0;
}