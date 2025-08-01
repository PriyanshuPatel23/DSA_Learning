#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int findLength(char ch[], int size) {
  int index = 0;
  while(ch[index] != '\0') {
    index++;
  }
  return index;
}


bool checkPalindrome(char ch[], int n) {								
  int i=0; 
  int j = n-1;

  while( i<= j) {
    if(ch[i] == ch[j]) {
      i++;
      j--;
    }
    else {
      return false;
    }
  }
  return true;
  
}

int main() {    

    char ch[100];
    cin.getline(ch, 100);
    
    
    int len = findLength(ch, 100);

   bool isPalindrome = checkPalindrome(ch, len);
  
   if(isPalindrome) {
    cout << "Valid Palindrome" << endl;
   }
   else {
    cout << "Invalid Palindrome" << endl;
   }
    
return 0;
}