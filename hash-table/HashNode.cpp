#include "HashNode.h"

template<class K, class V>
HashNode<K,V>::HashNode(K k, V v) :key(k), val(v), next() {}
