#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    Node(){
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp -> next;
    }
}

int findLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL)
    {
    Node* newNode = new Node(data);
    head =newNode;
    tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
     if(head == NULL)
    {
    Node* newNode = new Node(data);
    head =newNode;
    tail = newNode;
    }else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(head == NULL)
    {
    Node* newNode = new Node(data);
    head =newNode;
    tail = newNode;
    }else{
        int len = findLength(head);
        if(position == 1){
        insertAtHead(head, tail, data);
        }
        else if(position == len){
            insertAtTail(head, tail, data);
        }
        else{
            Node* newNode = new Node(data);
            Node* prevNode = NULL;
            Node* currNode = head;
            while(position != 1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
    
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(head == NULL){
        cout << "cant, del coz ll is empty" << endl;
        return;
    }
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    int len = findLength(head);
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete temp;
    }
    else if(position == len){
        Node* prevNode = tail -> prev;
        prevNode->next = NULL;
        tail-> prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;
        prevNode->next = nextNode;
        currNode -> prev = NULL;
        currNode -> next = NULL;
        nextNode->prev = prevNode;
        delete currNode;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 100);
    insertAtPosition(head, tail, 3, 200);
    print(head);
    cout << endl;
    deleteNode(head, tail, 3);
    cout<< endl;
    print(head);
    return 0;
}