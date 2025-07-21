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

void printRightView(Node* root, int level, vector<int>& rightView) {
  if(root == NULL) 
	return;

  if(level == rightView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	rightView.push_back(root->data);
  }
  printRightView(root->right, level+1, rightView);
  printRightView(root->left, level+1, rightView);
}



int main(){
    Node* root = createTree();
    vector<int> rightView;
    printRightView(root, 0, rightView);
    for(int i=0; i<rightView.size(); i++) {
	 cout << rightView[i] << " ";
   }
}