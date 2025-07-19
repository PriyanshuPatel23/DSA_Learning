#include <iostream>
#include <map>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Your existing hasCycle function
bool hasCycle(ListNode *head) {
    map<ListNode*, bool> table;
    ListNode* temp = head;
    while(temp != NULL) {
        if(table[temp] == false) {
            table[temp] = true;
        }
        else {
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

// Utility function to print result
void testCycle(ListNode* head) {
    if (hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
}

int main() {
    // Create nodes
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    cout << "Test 1: No cycle" << endl;
    testCycle(node1); // Expected: No cycle

    // Create a cycle: 5 -> 3
    node5->next = node3;

    cout << "Test 2: Cycle present (5->3)" << endl;
    testCycle(node1); // Expected: Cycle detected

    return 0;
}
