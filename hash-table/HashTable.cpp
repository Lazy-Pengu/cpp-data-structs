#include "HashTable.h"
#include "HashNode.h"


HashTable::HashTable(int b)
{
	this->size = b;
	table = new HashNode*[size];

	for (int i = 0; i < size; i++) {
		table[i] = NULL;
	}
}

void HashTable::insertItem(int key, int val)
{
	int index = hashFunction(key);
	
	HashNode* prev = NULL;
	HashNode* curr = table[index];

	while (curr != NULL && curr->key != key) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		curr = new HashNode(key, val);

		if (prev == NULL) {
			table[index] = curr;
		}
		else {
			prev->next = curr;
		}
	}
	else {
		curr->val = val;
	}
}

void HashTable::deleteItem(int key)
{
	// get the hash index of key 
	int index = hashFunction(key);

	HashNode* prev = NULL;
	HashNode* curr = table[index];

	while (curr != NULL && curr->key != key) {
		prev = curr;
		curr = curr->next;
	}


	if (prev != NULL && curr != NULL) {
		prev->next = curr->next;
		delete curr;
	}
	else if(prev == NULL && curr != NULL){
		table[index] = curr->next;
	}

}

int HashTable::hashFunction(int key) {
	return (key % size);
}

// function to display hash table 
void HashTable::displayHash() {
	for (int i = 0; i < size; i++) {
		cout << i;
		HashNode* cur = table[i];

		while (cur != NULL) {
			cout << "---> (" << cur->key << " , " << cur->val << ")";
			cur = cur->next;
		}
		cout << endl;
	}
}


