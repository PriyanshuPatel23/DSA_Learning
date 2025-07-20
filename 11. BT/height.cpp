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

Node* createTree() {
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;

  if(data == -1) {
	return NULL;
  }
  //Step1: create Node
  Node* root = new Node(data);
  //Step2: Create left subtree
  //cout << "left of Node: " << root->data << endl;
  root->left = createTree();
  //Step3: Craete right subtree
  //cout << "right of Node: " << root->data << endl;
  root->right = createTree();
  return root;

}

int height(Node* root) {
	//base case
	if(root == NULL ) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	int height = max(leftHeight, rightHeight) + 1;
	return height;
}


int main(){
    Node* root = createTree();
    int ans = height(root);
    cout << ans;
    return 0;
}