#include<iostream> 
using namespace std;

#include "HashTable.h"

int main()
{
	// array that contains keys to be mapped 
	int n = 100;

	// insert the keys into the hash table 
	HashTable<int, int> h(10); 

  for (int i = 0; i < n; i++)
		h.insertItem(i, i);


	h.displayHash();

	return 0;
}
