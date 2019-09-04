#include "HashNode.h"
#include "HashTable.h"
#include <cstddef>
#include<iostream> 

using namespace std;

template <class K, class V>
HashTable<K,V>::HashTable(int b)
{
	this->size = b;
	this->table = new HashNode<K, V>*[size];

	for (int i = 0; i < size; i++) {
		this->table[i] = NULL;
	}
}

template <class K, class V>
void HashTable<K,V>::insertItem(K key, V val)
{
	int index = hashFunction(key);
	
	HashNode<K,V>* prev = NULL;
	HashNode<K,V>* curr = this->table[index];

	while (curr != NULL && curr->key != key) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		curr = new HashNode<K,V>(key, val);

		if (prev == NULL) {
			this->table[index] = curr;
		}
		else {
			prev->next = curr;
		}
	}
	else {
		curr->val = val;
	}
}

template <class K, class V>
void HashTable<K,V>::deleteItem(K key)
{
	// get the hash index of key 
	int index = hashFunction(key);

	HashNode<K,V>* prev = NULL;
	HashNode<K,V>* curr = this->table[index];

	while (curr != NULL && curr->key != key) {
		prev = curr;
		curr = curr->next;
	}


	if (prev != NULL && curr != NULL) {
		prev->next = curr->next;
		delete curr;
	}
	else if(prev == NULL && curr != NULL){
		this->table[index] = curr->next;
	}

}

template <class K, class V>
int HashTable<K,V>::hashFunction(K key) {
	return (key % size);
}

// function to display hash this->table 
template <class K, class V>
void HashTable<K,V>::displayHash() {
	for (int i = 0; i < size; i++) {
		cout << i;
		HashNode<K,V>* cur = this->table[i];

		while (cur != NULL) {
			cout << "---> (" << cur->key << " , " << cur->val << ")";
			cur = cur->next;
		}
		cout << endl;
	}
}


