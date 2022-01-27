/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:52:27 by celys             #+#    #+#             */
/*   Updated: 2022/01/27 18:25:27 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>

namespace ft
{
    template <class T, class Container = std::deque<T> >
    class stack
    {
        private:
            Container container;
            Container container_type
            T value_type
            size_t size_type
            typedef T& reference;
            typedef T const & const_reference;
        public:
            stack();
            ~stack();
            operator=();
            T& top()
            {
                return container.back();
            }
            size();
            
            void push(const T& value)
            {
                container.push_back();
            }
            
            void pop()
            {
                container.pop_back();
            }
            empty();
        }
}

#endif