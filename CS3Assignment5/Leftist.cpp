#include "Leftist.h"
#include <math.h>


Leftist::Leftist(string n)
{
	name = n;
}

void Leftist::insert(ItemType &i)
{
	//if this is the first element create a node with no children
	if (root == NULL)
	{
		root = new Node(i, NULL, NULL);
		return;
	}

	insert(i, root->right, root->left);	
}
void Leftist::insert(ItemType &i, Node *r, Node*l)
{
	//if there is no right child, make one
	if (r == NULL)
	{
		Node *newNode = new Node(i, NULL, NULL);
		r = newNode;
	}

	//if there is a right child, keep moving down
	if (r->right != NULL)
	{
		insert(i, r->right, r->left);
	}

	//check for swap
	if (l != NULL)
	{
		if (r->npl < l->npl)
		{
			Node *temp = r;
			r = l;
			l = temp;
		}
	}
}
ItemType Leftist::deleteMax()
{
	ItemType j;
	return j;
}
void Leftist::merge(PQ *h)
{
}
string Leftist::toString(int printSize)const
{
	if (printSize > size)printSize = size;
	string tree = name + " current size = " + to_string(size);
	tree += treeString(root);
	return tree;
}
string Leftist::treeString(Node *i)const
{
	return i->element.word + "\n" + treeString(i->left) + treeString(i->right) + "\n";
}

bool Leftist::isHappy(ItemType &)
{
	return true;
}
Leftist::~Leftist()
{
}
