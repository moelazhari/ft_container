/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:46:07 by mazhari           #+#    #+#             */
/*   Updated: 2023/01/31 18:54:47 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

namespace ft {

	template <class InputIterator1, class InputIterator2>  
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
		while (first1!=last1) {
			if (*first1 != *first2)
				return false;
			++first1; 
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>  
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred){
		while (first1!=last1) {
			if (!pred(*first1,*first2))
				return false;
			++first1; 
			++first2;
		}
		return true;
	}

}

# endif