#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node() {
          cout << "Destructor called for: " << this->data << endl;
        }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}


void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

int findLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<"->";
        temp = temp->next;
    }
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        int len = findLength(head);
        
        if(position == 1) {
                insertAtHead(head, tail , data);
                return;
        }
        else if(position > len) {
                insertAtTail(head, tail, data);
                return;
        }
        else {
            Node* newNode = new Node(data);
            
            Node* prev = NULL;
            Node* curr = head;
            while(position != 1) {
                position--;
                prev = curr;
                curr = curr->next;
            }
            
            newNode -> next = curr;

            prev -> next = newNode;
            
        }
        
}

void deleteNode(Node* &tail, Node* &head, int position){
    if(head == NULL){
        cout << "cannot, del coz ll is empty" << endl;
        return;
    }
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    int len = findLength(head);
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if(position == len){
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail =prev;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        while(position!=1){
            position--;
            prev = curr;
            curr = curr -> next;
        }
        prev->next = curr-> next;
        curr->next = NULL;
        delete curr;
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
    insertAtPosition(200, 3, head, tail);
    cout << endl;
    print(head);
    cout << endl;
    deleteNode(tail,head,3);
    cout<<endl;
    print(head);
    cout << endl;
    return 0;
}