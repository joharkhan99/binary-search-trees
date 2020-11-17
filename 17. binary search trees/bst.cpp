#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

void findValue(int num, Node *root){
	if(root == NULL){
		cout << "empty";
	}else{
		while(root){
			if(num == root->data){
				cout << "\nfound: " << root->data << endl;
				break;
			}
			else if(num > root->data)
				root = root->right;
			else
				root = root->left;
		}
	}
}

Node* insert(int val, Node *root){
	Node *newNode = new Node;
	newNode->data = val;
	newNode->left = newNode->right = NULL;
	
	Node *temp = root, *parentLoc = NULL;
	
	while(temp != NULL){
		parentLoc = temp;
		if(val < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if(parentLoc == NULL)
		parentLoc = newNode;
	else if(val < parentLoc->data)
		parentLoc->left = newNode;
	else
		parentLoc->right = newNode;

	root = parentLoc;
	return root;
}

Node* findMinimum(Node *root){
	Node *temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

Node* findMaximum(Node *root){
	Node *temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

Node* Delete(Node *root, int num){
	Node *temp;
	
	if(root == NULL){
		cout<<"\nNot found";
	}
	else if(num < root->data){
		root->left = Delete(root->left, num);
	}
	else if(num > root->data){
		root->right = Delete(root->right, num);
	}
	else{
		//element found
		if(root->left && root->right){
			//replace with largest in left subtree
			temp = findMaximum(root->left);
			root->data = temp->data;
			root->left = Delete(root->left, root->data);
		}else{
			//one child
			temp = root;
			if(root->left == NULL)
				root = root->right;
			if(root->right == NULL)
				root = root->left;
			delete temp;
		}
	}
	return root;
}

void print(Node *root){
	if(root == NULL){
		return;
	}else{
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}


int main(int argc, char** argv) {
	
	Node *root = NULL;
	root = insert(40, root);
	insert(30, root);
	
	print(root);
	
	insert(100, root);
	insert(9, root);
	insert(1, root);
	insert(4, root);
	insert(45, root);
	insert(300, root);
	
	findValue(45, root);

	print(root);
	
	cout<<"\nmax is: "<<findMaximum(root)->data;
	cout<<"\nmin is: "<<findMinimum(root)->data;

	return 0;
}










