#include <iostream>
#include "node.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include "stdlib.h"

using namespace std;

void add(Node* parent, int value, int side);
void print(Node* head, int space);
void search(Node* head, int num);
void remove(Node* head, int num);
void twoChild(Node* head, int num);

int main(){
  bool quit = false;
  Node* head = new Node(NULL);
  while (quit == false) {
    cout << "Enter Console, File, Search, Remove, or Quit" << endl;
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
    else if (strcmp(input, "Search") == 0) {
      char input[99];
      cout << "Enter search integer" << endl;
      cin.getline(input, 99);
      int num = atoi(input);
      search(head, num);
    }
    else if (strcmp(input, "Remove") == 0) {
      char input[99];
      cout << "Enter integer to remove" << endl;
      cin.getline(input, 99);
      cout << "\n" << endl;
      int num = atoi(input);
      remove(head, num);
      print(head, 0);
    }
    else if (strcmp(input, "Quit") == 0) {
      quit = true;
    }
  }
}

void remove(Node* head, int num) {
  if (head == NULL) {
    cout << "Head is null" << endl;
    return;
  }
  else if (head->getValue() < num) {
    if (head->getRight() -> getValue() == num) {
      if (head->getRight()->getRight() == NULL && head->getRight()->getLeft() == NULL) {
        cout << "No child" << endl;
        head->setRight(NULL);
      }
      else if (head->getRight()->getLeft() != NULL && head->getRight()->getRight() == NULL) {
        cout << "One child" << endl;
        Node* newNode = new Node(head->getRight()->getLeft()->getValue());
        head->setRight(newNode);
      }
      else if (head->getRight()->getRight() != NULL && head->getRight()->getLeft() == NULL) {
        cout << "One child" << endl;
        Node* newNode = new Node(head->getRight()->getRight()->getValue());
        head->setRight(newNode);
      }
      else if (head->getRight() -> getRight() != NULL && head->getRight()->getLeft() != NULL) {
        cout << "Two child" << endl;
        
      }
    }
    else {
      remove(head->getRight(), num);
    }
  }
  else if (head->getValue() > num) {
    if (head->getLeft() -> getValue() == num) {
      if (head->getLeft()->getRight() == NULL && head->getLeft()->getLeft() == NULL) {
        cout << "No child" << endl;
        head->setLeft(NULL);
      }
      else if (head->getLeft()->getLeft() != NULL && head->getLeft()->getRight() == NULL) {
        cout << "One child" << endl;
        Node* newNode = new Node(head->getLeft()->getLeft()->getValue());
        head->setLeft(newNode);
      }
      else if (head->getLeft()->getRight() != NULL && head->getLeft()->getLeft() == NULL) {
        cout << "One child" << endl;
        Node* newNode = new Node(head->getLeft()->getRight()->getValue());
        head->setLeft(newNode);
      }
      else if (head->getLeft() -> getRight() != NULL && head->getLeft()->getLeft() != NULL) {
        cout << "Two child" << endl;

      }
    }
    else {
      remove(head->getLeft(), num);
    }
  }
  else if (head->getValue() == num) {
    cout << "Head is num" << endl;
  }
}

void twoChild(Node* head, int direction) {
  
}

void search(Node* head, int num) {
  if (head == NULL) {
    cout << "Not found" << endl;
  }
  else if (head->getValue() == num) {
    cout << "Int is found" << "\n" << endl;
  }
  else if (head->getValue() < num) {
    search(head->getRight(), num);
  }
  else if (head->getValue() > num) {
    search(head->getLeft(), num);
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
  if (first == 2) { //Set head
    parent -> setValue(value);
  }
  else {
    if (value >  parent->getValue()) { //Going right
      if (parent->getRight() != NULL) {
        add(parent -> getRight(), value, 0);
      }
      else {
        cout << "New node" << endl;
        Node* newNode = new Node(value);
        parent->setRight(newNode);
      }
    }
    else if (value < parent->getValue()) {
      if (parent -> getLeft() != NULL) { // Going left
        add(parent->getLeft(), value, 0);
      }
      else { // New node
        Node* newNode = new Node(value);
        parent->setLeft(newNode);
      }
    }
  }
}
