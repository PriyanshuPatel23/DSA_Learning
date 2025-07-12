#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void printDigits(int num, vector<int> &ans){
    if(num == 0){
        return;
    }
    int digit = num % 10;
    printDigits(num/10, ans);
    ans.push_back(digit);
}

int main() {
    int num = 4217;
    vector<int>ans;
    printDigits(num,ans);
    for(int n:ans){
        cout << n << endl;
    }
   return 0;
}