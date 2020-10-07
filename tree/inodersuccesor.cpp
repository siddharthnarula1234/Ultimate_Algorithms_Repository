// C++ Program to find inorder successor. 
#include<bits/stdc++.h> 
using namespace std; 


struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 

// Function to create a new Node. 
Node* newNode(int val) 
{ 
	Node* temp = new Node; 
	temp->data = val; 
	temp->left = NULL; 
	temp->right = NULL; 
	
	return temp; 
} 
void inorderSuccessor(Node* root, 
					Node* target_node, 
					Node* &next) 
{ 
	// if root is null then return 
	if(!root) 
		return; 

	inorderSuccessor(root->right, target_node, next); 
	
	// if target node found then enter this condition 
	if(root->data == target_node->data) 
	{ 
		// this will be true to the last node 
		// in inorder traversal i.e., rightmost node. 
		if(next == NULL) 
			cout << "inorder successor of "
				<< root->data << " is: null\n"; 
		else
			cout << "inorder successor of "
				<< root->data << " is: "
				<< next->data << "\n"; 
	} 
	next = root; 
	inorderSuccessor(root->left, target_node, next); 
} 

// Driver Code 
int main() 
{ 
	
	// Let's construct the binary tree 
	// as shown in above diagram. 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 
	
	// Case 1 
	Node* next = NULL; 
	inorderSuccessor(root, root->right, next); 

	// case 2 
	next = NULL; 
	inorderSuccessor(root, root->left->left, next); 

	// case 3 
	next = NULL; 
	inorderSuccessor(root, root->right->right, next); 
	
	return 0; 
} 
