/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:05:58 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/11 17:22:47 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>

namespace ft{

template < class Key, class T, 
			class Compare = std::less<Key>,
			class Alloc = std::allocator<std::pair<const Key,T> > 
		> class map{
			public:
			// Member types
			typedef Key 									key_type;
			typedef T   									mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef allocator_type::reference				reference;
			typedef allocator_type::const_reference			const_reference;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
			//iterators
			
			//reverse iterators
			
			typedef size_t									size_type;
	



			
		};
			
}

#endif