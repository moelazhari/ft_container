/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:31:52 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/02 19:10:54 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TF_UTILITY_HPP
#define TF_UTILITY_HPP

namespace ft {

	template <class T1, class T2> 
	struct pair{
		// member types
			typedef T1 first_type;
			typedef T2 second_type;
		// attributes
			first_type  first;
			second_type second;
		// constructors
			// default constructor
			pair(): first(T1()), second(T2()){
				return ;
			}
			// copy constructor
			template<class U, class V>
			pair(const pair<U, V>& pr): first(pr.first), second(pr.second){
				return ;
			}
			// initialization constructor
			pair(const first_type& a, const second_type& b): first(a), second(b){
				return ;
			}
		// member functions
			pair& operator=(const pair& pr){
				this->first = pr.first;
				this->second = pr.second;
				return *this;
			}
	};
	// relational operators overloads
	template <class T1, class T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		if (lhs.first < rhs.first || lhs.second < rhs.second)
			return (true);
		return (false);
	}
	
	template <class T1, class T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return !(rhs < lhs );
	}

	template <class T1, class T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return !(lhs < rhs);
	}
}

#endif