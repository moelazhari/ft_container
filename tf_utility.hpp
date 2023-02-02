/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_utility.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:31:52 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/02 18:38:05 by mazhari          ###   ########.fr       */
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
        

       private:
        first_type  first;
        second_type second; 
};



}

#endif