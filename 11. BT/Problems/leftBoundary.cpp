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

void printLeftBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	cout << root->data << " ";
	if(root->left != NULL) {
		printLeftBoundary(root->left);
	}
	else {
		printLeftBoundary(root->right);
	}
}


int main(){
    Node* root = createTree();
    printLeftBoundary(root);
}