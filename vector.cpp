/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:36:40 by mazhari           #+#    #+#             */
/*   Updated: 2023/01/29 19:59:40 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./vector.hpp"
#include <vector>


// constructing vectors
#include <iostream>

int main ()
{
  //constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second (4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  // size() returns the number of elements
    std::cout << "The size of fifth is " << fifth.size() << '\n';
 // max_size() returns the maximum possible number of elements
    std::cout << "The max size of fifth is " << fifth.max_size() << '\n';

// resize() resizes the container so that it contains n elements.
    fifth.resize(69);
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    
// capacity() returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
// empty() returns whether the container is empty
    std::cout << "The fifth is " << (fifth.empty() ? "empty" : "not empty") << '\n';

// reserve() requests that the vector capacity be at least enough to contain n elements.
    fifth.reserve(6969);
    std::cout << "The capacity of fifth  " << fifth.capacity() << '\n';
// shrink_to_fit() requests the container to reduce its capacity to fit its size.
    fifth.shrink_to_fit();
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';


// operator[] returns a reference to the element at a certain position
    std::cout << "The element at position 3 is " << fifth[3] << '\n';
// at() returns a reference to the element at a certain position
    try {
        std::cout << "The element at position 3 is " << fifth.at(69) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

// front() returns a reference to the first element in the vector
    std::cout << "The first element is " << fifth.front() << '\n';

// back() returns a reference to the last element in the vector
    std::cout << "The last element is " << fifth.back() << '\n';

// data() returns a direct pointer to the memory array used internally by the vector to store its owned elements.
    std::cout << "The data of fifth is " << fifth.data() << '\n';

// assign() assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
    ft::vector<int> sixth(5, 7);
    fifth.assign(sixth.begin(), sixth.end());
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
        
    fifth.assign(13, 37);
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

  // push_back() adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
    fifth.push_back(69);
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of the last element in fifth is :" << fifth.back() << '\n';
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

  // pop_back() removes the last element in the vector, effectively reducing the container size by one.
    fifth.pop_back();
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of the last element in fifth is :" << fifth.back() << '\n';
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

  // insert() inserts new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.  
    fifth.insert(fifth.begin(), 69);
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of the first element in fifth is :" << fifth.front() << '\n';
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    fifth.insert(fifth.begin(), 4, 1);
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of the first element in fifth is :" << fifth.front() << '\n';
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    fifth.insert(fifth.begin() + 4 , sixth.begin(), sixth.end());
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    
  // erase() removes from the vector either a single element (position) or a range of elements ([first,last)).
    fifth.erase(fifth.begin());
    std::cout << "The size of fifth is " << fifth.size() << '\n';
    std::cout << "The capacity of fifth is " << fifth.capacity() << '\n';
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    

    
    
      
    

  return 0;
}