/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:52:27 by celys             #+#    #+#             */
/*   Updated: 2022/02/09 15:46:09 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
// #include <vector>

// std::vector<int>(2);
namespace ft
{
    template<class T, class A = std::allocator<T> >
    class vector 
    {
        private:
            pointer _arr;
            size_type _len;
            size_type _cap;
			allocator_type	_alloc;

	    public:
            typedef A allocator_type;
            typedef typename A::pointer pointer;
            typedef typename A::const_pointer const_pointer;
            // typedef typename A::reference reference;
            // typedef typename A::const_reference;
            // const reference;
            // typedef typename A::value_type value type;
            // typedef TO iterator;
            // typedef T1 const iterator;
            typedef T2 size_type;
            // typedef T3 difference type;
            // typedef reverse_iterator<const_iterator>;
            // const reverse_iterator;
            // typedef reverse_iterator<iterator>;
            // reverse iterator;
            vector() : _arr(NULL), _len(0), _cap(0) {};

            explicit vector( const Allocator& alloc )
            {
                
            };

            explicit vector(size_type count, const T& value = T(),
                            const Allocator& alloc = Allocator())
            {
                
            };
            vector( const vector& other )
            {
                
    
            void reserve(size_type n)
            {
                if (n <= _cap)
                    return;

                // pointer new_data = alloc.allocate(new_cap);
                // for (size_type i = 0; i < _len; i++)
                // {
                //     alloc.construct(&new_arr[i], _arr[i]); // call copy constructor
                //     alloc.destroy(&_arr[i]);			   // call destructor
                // }

                // alloc.deallocate(_arr, _cap);
                // _arr = new_arr;
                // _cap = new_cap;
            }
            
            allocator_type get_allocator() const
            {
                return (this -> _alloc);
            };
            
            size_type size() const
            {
                return (this -> _size);
            };
            
            bool empty() const
            {
                return (!this -> _size);
            };
            
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
            size_type max size() const;
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