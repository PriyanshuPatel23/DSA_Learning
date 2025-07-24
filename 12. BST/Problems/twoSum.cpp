#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    else{
        if(data>root->data){
            root->right = insertIntoBST(root->right,data);
        }
        else{
            root->left = insertIntoBST(root->left,data);
        }
    }
    return root;
}

void createBST(Node* &root) {
	cout << "Enter data:" << endl;
	int data;
	cin >> data;

	while(data != -1) {
		root = insertIntoBST(root, data);
		cout << "Enter data:" << endl;
		cin >> data;
	}
}

void storeInorder(Node* root, vector<int> &inorder) {
        //base case
        if(root == NULL) {
            return;
        }
        //LNR
        storeInorder(root->left, inorder);
        //N
        inorder.push_back(root->data);
        //R
        storeInorder(root->right, inorder);
    }

    bool findTarget(Node* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);

        ///find targetnusing 2 pointer approach
        int start = 0;
        int end = inorder.size()-1;

        while(start < end) {
            int sum = inorder[start] + inorder[end];
            if(sum == k) {
                return true;
            }
            else if(sum > k) {
                end--;
            }
            else if(sum < k) {
                start++;
            }
        }
        return false;
    }


int main() {
   Node* root = NULL; 
   createBST(root);
   int k = 10;
   int ans = findTarget(root, k);
    if(ans) {
        cout << "The Target Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}