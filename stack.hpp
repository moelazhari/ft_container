/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:15:54 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/01 22:36:06 by mazhari          ###   ########.fr       */
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


			private:
			container_type _ctnr;
	};

}

#endif