#include<iostream> 
using namespace std;

#include "HashTable.h"

int main()
{
	// array that contains keys to be mapped 
	int n = 100;

	// insert the keys into the hash table 
	HashTable h(10); // 7 is count of buckets in 
				// hash table 
	for (int i = 0; i < n; i++)
		h.insertItem(i, i);


	h.displayHash();

	return 0;
}