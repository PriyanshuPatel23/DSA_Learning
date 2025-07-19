#include <iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;
    ListNode(){
        this->data = 0;
        this->next = NULL;
    }
    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};
    
void insertAtHead(ListNode *&head, ListNode *&tail, int data)
{
    if (head == NULL)
    {
        ListNode *newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(data);
        newNode->next = head;
        head = newNode;
    }
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int getLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
ListNode* middleNode(ListNode* head) {
        int n = getLength(head);
        int position = n/2 + 1;
        ListNode* temp = head;

        while(position != 1){
            position--;
            temp = temp->next;
        }
        return temp;
        
        //another logic 
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast=fast->next;
                slow = slow->next;
            }
        }

        return slow;
}


int main() {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);
    cout << endl;
    head = middleNode(head);
    print(head);
    
    return 0;
}