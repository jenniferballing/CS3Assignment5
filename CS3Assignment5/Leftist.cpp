#include "Leftist.h"
#include <math.h>

void swap(Node*, Node*);
int myNPL(Node*);
bool isHappy(Node*);
Node* merge(Node*, Node*);
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
	Node * newNode = new Node(i, NULL, NULL);
	if (root->element.priority>newNode->element.priority)merge(root, newNode);
	else insert(newNode->element, root);	
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
		Node * newNode = new Node(i, NULL, NULL);
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
	if (root->right != NULL && root->left != NULL)
	{
		Node* returned = merge(root->right, root->left);

		if (root->right > root->left) root = root->right;
		if (root->left > root->right) root = root->left;
	}
	if (root->right == NULL) root = root->left;
	if (root->left == NULL) root = root->right;

	return oldRoot->element;
}
Node* Leftist::merge(Node* one, Node* two)
{
	/*if (one->element.priority > two->element.priority)
	{
		Node * grandP, *newParent;
		if (two != root)
		{
			grandP = findParent(two, root);
			newParent = new Node(one->element, NULL, two);
			grandP->right = newParent;
			two = newParent;
		}
		else
		{
			root = new Node(one->element, NULL, two);
			two = root;
		}
	}
	else if (two->right == NULL)
	{
		Node * newNode = new Node(one->element, NULL, NULL);
		two->right = newNode;
	}
	else insert(one->element, two->right);
	return one;*/
	
	/*Node*thisRoot = NULL;
	if (one == NULL) return two;
	if (two == NULL) return one;
	if (one->element.priority < two->element.priority)
	{
		one->right = merge(one->right, two);
		thisRoot = one;
	}
	else
	{
		two->right = merge(two->right, one);
		thisRoot = two;
	}
	if (!isHappy(thisRoot))	swap(one->right, one->left);

	thisRoot->npl = myNPL(thisRoot);*/
	return one;
}
bool isHappy(Node*i)
{
	if (i->right == NULL && i->left == NULL) return true;
	if (i->right == NULL && i->left != NULL) return true;
	if (i->right != NULL && i->left == NULL) return false;
	//return isHappy(i->left) + isHappy(i->right);
}
int myNPL(Node*i)
{
	if (i->left == NULL || i->right == NULL)return 0;
	else return myNPL(i->right);
}
void swap(Node* one, Node* two)
{
	Node* temp = one;
	one = two;
	two = temp;
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

	return "\n" + right + indent + i->element.word + left + "\n";	
}
Leftist::~Leftist()
{
}
