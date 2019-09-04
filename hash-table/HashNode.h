#pragma once

template<typename K, typename V>
class HashNode {
public:
	K key;
	V val;
	HashNode<K, V>* next;

	HashNode(K key, V val);
};

