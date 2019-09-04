#include <iostream>
#include <assert.h>
#include <stdio.h>

using namespace std;

template <typename V>
class Node {

  public:
    V data;
    Node<V>* next;

    Node(V d);

};


template <typename V>
class LinkedList {

  public:
    int size;
    Node<V>* head;

    LinkedList();
    ~LinkedList();

    void insert(V d);
    void remove(int index);
    V get(int index);

    void reverse();
    void print();

};

template <typename V>
Node<V>::Node(V d) : data(d) {
  next = NULL;
}

template <typename V>
LinkedList<V>::LinkedList(): size(0) {
  head = NULL;
}

template <typename V>
LinkedList<V>::~LinkedList() {
  Node<V>* prev = NULL;
  
  while(head != NULL ) {
    prev = head;
    head = head->next;

    delete prev;

  }

  delete head;

}

template <typename V>
void LinkedList<V>::insert(V d) {
  Node<V>* cur = head;

  Node<V>* entry = new Node<V>(d);

  if(head == NULL) {
    head = entry;
    size++;
    return;
  }

  while(cur->next != NULL) {
    cur = cur->next;

  }

  cur->next = entry;
  size++;

}

template <typename V>
V LinkedList<V>::get(int index) {
  if(index >= size) {
    return 0;
  }

  Node<V>* curr = head;
  
  while(index > 0) {
    curr = curr->next;

    index--;
  }

  return curr->data;
}

template <typename V>
void LinkedList<V>::remove(int index) {
  if(index >= size) {
    return;
  }

  Node<V>* curr = head;
  Node<V>* prev = NULL;

  while(index > 0) {
    prev = curr;
    curr = curr->next;
    index--;
  }

  if(prev == NULL) {
    prev = head;
    head = head->next;

    delete prev;
  } else {
    prev->next = curr->next;

    delete curr;
  }

  size--;
}



template <typename V>
void LinkedList<V>::reverse() {
  Node<V>* prev = NULL;
  Node<V>* curr = head;
  Node<V>* next = NULL;
 
  while(curr != NULL) {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }

  head = prev;


}

template <typename V>
void LinkedList<V>::print() {
  Node<V>* cur = head;

  while(cur != NULL) {
    cout << cur->data << "--->";
    cur = cur->next;
  }

  cout << "size=" << size << endl;
}

int main() {
  LinkedList<int> list;

  for(int i = 0; i < 100; i++) {
    list.insert(i);

  }

  list.print();

  assert(list.get(10) == 10);



  LinkedList<string> listStr;

  listStr.insert("data");
  listStr.print();

  assert(listStr.get(0) == "data");

  LinkedList<char> listChar;

  for(int i = 32; i < 127; i++) {
    listChar.insert(i);

  }

  listChar.print();



}
