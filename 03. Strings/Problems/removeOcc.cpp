#include <iostream>
using namespace std;

string removeOcc(string s, string part){
    while(s.find(part) != string::npos){
        s.erase(s.find(part), part.length());
    }
    return s;
}


int main() {
    string s = "daabcbaabcbc";
    string part ="abc";
    s = removeOcc(s,part);
    cout << s;
    return 0;
}