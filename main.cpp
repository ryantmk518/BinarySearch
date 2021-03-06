#include <iostream>
#include "node.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include "stdlib.h"

//Ryan Thammakhoune Binary Search Tree. Add integers to a binary tree. Can check if int is in tree. Can remove int from tree. Type Console to keep adding integers to the tree.

using namespace std;

void add(Node* parent, int value, int side); //Initialize functions
void print(Node* head, int space);
void search(Node* head, int num);
void remove(Node* head, Node* first, int num);
Node* twoChild(Node* head);

int main(){
  bool quit = false;
  Node* head = new Node(NULL); //Head node
  while (quit == false) {
    cout << "Enter Console, File, Search, Remove, or Quit" << endl;
    char input[99];
    cin.getline(input, 99);
    if (strcmp(input, "Console") == 0) { //Enter through console
      cout << "Enter input separated by spaces" << endl;
      char in[999];
      cin.getline(in, 999);
      int* array = new int[999];
      int a = 0;
      char* token = strtok(in, " ");
      while (token != NULL) { //Split the input
        array[a] = atoi(token);
        token = strtok(NULL, " ");
        ++a;
      }
      if (head->getValue() == NULL) { //If tree does not exist
        cout << "New tree" << endl;
        add(head, array[0], 2);
        for(int i = 1; i < a; i++) {
          add(head, array[i], 0);
        }
      }
      else { //If tree already exists
        for (int i =0; i<a; i++) {
          add(head, array[i], 0);
        }
      }
      print(head, 0); //Print the tree
      cout << "\n";
    }
    else if (strcmp(input, "File") == 0) { //Enter through file
      cout << "Enter file name" << endl;
      char fname[99];
      cin.getline(fname, 99);
      ifstream file;
      file.open(fname);
      char* output = new char[999];
      int* array = new int[999];
      int i = 0;
      while (!file.eof()) { //While not end of file, get char
        file.get(output[i]);
        i++;
      }
      char* split = strtok(output, " ");
      int a = 0;
      while (split!=NULL) { //Split the char array
        array[a] = atoi(split);
        split = strtok(NULL, " ");
        ++a;
      }
      add(head, array[0], 2);
      for (int i =0; i<a; i++) { //Add them into the tree
        add(head, array[i], 0);
      }
      print(head, 0);
      cout << "\n";
    }
    else if (strcmp(input, "Search") == 0) { //Search
      char input[99];
      cout << "Enter search integer" << endl;
      cin.getline(input, 99);
      int num = atoi(input); //Gets num
      search(head, num);
    }
    else if (strcmp(input, "Remove") == 0) { //Remove
      char input[99];
      cout << "Enter integer to remove" << endl;
      cin.getline(input, 99);
      cout << "\n" << endl;
      int num = atoi(input);
      remove(head, head, num);
      print(head, 0);
    }
    else if (strcmp(input, "Quit") == 0) { //Quit
      quit = true;
      return 0;
    }
  }
}

void remove(Node* head, Node* first, int num) {
  if (head == NULL) { //If tree doesn't exist
    return;
  }
  else if (head->getValue() < num) { //Go right
    if (head->getRight() -> getValue() == num) { //If right is the int we want
      if (head->getRight()->getRight() == NULL && head->getRight()->getLeft() == NULL) { //No child case
        head->setRight(NULL);
      }
      else if (head->getRight()->getLeft() != NULL && head->getRight()->getRight() == NULL) { //One child case
        int newValue = head->getRight()->getLeft()->getValue();
        remove(first, first, newValue);
        head->getRight()->setValue(newValue);
      }
      else if (head->getRight()->getRight() != NULL && head->getRight()->getLeft() == NULL) { //One child case
        int newValue = head->getRight()->getRight()->getValue();
        remove(first, first, newValue);
        head->getRight()->setValue(newValue);
      }
      else if (head->getRight() -> getRight() != NULL && head->getRight()->getLeft() != NULL) { //Two child case
        int newValue = twoChild(head->getRight()->getRight())->getValue();
        remove(first, first, twoChild(head->getRight()->getRight())->getValue());
        head->getRight()->setValue(newValue);
      }
    }
    else {
      remove(head->getRight(), first, num);
    }
  }
  else if (head->getValue() > num) { //Go left
    if (head->getLeft() -> getValue() == num) {
      if (head->getLeft()->getRight() == NULL && head->getLeft()->getLeft() == NULL) { //No child case
        head->setLeft(NULL);
      }
      else if (head->getLeft()->getLeft() != NULL && head->getLeft()->getRight() == NULL) { //One child case
        int newValue = head->getLeft()->getLeft()->getValue();
        remove(first, first, newValue);
        head->getLeft()->setValue(newValue);
      }
      else if (head->getLeft()->getRight() != NULL && head->getLeft()->getLeft() == NULL) { //One child case
        int newValue = head->getLeft()->getRight()->getValue();
        remove(first, first, newValue);
        head->getLeft()->setValue(newValue);
      }
      else if (head->getLeft() -> getRight() != NULL && head->getLeft()->getLeft() != NULL) { //Two child case
        int newValue = twoChild(head->getLeft()->getRight())->getValue();
        remove(first, first, twoChild(head->getLeft()->getRight())->getValue());
        head->getLeft()->setValue(newValue);
      }
    }
    else {
      remove(head->getLeft(), first, num);
    }
  }
  else if (head->getValue() == num) { //If the head is the delete num
    int newValue = head->getRight()->getValue();
    remove(first, first, newValue);
    head->setValue(newValue);
  }
}

Node* twoChild(Node* head) { //Goes all the way left until null
  if (head->getLeft() != NULL) {
    twoChild(head->getLeft());
  }
  else {
    return head;
  }
}

void search(Node* head, int num) { //Search
  if (head == NULL) { //Cannot find it
    cout << "Not found" << endl;
  }
  else if (head->getValue() == num) { //If it is found
    cout << "Int is found" << "\n" << endl;
  }
  else if (head->getValue() < num) { //Search right
    search(head->getRight(), num);
  }
  else if (head->getValue() > num) { //Search left
    search(head->getLeft(), num);
  }
}

void print(Node* head, int space){ //Print
  if (head == NULL){ //If tree is empty
    return;
  }
  space += 5; //Amount of spaces
  print(head->getRight(), space);
  cout << "\n";
  for (int i = 5; i < space; i++){ //Prints spaces
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
