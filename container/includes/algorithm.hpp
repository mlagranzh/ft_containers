/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:09:01 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/16 19:26:00 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
	template<typename InputIterator1, typename InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template<typename InputIterator1, typename InputIterator2>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, \
		InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return first1 == last1 && first2 != last2;
	}
}

#endif
