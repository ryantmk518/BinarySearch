#include <iostream>
#include "node.h"

using namespace std;

//Node class

Node::Node(int* newvalue) {
  value = newvalue;
  right = NULL;
  left = NULL;
}

Node::~Node() {
  value = NULL;
}

void Node::setValue(int* newvalue) {
  value = newvalue;
}

int* Node::getValue() {
  return value;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getLeft() {
  return left;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}
