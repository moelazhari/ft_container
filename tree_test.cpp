#include <iostream>
#include "red_black_tree.hpp"
#include "map.hpp"

int main() {


  ft::tree<int, std::less<int> > tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(15);
  tree.insert(6);
  tree.insert(-13);
  tree.insert(-69);
  tree.insert(5451);
  tree.insert(24511);
  tree.insert(119);
  tree.insert(-984);
  tree.insert(7);

  tree.printLevels(tree.getRoot(), 0);
  tree.printInOrder(tree.getRoot());

  // std::cout<< "max :" << *(tree.max(tree.getRoot())->getData());
  // std::cout << *(tree[6]->getData()) << std::endl;

  std::cout << "Predecessor :" << *(tree.getPredecessor(tree[24511])->getData()) << std::endl;



 
  return 0;
}