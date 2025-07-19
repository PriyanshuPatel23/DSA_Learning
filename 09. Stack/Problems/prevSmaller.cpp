#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prevSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    for (int i = 0; i < n; i++)
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
    prevSmaller(arr, n);
 return 0;
}