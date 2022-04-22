/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:45:58 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/16 17:12:23 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	struct true_type {};
	struct false_type {};

	template<typename, typename>
	struct are_same
	{
		enum { value = 0 };
		typedef false_type	type;
	};

	template<typename T>
	struct are_same<T, T>
	{
		enum { value = 1 };
		typedef true_type	type;
	};

	template<bool B, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> {typedef T type;};

	template<typename T, T v>
	struct integral_constant
	{
		static const T						value = v;
		typedef T							value_type;
		typedef integral_constant<T, v>		type;

		operator T() const
		{
			return value;
		}
	};

	template<typename T>
	struct is_integral : public integral_constant<bool, false> {};

	template<>
	struct is_integral<bool> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<char> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<signed char> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned char> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<wchar_t> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<short> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned short> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<int> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned int> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<long> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned long> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<long long> : public integral_constant<bool, true> {};

	template<>
	struct is_integral<unsigned long long> : public integral_constant<bool, true> {};
}

#endif
