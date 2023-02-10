#include <iostream>
#include "red_black_tree.hpp"


 
int main() {


  ft::tree<int> tree;

  tree.insert(7);
  tree.insert(5);
  tree.insert(8);
  tree.insert(-2);
  tree.insert(6);
  tree.insert(-13);
  tree.insert(-69);

  tree.printLevels(tree.getRoot(), 0);

 
  return 0;
}