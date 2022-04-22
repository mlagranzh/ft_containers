/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:00:17 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/16 19:26:33 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_HPP
# define FUNCTION_HPP

# include"utility.hpp"

namespace ft
{
	template<typename Arg, typename Result>
	struct unary_function
	{
		typedef Arg		argument_type;   
		typedef Result	result_type;  
	};

	template<typename Arg1, typename Arg2, typename Result>
	struct binary_function
	{
		typedef Arg1	firstargument_type; 
		typedef Arg2	secondargument_type;
		typedef Result	result_type;
	};

	template<typename T>
	struct less : public binary_function<T, T, bool>
	{
		bool	operator()(const T& x, const T& y) const
		{
			return x < y;
		}
	};

	template<typename T>
	struct Identity : public unary_function<T, T>
	{
		T&	operator()(T& x) const
		{
			return x;
		}

		const T&	operator()(const T& x) const
		{
			return x;
		}
	};

	template<typename Pair>
	struct Select1st : public unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type&	operator()(Pair& x) const
		{
			return x.first;
		}

		const typename Pair::first_type&	operator()(const Pair& x) const
		{
			return x.first;
		}
	};

	template<typename Pair>
	struct Select2nd
	: public unary_function<Pair, typename Pair::second_type>
	{
		typename Pair::second_type&	operator()(Pair& x) const
		{
			return x.second;
		}

		const typename Pair::second_type&	operator()(const Pair& x) const
		{
			return x.second;
		}
	};
}

#endif
