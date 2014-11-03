#ifndef LEFTIST_H
#define LEFTIST_H
#include "PQ.h"

class Leftist : public PQ
{
public:
	Leftist(string);
	~Leftist();
	void insert(ItemType &, Node *);
	void insert(ItemType &); 
	ItemType deleteMax();
	void merge(PQ *h); 
	Node* merge(Node*, Node*);
	string toString(int size)const;
	string treeString(Node *, string)const;
	Node* findParent(Node *, Node*)const;
	bool isHappy(ItemType &);	
private:
	string indent = " ";
	Node *root;
};
#endif

