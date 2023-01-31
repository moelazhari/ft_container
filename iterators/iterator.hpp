/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:49:20 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/01 00:01:06 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    template <typename T>
    class Myiterator
    {
        //member types
        public:
            typedef typename std::ptrdiff_t                     difference_type;
            typedef T                                           value_type;
            typedef T*                                          pointer;
            typedef T&                                          reference;
            typedef typename std::random_access_iterator_tag   iterator_category;

            //constructors
            Myiterator() : _ptr(NULL) {
                return ;
            }
            
            Myiterator(pointer ptr) : _ptr(ptr) {
                return ;
            }

            Myiterator(Myiterator const & src) {
                *this = src;
                return ;
            }
            
            //destructor
            ~Myiterator() {
                return ;
            }
            
            //operator overloads
            
            bool operator==(Myiterator const & rhs) const {
                return this->_ptr == rhs._ptr;
            }
            
            bool operator!=(Myiterator const & rhs) const {
                return this->_ptr != rhs._ptr;
            }

            reference operator*() const {
                return *this->_ptr;
            }

            pointer operator->() const {
                return this->_ptr;
            }

            Myiterator & operator=(Myiterator const & rhs) {
                if (this != &rhs)
                    this->_ptr = rhs._ptr;
                return *this;
            }
            
            Myiterator &operator++() {
                this->_ptr++;
                return *this;
            }
            
            Myiterator operator++(int) {
                Myiterator tmp(*this);
                this->_ptr++;
                return tmp;
            }
            
            Myiterator &operator--() {
                this->_ptr--;
                return *this;
            }

            Myiterator operator--(int) {
                Myiterator tmp(*this);
                this->_ptr--;
                return tmp;
            }

            Myiterator operator+(difference_type n) const {
                return Myiterator(this->_ptr + n);
            }

            Myiterator operator-(difference_type n) const {
                return Myiterator(this->_ptr - n);
            }

            difference_type operator -(const Myiterator &rhs) {
                return this->_ptr - rhs._ptr;
            }

            bool operator<(const Myiterator &rhs) {
                return this->_ptr < rhs._ptr;
            }

            bool operator>(const Myiterator &rhs) {
                return this->_ptr > rhs._ptr;
            }

            bool operator<=(const Myiterator &rhs) {
                return this->_ptr <= rhs._ptr;
            }

            bool operator>=(const Myiterator &rhs) {
                return this->_ptr >= rhs._ptr;
            }

            Myiterator &operator+=(difference_type n) {
                this->_ptr += n;
                return *this;
            }

            Myiterator &operator-=(difference_type n) {
                this->_ptr -= n;
                return *this;
            }

            reference operator[](difference_type n) {
                return this->_ptr[n];
            }

        private:
            pointer _ptr;
    };

}

#endif