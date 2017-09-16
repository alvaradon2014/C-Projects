// EE 3223 Homework 7
// Nayely Alvarado


#include <iostream>
#include <string>
using namespace std;

// Non-Recursive Functions for TreeNode

struct TreeNode {
// An object of type TreeNode represents one node
// in a binary tree of strings.

	string item;      // The data in this node.
	TreeNode * left;    // Pointer to left subtree.
	TreeNode * right;   // Pointer to right subtree.

	TreeNode(string str) {
	// Constructor.  Make a node containing str.
		item = str;
		left = NULL;
		right = NULL;
	}
};  // end struct Treenode

void treeContains(TreeNode *root, const string item) {
// Return true if item is one of the items in the binary
// sort tree to which root points.   Return false if not.
	if (root == NULL) {
		// Tree is empty, so it certainly doesn't contain item.
		cout << "Tree is empty" << endl;
	}
	else if (item == root->item) {
		// Yes, the item has been found in the root node.
		cout << "Found" << endl;
	}
	else if (item < root->item) {
		// If the item occurs, it must be in the left subtree.
		treeContains(root->left, item);
	}
	else {
		// If the item occurs, it must be in the right subtree.
		treeContains(root->right, item);
	}
}  // end treeContains()


void treeOrder(TreeNode *root){
	if (!root) {
		return;
	}
	treeOrder(root->left);
	
	cout << root->item << endl;
	
	treeOrder(root->right);
}


void treeInsert(TreeNode * &root, const string newItem) {
	// Add the item to the binary sort tree to which the parameter
	// "root" refers.  Note that root is passed by reference since
	// its value can change in the case where the tree is empty.
	if (root == NULL) {
	// The tree is empty.  Set root to point to a new node containing
	// the new item.  This becomes the only node in the tree.
		root = new TreeNode(newItem);
	// NOTE:  The left and right subtrees of root
	// are automatically set to NULL by the constructor.
	// This is important!
		return;
	}
	else if (newItem < root->item) {
		treeInsert(root->left, newItem);
	}
	else {
		treeInsert(root->right, newItem);
	}
}  // end treeInsert()

int main() {

	TreeNode * root;  // Pointer to the root node in the tree.
	root = NULL;     // Start with an empty tree.
	
	treeInsert(root, "John");
	treeInsert(root, "Mary");
	treeInsert(root, "Tim");
	treeInsert(root, "Jose");
	treeInsert(root, "Alice");
		
	treeOrder(root);
	
	treeContains(root, "Jose");

	return(0);
}





