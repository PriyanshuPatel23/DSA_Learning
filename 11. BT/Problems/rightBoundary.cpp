#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree(){
    cout << "enter the value of node: " << endl;
    int data;
    cin >> data;
    
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}   

void printRightBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	
	if(root->right != NULL) {
			printRightBoundary(root->right);
	}
	else {
			printRightBoundary(root->left);
	}
	cout << root->data << " ";
}



int main(){
    Node* root = createTree();
    printRightBoundary(root);
}
