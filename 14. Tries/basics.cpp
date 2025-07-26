#include <iostream>
#include <string>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char val){
            this->value = val;
            for(int i = 0; i < 26; i++){
                children[i]=NULL;
            }
            this->isTerminal = false;
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
    }
    
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    if(word.length() == 0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    
   bool recursionAns = searchWord(child, word.substr(1));
   return recursionAns;
}

void deleteWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return;
    }
    
   deleteWord(child, word.substr(1));
 
}

int main() {
    TrieNode* root = new TrieNode('-');

  insertWord(root, "cater");
  insertWord(root, "care");
  insertWord(root, "com");
  insertWord(root, "lover");
  insertWord(root, "loved");
  insertWord(root, "load");
  insertWord(root, "lov");
  insertWord(root, "bat");
  insertWord(root, "cat");
  insertWord(root, "car");
  cout << "Insertion Done" << endl; 
   if(searchWord(root, "loved") ) {
    cout << "Found" << endl;
   }
   else {
    cout << "Not Found" << endl;
   }

   deleteWord(root, "loved")	;

   if(searchWord(root, "loved") ) {
    cout << "Found" << endl;
   }
   else {
    cout << "Not Found" << endl;
   }
    return 0;
}