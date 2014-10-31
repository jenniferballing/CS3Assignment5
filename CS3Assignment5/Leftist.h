#ifndef LEFTIST_H
#define LEFTIST_H
#include "PQ.h"

class Leftist : public PQ
{
public:
	Leftist(string, int);
	~Leftist();
	void insert(ItemType &); 
	ItemType deleteMax();
	void merge(PQ *h);  
	string toString(int size)const;
	bool isHappy(ItemType &);	
private:
	ItemType * lHeap;
	int lHeapSize;
	string indent = " ";
};
#endif

