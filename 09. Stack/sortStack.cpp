#include <iostream>
#include <stack>
using namespace std;


void insertSorted(stack<int> &st, int element) {
  //base case
  if(st.empty() || element > st.top()) {
    st.push(element);
    return;
  }

  //1 case sambhalna h
  int temp = st.top();
  st.pop();
  //recursion sambhalega
  insertSorted(st,element);
  //backtrack
  st.push(temp);
}

void sortStack(stack<int> &st) {
  //base case
  if(st.empty()) {
    return;
  }

  //1 case
  int temp = st.top();
  st.pop();

  //recursion
  sortStack(st);

  //backtrack
  insertSorted(st, temp);
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

    int element = 25;
    insertSorted(st, element);
    cout << "Stack after inserting sorted: ";
    printStack(st);
    
    
 
 return 0;
}