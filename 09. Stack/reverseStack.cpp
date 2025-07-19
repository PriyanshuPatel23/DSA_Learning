#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(temp);
}

void reverseStack(stack<int> &st) {
  //base case
  if(st.empty()) {
    return;
  }
  //1 case main solve krega
  int temp = st.top();
  st.pop();
  //refcursion
  reverseStack(st);
  //backtrack
  insertAtBottom(st,temp);
}


void printStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(50);
    st.push(60);

    int element = 400;
    insertAtBottom(st, element);
    reverseStack(st);
    cout << "Stack after inserting at bottom: ";
    printStack(st);
    
    
 
 return 0;
}