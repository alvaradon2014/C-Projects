// Nayely Alvarado EE3223
// Test 2 Day 2
// This program implements functions
// of a linked lists



#include <iostream>
#include <string>

using namespace std;

struct Node {
	int data;
	Node* next;
};

// Initialize the Linked List (create first node)
void initNode(struct Node *head, int n) {
	
	//INSERT HERE
	Node *start = *head;
	start->data = n;
	
}

// Add a node to the back of the list
void addNode(struct Node *head, int n) {
	// INSERT HERE
	
	Node *temp;
	temp = new(struct Node);
	temp->prev = NULL;
	temp->info = n;
	temp->next = head;
	head->prev = temp;
	head = temp;
}

// Insert a node at the front of the list (new head node)
void insertFront(struct Node **head, int n) {
	// INSERT HERE
	Node *tmp = *head;
	tmp->data = n;
	
	
}

struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if (cur->data == n) return cur;
		cur = cur->next;
	}
	cout << "No Node" << n << " in list.\n";
	return NULL;
}

bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	while(cur) {
		if(cur->next == ptrDel){
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

// Reverse the list
struct Node* reverse(struct Node** head)
{
	Node *parent = *head;
	Node *me = parent->next;
	Node *child = me->next;
	
	// make parent as tail
	parent->next = NULL;
	while(child) {
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}

// Create copy of a linked list
void copyLinkedList(struct Node *node, struct Node**pNew)
{
	if(node != NULL) {
		*pNew = new Node;
		(*pNew)->data = node->data;
		(*pNew)->next = NULL;
		copyLinkedList(node-Next, &((*pNew)->next));
	}
}

// Comparae two linked list
// return value same(1) different(0)
int compareLinkedList(struct Node *node1, struct Node *node2)
{
	static int flag;
	
	// both lists null
	if(node1 == NULL && node2 == NULL){
		flag = 1;
	}
	else {
	if(node1 == NULL || node2 == NULL)
		flag = 0;
	else if(node1->data != node2->data)
		flag = 0;
	else
		compareLinkedList(node->next, node2->next)
	}
	return flag
}

void deleteLinkedList(struct Node **node)
{
	struct Node *tmpNode;
	while(*node) {
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list - list->next;
	}
	cout << endl;
	cout << endl;
}

int main
{
	struct Node *newHead;
	struct *head = new Node;

initNode(head, 10);
	display(head);
	
	addNode(head,20);
	display(head);
	
	addNode(head,30);
	display(head);
		
	addNode(head,35);
display(head);

addNode(head, 40);
display(head);

insertFront(&head,5);
display(head);

int numDel = 5;
Node *ptrDelete = searchNode(head, numDel);
if(deleteNode(&head,ptrDelete))
	cout << "Node " << numDel << " deleted!\n";
display(head);

cout << "The list is reversed\n";
revers(&head);
display(head);

cout << "The list is copied\n";
copyLinkedList(head,&newHead);
display(newHead);

cout << "Comparing lists...\n";
cout << "Are the two lists the same?\n";
if(compareLinkedList(head,newHead))
	cout << "yes\n";
else
	cout << "no\n";

	return (0);
}
