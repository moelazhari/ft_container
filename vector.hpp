/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:34:48 by mazhari           #+#    #+#             */
/*   Updated: 2023/01/29 15:59:07 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "./iterators/iterator.hpp"
#include "./ft_type_traits.hpp"

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

			
			
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t      									size_type;


		//constructors
			//default constructor
			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _allocator(alloc){
				return ;
			}	
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc) {
				this->_p = this->_allocator.allocate(this->_size);
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
				this->_capacity = this->_size;
				this->_p = _allocator.allocate(this->_capacity);

				while (last != first)
				{
					--last;
					--n;
					this->_allocator.construct(this->_p + n, *last);
				}
			}
			//copy constructor
			vector (const vector& x){
				*this = x;
			}
		//destructor
			~vector(){
				if (this->_size == 0)
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
				//free memory
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.destroy(this->_p + i);
				this->_allocator.deallocate(this->_p, this->_capacity);
				// copy content of x
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_p = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(this->_p + i, x._p[i]);
				return (*this);
			}
		// Iterators functions
			iterator begin(){
				return (this->_p);
			}

			iterator end(){
				return (this->_p + this->_size);
			}

			const_iterator cbegin(){
				return (this->_p);
			}

			const_iterator cend() const{
				return (this->_p + this->_size);
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
					this->reserve(n);
					while (n > this->_size)
						this->push_back(val);
				}
				else
				{
					while (this->_size < n)
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
					
					for (size_type i = 0; i < this->_size; i++)
						this->pop_back();
					this->_allocator.deallocate(this->_p, this->_capacity);
					
					this->_p = tmp;
					this->_capacity = n;
				}
			}
		
			void shrink_to_fit(){
				if (this->_capacity == this->_size)
					return ;
				while (this->_capacity > this->_size)
				{
					this->_allocator.destroy(this->_p + this->_capacity);
					this->_capacity--;
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
			
			value_type* data(){
				return (this->_p);
			}

			const value_type* data() const{
				return (this->_p);
			}

		//Modifiers functions
			void push_back(const value_type& val){
				if (this->_size == this->_capacity)
					this->reserve(this->_capacity);
				this->_allocator.construct(this->_p + this->_size, val);
				this->_size++;
			}

			void pop_back(){
				this->_allocator.destroy(this->_p + this->_size);
				this->_size--;
			}



		private:
			size_type 		_size;
			size_type 		_capacity;
			pointer 		_p;
			allocator_type _allocator;
	};
}

#endif