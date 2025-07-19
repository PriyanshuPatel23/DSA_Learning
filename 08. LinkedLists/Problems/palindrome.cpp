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
        // int n = getLength(head);
        // int position = n/2 + 1;
        // ListNode* temp = head;

        // while(position != 1){
        //     position--;
        //     temp = temp->next;
        // }
        // return temp;
        
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
    
bool compareList(ListNode* head1, ListNode* head2){
    while(head2 != NULL){
        if(head1 -> data != head2 -> data){
            return false;
        }
        else{
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return true;
}

bool isPalindrome(ListNode* head){
    ListNode* midNode = middleNode(head);
    ListNode* head2 = midNode -> next;
    midNode->next = NULL;
    
    ListNode* prev = NULL;
    ListNode* curr = head2;
    head2 = reverseListUsingRecursion(prev,curr);
    
    bool ans = compareList(head, head2);
    return ans;
}

int main() {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 5);
    
    print(head);
    cout << endl;
    
     bool ans = isPalindrome(head);
    cout << (ans ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}