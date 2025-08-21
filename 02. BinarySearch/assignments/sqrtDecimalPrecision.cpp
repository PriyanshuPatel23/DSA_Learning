#include <iostream>
using namespace std;

// Step 1: Find integer part using Binary Search
int sqrtInt(int x) {
    int s = 0, e = x;
    long long mid;
    int ans = -1;

    while (s <= e) {
        mid = s + (e - s) / 2;
        
        if (mid * mid == x) return mid;
        
        if (mid * mid < x) {
            ans = mid;   // store closest integer
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

// Step 2: Refine answer using decimals
double sqrtWithPrecision(int x, int precision) {
    int intPart = sqrtInt(x); // integer square root
    double ans = intPart;
    double step = 0.1;

    for (int i = 0; i < precision; i++) {
        while ((ans + step) * (ans + step) <= x) {
            ans += step;
        }
        step /= 10; // refine to next decimal place
    }
    return ans;
}

int main() {
    int x = 10;
    int precision = 3;  // 3 decimal places
    double ans = sqrtWithPrecision(x, precision);
    cout << "Square root of " << x << " = " << ans << endl;
    return 0;
}
