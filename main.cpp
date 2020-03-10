#include <iostream>
#include "node.h"
#include <cstring>

using namespace std;

int main(){
  cout << "Console or File?" << endl;
  char input[99];
  cin.getline(input, 99);
  if (strcmp(input, "Console") == 0) {
    cout << "Enter input" << endl;
  }
  else if (strcmp(input, "File") == 0) {
    cout << "Enter file name" << endl;
  }
}
