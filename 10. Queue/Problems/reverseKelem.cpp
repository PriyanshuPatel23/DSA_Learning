#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseKEle(queue<int> &q, int k)
{
    int n = q.size();
    // edge case
    if (k > n || k == 0)
        return;
    stack<int> st;
    int tempK = k;
    while (tempK--)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // cout << n << endl;
    // n-k elements are still in front unhe piche krdo
    for (int i = 0; i <= (n - k); i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    // reverse k element
    reverseKEle(q, 3);
    while (!q.empty())
    {
    cout << q.front() << " ";
    q.pop();
    }
    return 0;
}