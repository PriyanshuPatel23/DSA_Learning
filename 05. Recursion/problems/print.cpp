#include <iostream>
using namespace std;
void print(int n){
    if(n == 1){
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    print(n-1);
}

int main() {
        print(7);
   return 0;
}