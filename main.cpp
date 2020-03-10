#include <iostream>
#include "node.h"
#include <cstring>

using namespace std;

void add(Node* parent, int value, int side);

int main(){
  Node* head = new Node(NULL);
  cout << "Console or File?" << endl;
  char input[99];
  cin.getline(input, 99);
  if (strcmp(input, "Console") == 0) {
    cout << "Enter input separated by spaces" << endl;
    char in[999];
    cin.getline(in, 999);
    int* array = new int[999];
    int a = 0;
    char* token = strtok(in, " ");
    while (token != NULL) {
      array[a] = atoi(token);
      token = strtok(NULL, " ");
      ++a;
    }
    add(head, array[0], 2);
    cout << head -> getValue() << endl;
    for(int i = 1; i < a; i++) {
      add(head, array[i], 0);
    }
  }
  else if (strcmp(input, "File") == 0) {
    cout << "Enter file name" << endl;
  }
}

void add(Node* parent, int value, int first) {
  if (first == 2) {
    parent -> setValue(value);
  }
  else {
    if (value > *parent->getValue()) {
      Node* head = parent -> getLeft();
      add(head, value, 0);
    }
  }
}
