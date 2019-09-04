#pragma once

#include "HashNode.h"

template <class K, class V>
class HashTable
{
	int size; // No. of buckets 

	// Pointer to an array containing buckets 
	HashNode<K, V>** table;
public:
	HashTable(int s); // Constructor 

	// inserts a key into hash table 
	void insertItem(K key, V val);

	// deletes a key from hash table 
	void deleteItem(K key);

	// hash function to map values to key 
	int hashFunction(K key);

	void displayHash();
};
