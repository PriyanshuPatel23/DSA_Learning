#include <iostream>
using namespace std;

int findLength(char ch[], int size){
    int index = 0;
    while(ch[index] != '\0'){
        index++;
    }
    return index;
}

int main() {    

    char ch[100];
    cin.getline(ch, 100);
    
    int length = findLength(ch, 100);
    cout << length;

return 0;
}