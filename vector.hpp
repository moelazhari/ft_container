/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:34:48 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/05 15:54:52 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "./iterators/iterator.hpp"
#include "./iterators/reverse_iterator.hpp"
#include "./ft_type_traits.hpp"
#include "./ft_algorithm.hpp"

namespace  ft
{
	// Vector class
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
		// Member types
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer         				pointer; 
			typedef typename allocator_type::const_pointer   				const_pointer;
			// Iterators	
			typedef	Myiterator<value_type>									iterator;
			typedef	Myiterator<const value_type>							const_iterator;
			// Reverse iterators
			typedef typename ft::Myreverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::Myreverse_iterator<const_iterator>			const_reverse_iterator;

			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t      											size_type;

		//constructors
			//default constructor
			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _allocator(alloc){
				return ;
			}	
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n * 2), _allocator(alloc) {
				this->_p = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(this->_p + i, val);
			}
			//range constructor
			template < class InputIterator >
			vector (InputIterator first,\
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,\
			const allocator_type& alloc = allocator_type()) : _allocator(alloc)
			{
				difference_type n = last - first; 

				this->_size = n;
				this->_capacity = this->_size * 2;
				this->_p = _allocator.allocate(this->_capacity);

				while (last != first)
				{
					--last;
					--n;
					this->_allocator.construct(this->_p + n, *last);
				}
			}
			//copy constructor
			vector (const vector& x): _size(0), _capacity(0){
				*this = x;
			}
		//destructor
			~vector(){
				if (!this->_size)
					return ;
				while (this->_size > 0)
				{
					this->_allocator.destroy(this->_p + this->_size);
					this->_size--;
				};
				this->_allocator.deallocate(this->_p, this->_capacity);
			}
		//operator=
			vector& operator= (const vector& x){
				if (this->_size)
				{
					this->clear();
					this->_allocator.deallocate(this->_p, this->_capacity);
				}
				// copy content of x
				this->_allocator = x._allocator;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_p = this->_allocator.allocate(this->_capacity);
				
				for (size_type i = 0; i < this->_size; i++)
					this->_p[i] = x._p[i];
				return (*this);
			}
		// Iterators functions
			iterator begin(){
				return iterator(this->_p);
			}

			iterator end(){
				return iterator(this->_p + this->_size);
			}

			reverse_iterator rbegin(){
				return (reverse_iterator(this->end()));
			}

			reverse_iterator rend(){
				return (reverse_iterator(this->begin()));
			}

		//Capacity functions
			size_type size() const{
				return (this->_size);
			}
			size_type max_size() const{
				return (this->_allocator.max_size());
			}

			void resize (size_type n, value_type val = value_type()){
				if (n > this->_size)
				{
					this->reserve(n * 2);
					while (n > this->_size)
						this->push_back(val);
				}
				else
				{
					while (this->_size > n)
						this->pop_back();
				}
			}
			
			size_type capacity() const{
				return (this->_capacity);
			}

			bool empty() const{
				return (this->_size == 0);
			}

			void reserve (size_type n){
				if (n > this->_capacity)
				{
					pointer tmp = this->_allocator.allocate(n);
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.construct(tmp + i, this->_p[i]);
					
					if (this->_size)
					{
						for (size_type i = 0; i < this->_size; i++)
							this->_allocator.destroy(this->_p + i);
						this->_allocator.deallocate(this->_p, this->_capacity);
					}
					this->_p = tmp;
					this->_capacity = n;
				}
			}
		
		//Element access functions
			reference operator[](size_type n){
				return (this->_p[n]);
			}

			const_reference operator[](size_type n) const{
				return (this->_p[n]);
			}

			reference at (size_type n){
				if (n >= this->_size)
					throw std::out_of_range("out of range");
				return (this->_p[n]);
			}

			const_reference at (size_type n) const{
				if (n >= this->_size)
					throw std::out_of_range("out of range");
				return (this->_p[n]);
			}
			
			reference front(){
				return (this->_p[0]);
			}

			const_reference front() const{
				return (this->_p[0]);
			}

			reference back(){
				return (this->_p[this->_size - 1]);
			}

			const_reference back() const{
				return (this->_p[this->_size - 1]);
			}

		//Modifiers functions
			template <class InputIterator>
			void assign (InputIterator first,\
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last){
				this->clear();
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			}

			void assign (size_type n, const value_type& val){
				this->clear();
				while (n > 0)
				{
					this->push_back(val);
					--n;
				}
			}

			void push_back(const value_type& val){
				if (this->_size == this->_capacity)
					this->reserve((this->_capacity == 0) ? 2 : this->_capacity * 2);
				this->_allocator.construct(this->_p + this->_size, val);
				this->_size++;
			}

			void pop_back(){
				this->_allocator.destroy(this->_p + this->_size);
				this->_size--;
			}
			// isert single element
			iterator insert (iterator position, const value_type& val){

				pointer tmp = this->_allocator.allocate(this->_capacity + 1);
				iterator it = this->begin();
				size_type i = 0;

				while (it != position)
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}
				this->_allocator.construct(tmp + i, val);
				++i;
				while (it != this->end())
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}

				if (this->_size)
				{
					this->clear();
					this->_allocator.deallocate(this->_p, this->_capacity);
				}
				
				this->_p = tmp;
				this->_size = i;
				this->_capacity = this->_size;
				return (position);
			}
			// insert fill
			void insert (iterator position, size_type n, const value_type& val){

				pointer tmp = this->_allocator.allocate(this->_capacity + n);
				iterator it = this->begin();
				size_type i = 0;

				while (it != position)
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}
				while (n > 0)
				{
					this->_allocator.construct(tmp + i, val);
					++i;
					--n;
				}
				while (it != this->end())
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}

				this->clear();
				this->_allocator.deallocate(this->_p, this->_capacity);

				this->_p = tmp;
				this->_size = i;
				this->_capacity = this->_size;
			}
			// insert range
			template <class InputIterator>
			void insert (iterator position, InputIterator first,\
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last){

				difference_type n = last - first;

				pointer tmp = this->_allocator.allocate(this->_capacity + n);
				iterator it = this->begin();
				size_type i = 0;

				while (it != position)
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}
				while (first != last)
				{
					this->_allocator.construct(tmp + i, *first);
					++i;
					++first;
				}
				while (it != this->end())
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}

				this->clear();

				this->reserve(this->_capacity + n);
				this->_allocator.deallocate(this->_p, this->_capacity);

				this->_p = tmp;
				this->_size = i;
				this->_capacity = this->_size;
			}
			// erase single element
			iterator erase (iterator position){
				
				pointer tmp = this->_allocator.allocate(this->_capacity);
				iterator it = this->begin();
				size_type i = 0;

				while (it != position)
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}
				++it;
				while (it != this->end())
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}

				this->clear();
				this->_allocator.deallocate(this->_p, this->_capacity);
				
				this->_p = tmp;
				this->_size = i;
				return (position);
			}
			// erase range
			iterator erase (iterator first, iterator last){
				pointer tmp = this->_allocator.allocate(this->_capacity);
				iterator it = this->begin();
				size_type i = 0;

				while (it != first)
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}
				while (it != last)
					++it;
				while (it != this->end())
				{
					this->_allocator.construct(tmp + i, *it);
					++it;
					++i;
				}

				this->clear();
				this->_allocator.deallocate(this->_p, this->_capacity);
				
				this->_p = tmp;
				this->_size = i;
				return (first);
			}

			void swap (vector& x){
				ft::vector<value_type> tmp(x);
				x = *this;
				*this = tmp;
			}
			
			void clear(){
				while (this->_size > 0)
					this->pop_back();
			}
		// Allocator
			allocator_type get_allocator() const{
				return (this->_allocator);
			}
		// private attributes
		private:
			size_type		_size;
			size_type 		_capacity;
			pointer			_p;
			allocator_type	_allocator;
	};
}
// Non-member function overloads

template <class T, class Alloc>
  bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	if (lhs.size() != rhs.size())
		return (false);
	
	ft::vector<T, Alloc>	v(lhs);
	ft::vector<T, Alloc>	v2(rhs);

	return (ft::equal(v.begin(), v.end(), v2.begin()));
  }

template <class T, class Alloc>
  bool operator!= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs){
	return (!(lhs == rhs));
  }

template <class T, class Alloc>
  bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){

	ft::vector<T, Alloc>	v(lhs);
	ft::vector<T, Alloc>	v2(rhs);

	return (ft::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()));
  }

template <class T, class Alloc>
  bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	return (!(rhs < lhs));
  }

template <class T, class Alloc>
  bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	return (rhs < lhs);
  }

template <class T, class Alloc>
  bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	return (!(lhs < rhs));
  }

template <class T, class Alloc>
  void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y){
	x.swap(y);
}

#endif