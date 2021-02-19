#include <iostream>
#include "sqlite3.h"

int add(int x, int y) { return x + y; }

int main(int argc, char *argv[]) {
  std::cout << "Hello, World!\n";
  std::cout << add(1, 1) << std::endl;
  return 0;
}
 
