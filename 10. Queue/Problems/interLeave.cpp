#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &first)
{
    queue<int> second;
    // push first half in second
    int n = first.size();
    for (int i = 0; i < n / 2; i++)
    {
        int temp = first.front();
        first.pop();
        second.push(temp);
    }
    // merge in original QUeue
    // for (int i = 0; i < n / 2; i++)
    while (!second.empty())
    {
        int temp = second.front();
        second.pop();
        first.push(temp);
        temp = first.front();
        first.pop();
        first.push(temp);
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
    interleaveQueue(q);
    while (!q.empty())
    {
    cout << q.front() << " ";
    q.pop();
    }
    return 0;
}