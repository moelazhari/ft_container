/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:03:24 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/07 21:59:52 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_TYPE_TRAITS_HPP
# define FT_TYPE_TRAITS_HPP

namespace ft
{
    // Iterator traits
    template <class T>
    class iterator_traits {
        public:
            typedef typename T::iterator_category iterator_category;
            typedef typename T::value_type        value_type;
            typedef typename T::difference_type   difference_type;
            typedef typename T::pointer           pointer;
            typedef typename T::reference         reference;
    };
    // Specialization for Iterator_traits pointers
    template <typename T>
    class iterator_traits<T*> {
        public:
            typedef T                               value_type;
            typedef ptrdiff_t                       difference_type;
            typedef std::random_access_iterator_tag iterator_category;
            typedef T*                              pointer;
            typedef T&                              reference;
    };
    // Specialization for Iterator_traits const pointers
    template <typename T>
    class iterator_traits<const T*> {
        public:
            typedef T                          value_type;
            typedef ptrdiff_t                  difference_type;
            typedef std::random_access_iterator_tag iterator_category;
            typedef const T*                   pointer;
            typedef const T&                   reference;
    };

    // Enable_if
    template <bool B, class T = void>
    struct enable_if {
    };
    // Specialization for enable_if true
    template<typename T>
    struct enable_if<true, T> { 
        typedef T type;
    };

    // Is_integral
    template <class T>
    struct is_integral
    {
        static const bool value = false;
    };

    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<char16_t>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<char32_t>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };

}

# endif