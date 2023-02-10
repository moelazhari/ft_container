#include <iostream>
#include "red_black_tree.hpp"


 
int main() {


  ft::tree<int> tree;

  tree.insert(6);
  tree.insert(2);
  tree.insert(9);
  tree.insert(10);
  tree.insert(100);
  tree.insert(-6);
  tree.insert(65111);


  tree.printLevels(tree.getRoot(), 0);

 
  return 0;
}