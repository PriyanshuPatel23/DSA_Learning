#include <iostream>
using namespace std;

int sqrt(int x){
    int s = 0;
    int e = x;
    long long int mid = s + (e - s) / 2;
    int ans = -1;
    
    while(s <= e){
        if(mid*mid == x){
            return mid;
        }
        else if(mid*mid < x){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    int x = 4;
    int ans = sqrt(x);
    cout << ans;
    return ans;
}