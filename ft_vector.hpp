/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:52:27 by celys             #+#    #+#             */
/*   Updated: 2022/01/27 22:06:30 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>

namespace ft
{
    template<class T, class A = std::allocator<T> >
    class vector 
    {
        public:
            typedef A allocator type;
            typedef typename A: :pointer pointer;
            typedef typename A: :const_pointer
            const pointer;
            typedef typename A: :reference reference;
            typedef typename A::const_reference
            const reference;
            typedef typename A::value_type value type;
            typedef TO iterator;
            typedef T1 const iterator;
            typedef T2 size type;
            typedef T3 difference type;
            typedef reverse_iterator<const_iterator>
            const reverse iterator;
            typedef reverse iterator<iterator>
            reverse iterator;
            vector();
            explicit vector(const A& a1);
            explicit vector(size type n);
            vector(size type n, const T& x);
            vector(size type n, const T& x,
            const A& al);
            vector(const vectors x);
            template<class InIt>
            vector(InIt first, InIt last);
            template<class InIt>
            vector(InIt first, InIt last,
            const A& a1);
            void reserve(size type n);
            size_type capacity() const;
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse iterator rbegin() const;
            reverse iterator rend();
            const_reverse iterator rend() const;
            void resize(size type n);
            void resize(size type n, T x);
            size_type size() const;
            size_type max size() const;
            bool empty() const;
            A get allocator() const;
            reference at(size_type pos);
            const_reference at(size_type pos) const;
            reference operator[] (size type pos);
            const_reference operator[] (size type pos);
            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;
            void push back(const T& x);
            void pop back();
            template<class InIt>
            void assign(InIt first, InIt last);
            void assign(size type n, const T& x);
            iterator insert(iterator it, const T& x);
            void insert(iterator it, size type n, const T& x);
            template<class InIt>
            void insert(iterator it, InIt first, InIt last);
            iterator erase(iterator it);
            iterator erase(iterator first, iterator last);
            void clear();
            void swap(vectors x);
    };
}

#endif