#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int findLength(char ch[], int size){
    int index = 0;
    while(ch[index] != '\0'){
        index++;
    }
    return index;
}

void reverseString(char ch[], int n){
    int i = 0;
    int j = n - 1;
    
    while(i <= j){
        swap(ch[i], ch[j]);
        i++;
        j--;    
    }
}

int main() {    

    char ch[100];
    cin.getline(ch, 100);
    
    int length = findLength(ch, 100);
    cout << "before" << ch;
    reverseString(ch, length);
    cout << endl << "After" << ch;

return 0;
}