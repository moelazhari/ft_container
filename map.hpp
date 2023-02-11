/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:05:58 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/11 21:02:09 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "red_black_tree.hpp"
#include "ft_utility.hpp"

namespace ft{

template < class Key, class T, 
			class Compare = std::less<Key>,
			class Alloc = std::allocator<std::pair<const Key,T> > 
		> class map{
			public:
			// Member types
				typedef Key 									key_type;
				typedef T   									mapped_type;
				typedef ft::pair<const key_type, mapped_type>	value_type;
				typedef Compare									key_compare;
				typedef Alloc									allocator_type;

				typedef  typename allocator_type::reference			reference;
				typedef  typename allocator_type::const_reference	const_reference;
				typedef  typename allocator_type::pointer			pointer;
				typedef  typename allocator_type::const_pointer		const_pointer;
				//iterators
			
				//reverse iterators
			
				typedef size_t									size_type;
			//constructors
				explicit map (const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()): _size(0), _tree(comp, alloc){
								return ;
							};
				// template <class InputIterator>
				// map (InputIterator first, InputIterator last,
				// 	const key_compare& comp = key_compare(),
				// 	const allocator_type& alloc = allocator_type()): _size(0), _tree(comp, alloc){
						
		
				// 	};

				map (const map& x): _size(0), _tree(NULL){
					*this = x;
					return ;
				};
				

			
			// Member functions
			

			private:
				// Member variables
				size_type											_size;
				ft::tree<value_type, key_compare, allocator_type>	_tree;
		};
			
}

#endif