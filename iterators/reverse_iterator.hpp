/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:50:23 by mazhari           #+#    #+#             */
/*   Updated: 2023/01/31 23:55:49 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP


template <class Iterator> 
class Myreverse_iterator{
	private:
		Iterator base;

	public:
	// member types
		typedef 			Iterator										Iterator_type;
		typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;          
		typedef typename	iterator_traits<Iterator>::value_type			value_type;
		typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename	iterator_traits<Iterator>::pointer				pointer;
		typedef typename	iterator_traits<Iterator>::reference			reference;

	// constructors
		// default
		Myreverse_iterator() {
			return ;
		}
		// initialization
		explicit Myreverse_iterator (Iterator_type x) : base(x) {
			return ;
		}
		// copy
		template <class Iter>
		Myreverse_iterator (const Myreverse_iterator<Iter>& rev_it) : base(rev_it.base){
			return ;
		}
}

#endif