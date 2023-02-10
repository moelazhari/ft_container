/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:39:00 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/10 17:27:20 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include <iostream>
#include <queue>

#define COUNT 10

namespace ft
{
    #define	RED 0
    #define	BLACK 1

    template <class T>
    class node
    {
        public:
            typedef T 		value_type;
			typedef node* 	pointer;

            node(value_type data, node* parent = NULL)
            {
                this->_data  	= data;
                this->_left  	= NULL;
                this->_right 	= NULL;
                this->_parent	= parent;
                this->_color 	= RED;
            }

			pointer getGrandParent(){
				if (!this->_parent)
					return (NULL);
				return (this->_parent->_parent);
			}

			pointer getUncle(){
				pointer grandparent = this->getGrandParent();
				if (!grandparent)
					return (NULL);
				if (this->_parent == grandparent->_left)
					return (grandparent->_right);
				else
					return (grandparent->_left);
			}

			pointer getSibling(){
				if (this->_parent == NULL)
					return (NULL);
				if (this == this->_parent->_left)
					return (this->_parent->_right);
				else
					return (this->_parent->_left);
			}
			// setrs and geters
			value_type getData(){
				return (this->_data);
			}
			
			void setData(value_type data){
				this->_data = data;
			}

			pointer getLeft(){
				return (this->_left);
			}
			
			void setLeft(pointer node){
				this->_left = node;
			}

			pointer getRight(){
				return (this->_right);
			}

			void setRight(pointer node){
				this->_right = node;
			}

			pointer getParent(){
				return (this->_parent);
			}
			
			void setParent(pointer node){
				this->_parent = node;
			}
			
			bool getColor(){
				return (this->_color);
			}

			void setColor(bool color){
				this->_color = color;
			}

        private:
            value_type	_data;
            pointer		_left;
            pointer		_right;
            pointer		_parent;
            bool		_color;
    };

	template <class T>
	class tree{
		public:
		// member types
			typedef T							value_type;
			typedef ft::node<T>					node_type;
			typedef typename node_type::pointer node_pointer;
			typedef std::allocator< node_type >	allocator_type;
			typedef size_t						size_type;
		// constructor
			tree() : _root(NULL), _size(0), _alloc(allocator_type()) {
				return ;
			}
		// member function
			node_pointer insert(value_type data){
				this->_size++;

				node_pointer newNode = this->_alloc.allocate(1);
				this->_alloc.construct(newNode, data);
				
				if (!this->_root){
					this->_root = newNode;
					this->_root->setColor(BLACK);
					return (this->_root);
				}
				node_pointer curnt = this->_root;
				node_pointer parent;
				while (1)
				{
					parent = curnt;
					if (newNode->getData() < curnt->getData()){
						curnt = parent->getLeft();
						if (!curnt){
							newNode->setParent(parent);
							parent->setLeft(newNode);
							break ;
						}
					}
					else{
						curnt = parent->getRight();
						if (!curnt){
							newNode->setParent(parent);
							parent->setRight(newNode);
							break ;
						}
					}
				}
				// this->fixTree(newNode);
				return (newNode);
			}

			void rotateRight(node_pointer node){
				node_pointer left = node->getLeft();
				node_pointer parent = node->getParent();
				node_pointer right = left->getRight();


				left->setParent(parent);
				if (parent){
					if (node == parent->getLeft())
						parent->setLeft(left);
					else
						parent->setRight(left);
				}
				else
					this->_root = left;
				left->setRight(node);
				node->setParent(left);
				node->setLeft(right);
				if (right)
					right->setParent(node);
			}
			
			void printInOrder(node_pointer node){
				if (!node)
					return ;
				printInOrder(node->getLeft());
				std::cout << node->getData() << " ";
				printInOrder(node->getRight());
			}

			void printLevels(node_pointer node, int space){
				// Base case
				if (node == NULL)
					return;
			
				// Increase distance between levels
				space += COUNT;
			
				// Process right child first
				printLevels(node->getRight(), space);
			
				// Print current node after space
				// count
				std::cout << std::endl;
				for (int i = COUNT; i < space; i++)
					std::cout << " ";
				std::cout << node->getData() << (node->getColor() ? ":BLACK" : ":RED") << "\n";
			
				// Process left child
				printLevels(node->getLeft(), space);
			}

			node_pointer getRoot(){
				return (this->_root);
			}

		private:
			node_pointer	_root;
			size_type		_size;
			allocator_type	_alloc;
	};
	

}

# endif