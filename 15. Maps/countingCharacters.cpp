#include <iostream>
#include <unordered_map>
using namespace std;

void countingCharacters(unordered_map<char, int> &mapping, string str){
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        mapping[ch]++;
    }
}

int main() {
    string str = "priyanshupatel";
    unordered_map<char, int>mapping;
    countingCharacters(mapping, str);
    
    for(auto i : mapping){
        cout << i.first << "->" << i.second << endl;
    }
    return 0;
}