#include <iostream>
using namespace std;

// Step 1: Find integer quotient using binary search
int getQuotient(int divisor, int dividend) {
    int s = 0, e = dividend;
    int ans = 0;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if ((long long)mid * divisor == dividend) 
            return mid;
        else if ((long long)mid * divisor < dividend) {
            ans = mid;       // store best so far
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;  // closest integer part
}

// Step 2: Refine with decimals
double divideWithPrecision(int divisor, int dividend, int precision) {
    int intPart = getQuotient(abs(divisor), abs(dividend));
    double ans = intPart;
    double step = 0.1;

    for (int i = 0; i < precision; i++) {
        while ((ans + step) * abs(divisor) <= abs(dividend)) {
            ans += step;
        }
        step /= 10;
    }

    // handle negative results
    if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0)) {
        ans = -ans;
    }

    return ans;
}

int main() {
    int divisor = 7, dividend = 29;
    int precision = 3;

    double ans = divideWithPrecision(divisor, dividend, precision);
    cout << "Quotient = " << ans << endl;

    return 0;
}
