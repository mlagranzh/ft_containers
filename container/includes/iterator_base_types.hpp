/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base_types.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:36:09 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/02 13:46:56 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BASE_TYPES_HPP
# define ITERATOR_BASE_TYPES_HPP

# include <cstddef>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<typename Category, typename T, typename Distance = ptrdiff_t, \
		typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef Category  iterator_category;
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
	};

	template<typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template<typename T>
	struct iterator_traits<T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};

	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};
}

#endif
