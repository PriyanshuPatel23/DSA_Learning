#include <iostream>
using namespace std;

class CustomQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
        CustomQueue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }
        void push(int val){
            if(rear == size - 1){
                cout << "Queue Overflow" << endl;
                return;
            }
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }
        void pop(){
            if(rear == -1 && front == -1){
                cout << "Queue underflow" << endl;
                return; 
            }
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else{
                arr[front] = -1;
                front++;
            }
        }
        bool isEmpty(){
            if(front == -1 && rear == -1){
                return -1;
            }
            else{
                return 0;
            }
        }
        int getSize(){
            if(front == -1 && rear == -1){
                return 0;
            }
            else{
                return (rear-front+1);
            }
        }
        int getRear(){
            if(rear == -1){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[rear];
        }
        void print(){
            cout << "Printing Queue" << endl;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    CustomQueue q(5);
    q.pop();
    cout << "Is Queue Empty: " << q.isEmpty() << endl;
    q.push(10);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.push(20);
    q.pop();
    q.print();
    q.push(30);
    q.print();
    q.pop();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    q.push(60);
    q.print();
    // cout << "Front Element: " << q.getFront() << endl;
    // cout << "Rear element: " << q.getRear() << endl;

    return 0;
}