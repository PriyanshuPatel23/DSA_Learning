#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans){
    if(pos == 1){
        cout << "Deleting" << st.top() << endl;
        st.pop();
        return;
    }
    pos--;
    int temp = st.top();
    st.pop();
    solve(st, pos, ans);
    st.push(temp);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    int pos = 2;
    int ans = 0;
    
    solve(st, pos, ans);
 return 0;
}