#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    return ans;
}


int main() {
    int arr[] = {2,1,4,3};
    int n = 4;
    nextSmaller(arr, n);
 return 0;
}