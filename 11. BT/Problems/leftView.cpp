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

void printLeftView(Node* root, int level, vector<int>& leftView) {
  if(root == NULL) 
	return;

  if(level == leftView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	leftView.push_back(root->data);
  }
  printLeftView(root->left, level+1, leftView);
  printLeftView(root->right, level+1, leftView);
}



int main(){
    Node* root = createTree();
    vector<int> leftView;
    printLeftView(root, 0, leftView);
    for(int i=0; i<leftView.size(); i++) {
	 cout << leftView[i] << " ";
   }
}