/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:50:23 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/01 18:54:57 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../ft_type_traits.hpp"

namespace ft
{
	template <class Iterator> 
	class Myreverse_iterator{

		public:
		// member types
			typedef 			Iterator											iterator_type;
			typedef typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;          
			typedef typename	ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename	ft::iterator_traits<Iterator>::reference			reference;

		// member functions
			// default constructor
			// Myreverse_iterator() {
			// 	return ;
			// }
			// // initialization constructor
			// explicit Myreverse_iterator (iterator_type x) : _base(x) {
			// 	return ;
			// }
			// // copy constructor
			// template <class Iter>
			// Myreverse_iterator (const Myreverse_iterator<Iter>& rev_it) : base(rev_it._base()){
			// 	return ;
			// }
			
			// iterator_type base() const{
			// 	return _base;
			// }

		private:
			iterator_type _base;
	};

}

#endif