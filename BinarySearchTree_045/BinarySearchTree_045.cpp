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

	void search(string element, node*& parent, node*& currentNode)
	{
		// this function searches the current node of the specified node as well as the current node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	} 

	void inorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << "  ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << "  ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}  

	void postorder(node* ptr)
	{
		//performs the postorder traversal of the tree
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << "  ";
		}
	} 
};

int main()
{
	BinaryTree obj;
	while (true)
	{
		cout << "\nMENU" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5.Exit" << endl;
		cout << "\nEnter Your Choice(1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case'1': {
			cout << "Enter a word: ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case'2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case'3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
		case'4':
		{
			obj.postorder(obj.ROOT);
			break;
		}
		case'5':
			return 0;
		default:
		{
			cout << "invalid option" << endl;
			break;
		}
		}

	}
}