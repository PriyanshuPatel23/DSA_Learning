#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string s){
    stack<char>st;
    int n = s.size();
    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            int operatorCount = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '/')
                    operatorCount++;
                st.pop();
                
            }
            st.pop();
            if(operatorCount == 0){
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    string str = "((a+b)*(a+b))";
    cout<<checkRedundant(str)<<endl;
 return 0;
}