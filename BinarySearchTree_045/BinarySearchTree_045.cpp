#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	string info;
	node* leftchild;
	node* rightchild;

	// constuctor for the node class
	node(string i, node* l, node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	node* ROOT;

	BinaryTree() 
	{
		ROOT = NULL; //initializing Root to null
	}

	void insert(string element) // insert a node in the binary search tree
	{
		node* NewNode = new node(element, NULL, NULL); // allocate memory for the new node
		NewNode->info = element; //Assign value to the data field of the new node
		NewNode->leftchild = NULL; //Make the left child of the new node point to null
		NewNode->rightchild = NULL; //Make the right child of the new node point to NULL

		node* parent = NULL;
		node* currentNode = NULL;
		search(element, parent, currentNode); //Locate the node which will be the parent of the node to be inserted

		if (parent == NULL)// if the parent is NULL (Tree is empty)
		{
			ROOT = NewNode;  // mark the new node as ROOT
			return; //Exit
		}

		if (element < parent->info) // if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = NewNode; //make the left child of the parent point to the new node
		}

		else if (element > parent->info) //if the value in the data field of the new node is greater that that of the parent
		{
			parent->rightchild = NewNode; // make the right child of the parent point to the new node
		}
	}