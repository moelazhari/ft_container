/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:49:20 by mazhari           #+#    #+#             */
/*   Updated: 2023/02/11 20:58:24 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    template <typename T>
    class vectorIterator
    {
        //member types
        public:
            typedef typename std::ptrdiff_t                     difference_type;
            typedef T                                           value_type;
            typedef T*                                          pointer;
            typedef T&                                          reference;
            typedef typename std::random_access_iterator_tag   iterator_category;

            //constructors
            vectorIterator() : _ptr(NULL) {
                return ;
            }
            
            vectorIterator(pointer ptr) : _ptr(ptr) {
                return ;
            }

            vectorIterator(vectorIterator const & src) {
                *this = src;
            }
            //operator overloads
            bool operator==(vectorIterator const & rhs) const {
                return this->_ptr == rhs._ptr;
            }
            
            bool operator!=(vectorIterator const & rhs) const {
                return this->_ptr != rhs._ptr;
            }

            reference operator*() const {
                return *this->_ptr;
            }

            pointer operator->() const {
                return this->_ptr;
            }

            vectorIterator & operator=(vectorIterator const & rhs) {
                if (this != &rhs)
                    this->_ptr = rhs._ptr;
                return *this;
            }
            
            vectorIterator &operator++() {
                this->_ptr++;
                return *this;
            }
            
            vectorIterator operator++(int) {
                vectorIterator tmp(*this);
                this->_ptr++;
                return tmp;
            }
            
            vectorIterator &operator--() {
                this->_ptr--;
                return *this;
            }

            vectorIterator operator--(int) {
                vectorIterator tmp(*this);
                this->_ptr--;
                return tmp;
            }

            vectorIterator operator+(difference_type n) const {
                return vectorIterator(this->_ptr + n);
            }

            vectorIterator operator-(difference_type n) const {
                return vectorIterator(this->_ptr - n);
            }

            difference_type operator -(const vectorIterator &rhs) {
                return this->_ptr - rhs._ptr;
            }

            bool operator<(const vectorIterator &rhs) {
                return this->_ptr < rhs._ptr;
            }

            bool operator>(const vectorIterator &rhs) {
                return this->_ptr > rhs._ptr;
            }

            bool operator<=(const vectorIterator &rhs) {
                return this->_ptr <= rhs._ptr;
            }

            bool operator>=(const vectorIterator &rhs) {
                return this->_ptr >= rhs._ptr;
            }

            vectorIterator &operator+=(difference_type n) {
                this->_ptr += n;
                return *this;
            }

            vectorIterator &operator-=(difference_type n) {
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