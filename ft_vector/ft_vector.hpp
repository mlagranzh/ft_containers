/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:52:27 by celys             #+#    #+#             */
/*   Updated: 2022/01/28 22:14:46 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>

namespace ft
{
    template <class T, class A>
    class Vector_val
    {
        protected:
            Vector val(A Al = A()) : Alval(Al) {}
        typedef typename A::template rebind<T>::other Alty;
        
        Alty Alval;
    };
    
    template<class T, class A = std::allocator<T> >
    class vector : public Vector_val<T, A>
    {
        public:
            typedef A allocator_type;
            typedef typename A::pointer pointer;
            typedef typename A::const_pointer const_pointer;
            typedef typename A::reference reference;
            typedef typename A::const_reference const_reference;
            typedef typename A::value_type value type;
            
            typedef Vector_val<T, Ax> Mybase;
            typedef typename Mybase::Alty A;
            typedef A allocator_type;
            // typedef TO iterator;
            // typedef T1 const_iterator;
            // typedef T2 size_type;
            // typedef T3 difference_type;
            
            typedef reverse_iterator<const_iterator> const_reverse_iterator;
            typedef reverse iterator<iterator> reverse_iterator;
            
            vector() : Mybase()
            {
                
            };
            
            explicit vector(const A& a1)
            {
                
            };
            
            explicit vector(size type n)
            {
                
            };
            
            vector(size type n, const T& x)
            {
                
            };
            
            vector(size type n, const T& x, const A& al)
            {

            };
            
            vector(const vectors x)
            {
                
            };
            
            template<class InIt>
            vector(InIt first, InIt last)
            {

            };
            
            template<class InIt>
            vector(InIt first, InIt last, const A& a1)
            {
                
            };
            
            void reserve(size type n)
            {

            };
            
            size_type capacity() const
            {
                
            }
            
            iterator begin()
            {
                
            }

            const_iterator begin() const
            {

            }
            
            iterator end()
            {

            }
            
            const_iterator end() const
            {

            }
            
            reverse_iterator rbegin()
            {
                
            }
            
            const_reverse_iterator rbegin() const
            {
                
            }
            
            reverse_iterator rend()
            {
                
            }
            
            const_reverse_iterator rend() const
            {

            }
            
            void resize(size type n)
            {

            }

            void resize(size type n, T x)
            {

            }

            size_type size() const
            {
                
            }
            size_type max size() const
            {
                
            };
            
            bool empty() const
            {
                
            };
            
            A get_allocator() const
            {
                
            }
            
            reference at(size_type pos)
            {
                
            };
            
            const_reference at(size_type pos) const
            {
                
            };
            
            reference operator[] (size type pos)
            {
                
            };
            
            const_reference operator[] (size type pos)
            {

            };
            
            reference front()
            {
                
            };
            
            const_reference front() const
            {

            };
            
            reference back()
            {

            };
            
            const_reference back() const
            {
                
            };
            
            void push_back(const T& x)
            {
                
            };
            
            void pop_back()
            {

            };
            
            template<class InIt>
            void assign(InIt first, InIt last)
            {

            };
            
            void assign(size type n, const T& x)
            {

            };
            
            iterator insert(iterator it, const T& x)
            {

            };
            
            void insert(iterator it, size type n, const T& x)
            {
                
            };
            
            template<class InIt>
            void insert(iterator it, InIt first, InIt last)
            {
                
            };
            
            iterator erase(iterator it)
            {
                
            };
            
            iterator erase(iterator first, iterator last)
            {
                
            };

            void clear()
            {
                
            };

            void swap(vectors x)
            {
                
            };
    };

    template<class T, class A>
        bool operator==(
            const vector<T, A>& lhs,
            const vector<T, A>& rhs,
        );
}

#endif