#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int value){
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

Node* minValue(Node* root) {
	if(root == NULL) {
		cout << "NO MIN VALUE" << endl;
		return NULL; 
	}
	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

int main() {
   
	Node* root = NULL;
	createBST(root);

	cout << endl;
	Node* minNode = minValue(root);
	if(minNode == NULL) {
		cout << "There is no node in tree, so no min value" << endl;
	}
	else {
		cout << "Min Value: " << minNode->data << endl;
	}

    
    return 0;
}