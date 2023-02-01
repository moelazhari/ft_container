/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:15:54 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/01 22:45:07 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "./vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> > 
	class stack{
		public:
		// Member types
			typedef T   		value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
			//constructor
			explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {
				return ;
			}
		// Member functions
			bool empty() const{
				return _ctnr.empty();
			}

			size_type size() const{
				return _ctnr.size();
			}

			value_type& top(){
				return _ctnr.back();
			}

			const value_type& top() const{
				return _ctnr.back();
			}

			void push (const value_type& val){
				_ctnr.push_back(val);
			}

			void pop(){
				_ctnr.pop_back();
			}

			private:
			container_type _ctnr;
	};
	// Non-member function overloads

	template <class T, class Container>
	bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return (lhs._ctnr == rhs._ctnr);
	}

	template <class T, class Container>
	bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return (lhs._ctnr != rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return (lhs._ctnr < rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return (lhs._ctnr <= rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return (lhs._ctnr > rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
		return (lhs._ctnr >= rhs._ctnr);
	}

}

#endif