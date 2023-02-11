#include <iostream>
#include "red_black_tree.hpp"


 
int main() {


  ft::tree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(15);
  // tree.insert(6);
  // tree.insert(-13);
  // tree.insert(-69);

  tree.printLevels(tree.getRoot(), 0);

 
  return 0;
}