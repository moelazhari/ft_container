/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:39:00 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/07 22:27:23 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include <iostream>

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
				if (!this->parent)
					return (NULL);
				return (this->parent->parent);
			}

			pointer getUncle(){
				pointer grandparent = this->getGrandParent();
				if (!grandparent)
					return (NULL);
				if (this->parent == grandparent->left)
					return (grandparent->right);
				else
					return (grandparent->left);
			}

			pointer getSibling(){
				if (this->parent == NULL)
					return (NULL);
				if (this == this->parent->left)
					return (this->parent->right);
				else
					return (this->parent->left);
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
            value_type     _data;
            node*          _left;
            node*          _right;
            node*          _parent;
            bool           _color;
    };

	template < class T, class Alloc = std::allocator<T> >
	class tree{
		public:
			typedef T						value_type;
			typedef Alloc					allocator_type;
			typedef node					node_type;
			typedef typename node::pointer  node_pointer;

			tree() : _root(NULL), _alloc(Alloc) {
				return ;
			}

			// node_pointer insert(node){
			// 	node_pointer newNode = _alloc.allocate(1);
				
			// }
		



		private:
			node_pointer	_root;
			allocator_type	_alloc;
	};
	
}

# endif