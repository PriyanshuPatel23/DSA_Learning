#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueueRec(queue<int> &q)
{
    // base case
    if (q.empty())
        return;
    int top = q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(top);
}

void print(queue<int> q) {
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    reverseQueueRec(q);
    print(q);
}