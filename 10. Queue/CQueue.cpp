#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int val)
    {
        // over flow
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) // imp condition
        {
            cout << "OverFlow" << endl;
            return;
        }
        // first Ele
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // circular Nature
        else if (rear == size - 1 & front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // normal pushing
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void pop()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        // singleElement
        // circular Nature
        // normal Flow
        else if (front == rear)
        {
            // important
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void print()
    {
        cout << "Printing Queue: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~CircularQueue()
    {
        cout << "Destructor Called" << endl;
        delete[] arr;
    }
};
int main() {
    CircularQueue q(5);
    q.print();
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(69);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(69);
    q.push(190);
    q.push(1902);
    q.push(190);
    q.push(0);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
 return 0;
}