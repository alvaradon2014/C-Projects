


#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
	int val;
	Node* left;
	Node* right;

public:
	Node();
	Node(int);
	bool set_left(Node*);
	Node* get_left();
	bool set_right(Node*);
	Node* get_right();
	int get_val();
	bool set_val(int);
};

Node::Node() {
	val = 0;
	left = right = NULL;
}

Node::Node(int v) {
	val = v;
	left = right = NULL;
}

bool Node::set_left(Node* n) {
	left = n;
	return true;
}

bool Node::set_right(Node* n) {
	right = n;
	return true;
}

Node* Node::get_left() {
	return left;
}

Node* Node::get_right() {
	return right;
}

int Node::get_val() {
	return val;
}

bool Node::set_val(int v) {
	val = v;
	return true;
}

class BST {
private:
	Node* root;
	void preorder(Node*);
	// Implement an inorder display as part of Part C
	// left -> root -> right
	void inorder(Node*);
	void cleanUp(Node*);

public:
	BST();
	~BST();
	bool add(int);
	bool is_present(int);
	void display();

	//implement these functions

	//part (a)
	//(10 points) Implement a function called void copy_bst(BST * bst) that
	// copies all the nodes from one BST into another BST
	void copy_bst(BST * bst);

	//part (b)
	//(10 points) Implement a function called bool remove_all(vector<int>& v)
	//that removes all elements of v from the tree. Return true if all
	//elements were removed successfully. False otherwise (e.g., when v
	//is not found in the tree).
	bool remove_all(vector<int>&);

	//part (c)
	//(10 points) Implement the private void inorder(Node*) function to retrurn
	// the inorder sequence of the tree nodes. Set the display function to use
	// your inorder function instead of the preorder function it uses currently.


	//part (d)
	//(20 points) Implement a function called 
	//int count_less_than(int v) that returns the number of values in the tree 
	//that are less than v. Do not modify the existing add function.
	int count_less_than(int);
};

BST::BST() {
	root = NULL;
}

BST::~BST() {
	cout << "deleting..." << endl;
	cleanUp(root);
	cout << endl;
}

void BST::cleanUp(Node* curr) {
	if (curr != NULL) {
		cout << curr->get_val() << " ";
		cleanUp(curr->get_left());
		cleanUp(curr->get_right());
		delete curr;
	}
}

bool BST::add(int v) {
	Node* temp = new Node(v);
	if (root == NULL) {
		root = temp;
		return true;
	}
	Node* curr = root;

	while (curr != NULL) {
		if (curr->get_val() == v) {
			delete temp;
			return false;
		}
		else if (v<curr->get_val()) {
			if (curr->get_left() == NULL) {
				curr->set_left(temp);
				return true;
			}
			else
				curr = curr->get_left();
		}
		else {
			if (curr->get_right() == NULL) {
				curr->set_right(temp);
				return true;
			}
			else
				curr = curr->get_right();
		}
	}
}

// Part (a)
void BST::copy_bst(BST * bst) {
	Node* curr = this->root;
	Node* temp = bst->root;
	
	while (curr != NULL) {
		if (curr->get_val() == temp->get_val())
			return;					// No duplicates
		else if (curr->get_val() < curr->get_val()) {
			if (curr->get_left() == NULL) {
				curr->set_left(temp);		// Adds in value from old tree
				return;
			}
			else
				curr = curr->get_left();	// Moves left to find where to insert
		}
		else {
			if (curr->get_right() == NULL) {
				curr->set_right(temp);		// Adds in value from old tree
				return;
			}
			else
				curr = curr->get_right();	// Moves right to find where to insert
		}
	}
}


// Part (d)
int BST::count_less_than(int v) {
	Node* curr = root;
	int count = 0;
	
	while (curr != NULL) {
		if (curr->get_val() >= v)
			curr = curr->get_left();
		else {
			count++;
			curr = curr->get_left();
		}
	}
	cout << "There are " << count << " node(s) with values less than " << v << endl;
	return(count);
}

bool BST::is_present(int v) {
	Node* curr = root;

	while (curr != NULL) {
		if (curr->get_val() == v)
			return true;
		else if (v > curr->get_val())
			curr = curr->get_right();
		else
			curr = curr->get_left();
	}
	return false;
}



// Part (b)
bool BST::remove_all(vector<int>& del) {
	Node* curr = root;
	bool flag = false;

	while (curr != NULL) {
		if (curr->get_val() == del[0]) {
			delete curr;
			flag = true;
		}
		else if (del[0] > curr->get_val())
			curr = curr->get_right();
		else
			curr = curr->get_left();
	}
	return(flag);

}


void BST::display() {
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
}

void BST::preorder(Node* curr) {
	if (curr != NULL) {
		cout << curr->get_val() << " ";
		preorder(curr->get_left());
		preorder(curr->get_right());
	}
}


// Part (c)
void BST::inorder(Node* curr) {
	if (curr != NULL) {
		inorder(curr->get_left());
		cout << curr->get_val() << " ";
		inorder(curr->get_right());
	}
}




int main() {
	BST b;
	BST a;		// to copy into later

	vector<int> test = {15, 7};

	b.add(20);
	b.add(25);
	b.add(15);
	b.add(10);
	b.add(18);
	b.display();
	
	//test your new functionalities here
	b.count_less_than(17);
	b.remove_all(test);

	a.add(5);		// Set up test tree
	a.add(10);
	a.display();
	a.copy_bst(&b);		// Copy b tree values into a tree
	a.display();

	// To observe display
	while (1) {
		int a;
		cin >> a;
		if (a == 0)
			break;
	}

	return(0);
}