#include <iostream>
#include "node.h"
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

void add(Node* parent, int value, int side);
void print(Node* head, int space);

int main(){
  bool quit = false;
  Node* head = new Node(NULL);
  while (quit == false) {
    cout << "Enter Console, File, or Quit" << endl;
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
      if (head ->getValue()== NULL) {
        cout << "Head is null" << endl;
        add(head, array[0], 2);
        for(int i = 1; i < a; i++) {
          add(head, array[i], 0);
        }
      }
      else {
        for (int i =0; i<a; i++) {
          add(head, array[0], 0);
        }
      }
      print(head, 0);
      cout << "\n";
    }
    else if (strcmp(input, "File") == 0) {
      cout << "Enter file name" << endl;
      char fname[99];
      cin.getline(fname, 99);
      ifstream file;
      file.open(fname);
      char* output = new char[999];
      int* array = new int[999];
      int i = 0;
      while (!file.eof()) {
        file.get(output[i]);
        i++;
      }
      char* split = strtok(output, " ");
      int a = 0;
      while (split!=NULL) {
        array[a] = atoi(split);
        split = strtok(NULL, " ");
        ++a;
      }
      add(head, array[0], 2);
      for (int i =0; i<a; i++) {
        add(head, array[i], 0);
      }
      print(head, 0);
      cout << "\n";
    }
    else if (strcmp(input, "Quit") == 0) {
      quit = true;
    }
  }
}

void print(Node* head, int space){
  if (head == NULL){
    return;
  }
  space += 5;
  print(head->getRight(), space);
  cout << "\n";
  for (int i = 5; i < space; i++){
    cout << " ";
  }
  cout << head->getValue() << endl;
  print(head->getLeft(), space);
}

void add(Node* parent, int value, int first) {
  int count = 0;
  if (first == 2) {
    cout << "Set head" << endl;
    parent -> setValue(value);
  }
  else {
    if (value >  parent->getValue()) {
      cout << "Going right" << endl;
      if (parent->getRight() != NULL) {
        cout << "Searching" << endl;
        add(parent -> getRight(), value, 0);
      }
      else {
        cout << "New node" << endl;
        Node* newNode = new Node(value);
        parent->setRight(newNode);
      }
    }
    else if (value < parent->getValue()) {
      cout << "Going left" << endl;
      if (parent -> getLeft() != NULL) {
        cout << "Searching" << endl;
        add(parent->getLeft(), value, 0);
      }
      else {
        cout << "New node" << endl;
        Node* newNode = new Node(value);
        parent->setLeft(newNode);
      }
    }
  }
}
