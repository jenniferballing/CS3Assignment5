#include "Leftist.h"
#include <math.h>

void checkSwap(Node*, Node*);

Leftist::Leftist(string n)
{
	name = n;
	size = 0;
}

void Leftist::insert(ItemType &i)
{
	//if this is the first element create a node with no children
	if (root == NULL)
	{
		root = new Node(i, NULL, NULL);
		return;
	}

	insert(i, root);	
}
void Leftist::insert(ItemType &i, Node *parent)
{
	if (i.priority > parent->element.priority)
	{
		Node * grandP, *newParent;
		if (parent != root)
		{
			grandP = findParent(parent, root);
			newParent = new Node(i, NULL, parent);
			grandP->right = newParent;
			parent = newParent;
		}
		else
		{
			root = new Node(i, NULL, parent);
			parent = root;
		}
	}
	else if (parent->right == NULL)
	{
		Node *newNode = new Node(i, NULL, NULL);
		parent->right = newNode;
	}
	else insert(i, parent->right);

	//check for swap
	if (parent->left != NULL && parent->right != NULL)
	{
		if (parent->left->npl > parent->right->npl)
		{
			Node* temp = parent->right;
			parent->right = parent->left;
			parent->left = temp;
		}
	}
	if (parent->left == NULL && parent->right != NULL)
	{
		Node* temp = parent->right;
		parent->right = parent->left;
		parent->left = temp;
	}
}

Node* Leftist::findParent(Node* child, Node* root) const
{
	if (root == NULL) return NULL;
	if (root->left == child || root->right == child) return root;
    return	findParent(child, root->right);
	return findParent(child, root->left);
}
ItemType Leftist::deleteMax()
{
	Node* oldRoot = root;
	Node* right = NULL, *left=NULL;
	if (root->right != NULL) right = root->right;	
	if(root->left != NULL) left = root->left;

	if (right->element.priority > left->element.priority) root = right;	
	else if (left->element.priority > right->element.priority) root = left;
	
	Node *returned = merge(right, left);	
	return oldRoot->element;	
}
Node* Leftist::merge(Node* right, Node* left)
{
	if (right == NULL)return left;
	if (left == NULL)return right;
	Node* newRoot = NULL;

	if (right->element.priority > left->element.priority)
	{		
		right = merge(right->right, left);
		newRoot = right;
	}
	else if (left->element.priority > right->element.priority)
	{
		left = merge(right, left->right);
		newRoot = left;
	}


	checkSwap(right, left);
	return newRoot;
}
void checkSwap(Node* one, Node* two)
{
	if (one != NULL && two != NULL)
	{
		if (one->npl > two->npl)
		{
			Node* temp = two;
			two = one;
			one = temp;
		}
	}
	if (one == NULL && two != NULL)
	{
		Node* temp =two;
		two = one;
		one = temp;
	}
}
void Leftist::merge(PQ *h)
{
}
string Leftist::toString(int printSize)const
{
	if (printSize > size)printSize = size;
	string tree = name;// +" current size = " + to_string(size);
	string i = "  ";
	tree += treeString(root, i);
	return tree;
}
string Leftist::treeString(Node *i, string indent)const
{
	string left, right;
	if (i == NULL) return "";
	else
	{
		Node * parent;
		parent = findParent(i, root);
	}

	if (i->left != NULL)left = "\n" + treeString(i->left, indent + "   ");
	else left = "";
	if (i->right != NULL)right = "\n" + treeString(i->right, indent + "   ");
	else right = "";

	return right + indent + i->element.word + left + "\n";	
}

bool Leftist::isHappy(ItemType &)
{
	return true;
}
Leftist::~Leftist()
{
}
