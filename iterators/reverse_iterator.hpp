/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:50:23 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/01 20:01:25 by mazhari          ###   ########.fr       */
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
			//default constructor
			Myreverse_iterator() {
				return ;
			}
			// initialization constructor
			explicit Myreverse_iterator (iterator_type x) : _base(x) {
				return ;
			}
			// copy constructor
			template <class Iter>
			Myreverse_iterator (const Myreverse_iterator<Iter>& rev_it) : _base(rev_it._base()){
				return ;
			}
			
			iterator_type base() const{
				return this->_base;
			}

			reference operator*() const{
				iterator_type tmp = this->_base;
				return *(--tmp);
			}

			Myreverse_iterator operator+ (difference_type n) const{
				return Myreverse_iterator(this->_base - n);
			}

			Myreverse_iterator& operator++(){
				--this->_base;
				return *this;
			}

			Myreverse_iterator operator++(int){
				Myreverse_iterator tmp = *this;
				--this->_base;
				return tmp;
			}

			Myreverse_iterator& operator+= (difference_type n){
				this->_base -= n;
				return *this;
			}
			
			Myreverse_iterator operator- (difference_type n) const{
				return Myreverse_iterator(this->_base + n);
			}

			Myreverse_iterator& operator--(){
				++this->_base;
				return *this;
			}

			Myreverse_iterator operator--(int){
				Myreverse_iterator tmp = *this;
				++this->_base;
				return tmp;
			}

			Myreverse_iterator& operator-= (difference_type n){
				this->_base += n;
				return *this;
			}

			pointer operator->() const{
				return &(operator*());
			}

			reference operator[] (difference_type n) const{
				return base()[-n-1];
			}

			

		private:
			iterator_type _base;
	};

}

#endif