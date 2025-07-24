#include <iostream>
#include <queue>
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


int kthSmallest(Node* root, int &k) {
        if(root == NULL) {
            return -1;
        }
        //LNR
        //L
        int leftAns = kthSmallest(root->left, k );
        if(leftAns != -1) {
            return leftAns;
        }
        //N;
        k--;
        if( k == 0) {
            return root->data;
        }
        //R
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
        
    }


int main() {
   Node* root = NULL; 
   createBST(root);
   int k = 4;
   int ans = kthSmallest(root, k);
    if(ans != -1) {
        cout << "The " << k << "-th smallest element is: " << ans << endl;
    } else {
        cout << "Invalid value of k (too large)." << endl;
    }

    return 0;
}