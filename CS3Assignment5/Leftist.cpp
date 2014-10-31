#include "Leftist.h"
#include <math.h>


Leftist::Leftist(string n, int h)
{
	name = n;
	size = 0;
	lHeap = new ItemType[lHeapSize];
	lHeapSize = h;
}

void Leftist::insert(ItemType & i)
{
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
	stringstream ss;
	ss << name << "  current size=" << size;

	for (int i = 0; i < printSize; i++)
	{
		ss << lHeap[i].toString() + indent;
		if (i == 0) ss << "\n";
	}
	string returnSt;
	ss >> returnSt;
	return returnSt;
}
bool Leftist::isHappy(ItemType &)
{
	return true;
}
Leftist::~Leftist()
{
}
