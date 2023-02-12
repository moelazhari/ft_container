/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:39:00 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/12 22:50:32 by mazhari          ###   ########.fr       */
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

    template <class T, class Alloc = std::allocator< T > >
    class node
    {
        public:
            typedef T 							value_type;
			typedef T*							pointer;
			typedef node*						node_pointer;
			typedef Alloc						allocator_type;

            node(value_type data, node* parent = NULL) : _left(NULL), _right(NULL), _parent(parent), _color(RED), _alloc(allocator_type()){
				this->setData(data);
			}

			~node(){
				this->_alloc.destroy(this->_data);
				this->_alloc.deallocate(this->_data, 1);
			}

			node_pointer getGrandParent(){
				if (!this->_parent)
					return (NULL);
				return (this->_parent->_parent);
			}

			node_pointer getUncle(){
				node_pointer grandparent = this->getGrandParent();
				if (!grandparent)
					return (NULL);
				if (this->_parent == grandparent->_left)
					return (grandparent->_right);
				else
					return (grandparent->_left);
			}

			node_pointer getSibling(){
				if (this->_parent == NULL)
					return (NULL);
				if (this == this->_parent->_left)
					return (this->_parent->_right);
				else
					return (this->_parent->_left);
			}
			//
	
			
			// setrs and geters
			pointer getData(){
				return (this->_data);
			}
			
			void setData(value_type data){
				this->_data = this->_alloc.allocate(1);
				this->_alloc.construct(this->_data, data);
			}

			node_pointer getLeft(){
				return (this->_left);
			}
			
			void setLeft(node_pointer node){
				this->_left = node;
			}

			node_pointer getRight(){
				return (this->_right);
			}

			void setRight(node_pointer node){
				this->_right = node;
			}

			node_pointer getParent(){
				return (this->_parent);
			}
			
			void setParent(node_pointer node){
				this->_parent = node;
			}
			
			bool getColor(){
				return (this->_color);
			}

			void setColor(bool color){
				this->_color = color;
			}

        private:
            pointer					_data;
            node_pointer			_left;
            node_pointer			_right;
            node_pointer			_parent;
            bool					_color;
			allocator_type 			_alloc;
    };

	template <class T, class C, class Alloc = std::allocator<T> >
	class tree{
		public:
		// member types
			typedef T									value_type;
			typedef	T									key_type;
			typedef ft::node<T, Alloc>					node_type;
			typedef typename node_type::node_pointer	node_pointer;
			typedef C									key_compare;
			typedef std::allocator< node_type >			allocator_type;
			typedef size_t								size_type;
		// constructor
			tree(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _root(NULL), _size(0), _comp(comp) ,_alloc(alloc) {
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
					if (this->_comp(*(newNode->getData()), *(curnt->getData()))){
						curnt = parent->getLeft();
						if (!curnt){
							newNode->setParent(parent);
							parent->setLeft(newNode);
							break ;
						}
					}
					else if (this->_comp(*(curnt->getData()), *(newNode->getData()))){
						curnt = parent->getRight();
						if (!curnt){
							newNode->setParent(parent);
							parent->setRight(newNode);
							break ;
						}
					}
					else
						return (NULL);
				}
				this->fixTree(newNode);
				return (newNode);
			}
			
			// void delete(node_pointer node){
			// 	if (!node)
			// 		return ;

			// 	if (node == this->_root){
			// 		this->_root = NULL;
			// 		this->_alloc.destroy(node);
			// 		this->_alloc.deallocate(node, 1);
			// 		return ;
			// 	}

			// 	node_pointer left = node->getLeft();
			// 	node_pointer right = node->getRight();
			// 	node_pointer parent = node->getParent();
				
			// 	// if node is leaf
			// 	if (!left && !right){
			// 		if (node == parent->getLeft())
			// 			parent->setLeft(NULL);
			// 		else
			// 			parent->setRight(NULL);
			// 		this->_alloc.destroy(node);
			// 		this->_alloc.deallocate(node, 1);
			// 	}
			// 	// if node has one child
			// 	else if ((left && !right) || (!left && right)){
			// 		if (left){
			// 			if (node == parent->getLeft())
			// 				parent->setLeft(left);
			// 			else
			// 				parent->setRight(left);
			// 			left->setParent(parent);
			// 		}
			// 		else{
			// 			if (node == parent->getLeft())
			// 				parent->setLeft(right);
			// 			else
			// 				parent->setRight(right);
			// 			right->setParent(parent);
			// 		}
			// 		this->_alloc.destroy(node);
			// 		this->_alloc.deallocate(node, 1);
			// 	}
			// 	// if node have tow children
			// }
			//

			node_pointer getPredecessor(node_pointer node){
				if (node->getLeft())
					return (max(node->getLeft()));
				else {
					return (node->getParent());
				}
			}
			// node_pointer getSuccessor(node_pointer node) {
			// 	node_pointer tmp;
			// 	node_pointer parent = node->getParent();

			// 	if (node == this->max(this->_root))
			// 		return NULL;
			// 	if (node->getRight())
			// 	{
			// 		tmp = node->getRight();
			// 		while (tmp->getLeft())
			// 			tmp = tmp->getLeft();
			// 		return tmp;
			// 	}
			// 	else if (!node->getRight() && node == parent->getRight()){
					
			// 	}
			// 	else {
			// 		std::cout << "69" << std::endl;
			// 		return NULL;
			// 	}
			// }

			void fixTree(node_pointer node){
				if (node == this->_root){
					node->setColor(BLACK);
					return ;
				}
				
				node_pointer parent = node->getParent();
				node_pointer uncle = node->getUncle();
				node_pointer grandParent = node->getGrandParent();

				if (parent->getColor() == RED &&  uncle && uncle->getColor() == RED)
				{
					parent->setColor(BLACK);
					uncle->setColor(BLACK);
					grandParent->setColor(RED);
					this->fixTree(grandParent);
				}
				else if (parent->getColor() == RED && (!uncle || uncle->getColor() == BLACK) ) {
					if (node == parent->getLeft() && parent == grandParent->getLeft()){
						this->rotateRight(grandParent);
						parent->setColor(BLACK);
						grandParent->setColor(RED);
					}
					else if (node == parent->getRight() && parent == grandParent->getLeft()){
						this->rotateLeft(parent);
						this->rotateRight(grandParent);
						node->setColor(BLACK);
						grandParent->setColor(RED);
						}
					else if (node == parent->getRight() && parent == grandParent->getRight()){
						this->rotateLeft(grandParent);
						parent->setColor(BLACK);
						grandParent->setColor(RED);
					}
					else if (node == parent->getLeft() && parent == grandParent->getRight()){
						this->rotateRight(parent);
						this->rotateLeft(grandParent);
						node->setColor(BLACK);
						grandParent->setColor(RED);
					}
				}
			}

			void rotateLeft(node_pointer node){
				node_pointer right = node->getRight();
				node_pointer parent = node->getParent();
				node_pointer left = right->getLeft();

				right->setParent(parent);
				if (parent){
					if (node == parent->getLeft())
						parent->setLeft(right);
					else
						parent->setRight(right);
				}
				else
					this->_root = right;
				right->setLeft(node);
				node->setParent(right);
				node->setRight(left);
				if (left)
					left->setParent(node);
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

			node_pointer max(node_pointer node)
			{
				if (!node->getRight())
					return node;
				while (node->getRight())
					node = node->getRight();
				return node;
			}

			// operator overloades
			node_pointer operator[](const key_type& key){
				node_pointer node = this->_root;
				while (node != NULL)
				{
					if (key == *(node->getData()))
						return node;
					else if (key < *(node->getData()))
						node = node->getLeft();
					else
						node = node->getRight();
				}
				return NULL;
			}
			
			void printInOrder(node_pointer node){  
				if (!node)
					return ;
				printInOrder(node->getLeft());
				std::cout << *(node->getData()) << " ";
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
				std::cout << *(node->getData()) << (node->getColor() ? ":BLACK" : ":RED") << "\n";
			
				// Process left child
				printLevels(node->getLeft(), space);
			}

			node_pointer getRoot(){
				return (this->_root);
			}

		private:
			node_pointer	_root;
			size_type		_size;
			key_compare		_comp;
			allocator_type	_alloc;
	};

}

# endif