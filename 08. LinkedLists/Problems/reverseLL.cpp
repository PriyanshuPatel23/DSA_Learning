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

  ListNode* reverseListUsingRecursion(ListNode *prev, ListNode *curr) {
        if (curr == NULL) {
            return prev;
        }   
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        return reverseListUsingRecursion(prev, curr);
    }

    ListNode* reverseList(ListNode *head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        return reverseListUsingRecursion(prev, curr);

        // while(curr != NULL){
        //     ListNode* nextNode  = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextNode;
        // }
        // return prev;
    }
    
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
}


int main() {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 5);
    print(head);
    cout << endl;
    head = reverseList(head);
    print(head);
    cout << endl;
    return 0;
}