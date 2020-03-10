#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

//Node Header: Intializes functions and variables

class Node{
 public:
  Node(int*);
  ~Node();
  int* getValue();
  void setValue(int*);
  void setRight(Node*);
  void setLeft(Node*);
  Node* getRight();
  Node* getLeft();
 private:
  int* value;
  Node* right;
  Node* left;
};

#endif
