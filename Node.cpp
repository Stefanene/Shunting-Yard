#include <iostream>
#include <cstring>

#include "Node.h"

using namespace std;

Node::Node(char indata) {
  //constructor
  data = indata;
  right = NULL;
  left = NULL;
  next = NULL;
}

Node::~Node() {
  //destructor
}

//setters
void Node::setData(char newData) {
  data = newData;
}

void Node::setRight(Node* newR) {
  right = newR;
}

void Node::setLeft(Node* newL) {
  left = newL;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}

//getters
char Node::getData() {
  return data;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getNext() {
  return next;
}
