/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:02:37 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/16 19:53:53 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		pair() : first(), second() {}
		pair(const T1& a, const T2& b) : first(a), second(b) {}
		template<typename U1, typename U2>
		pair(const pair<U1, U2>& src) : first(src.first), second(src.second) {}
		
		pair&	operator=(const pair& rhs)
		{
			new (this) pair(rhs);
			return *this;
		}
	};

	template<typename T1, typename T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template<typename T1, typename T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T1, typename T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) \
			&& lhs.second < rhs.second);
	}

	template<typename T1, typename T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return rhs < lhs;
	}

	template<typename T1, typename T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename T1, typename T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 first, T2 second)
	{
		return pair<T1, T2>(first, second);
	}
}

#endif
