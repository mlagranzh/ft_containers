/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:21:36 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/19 23:20:45 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template<typename T, typename Container = vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef Container							container_type;

		protected:
			Container	c;

		public:
			explicit	stack(const Container& c = Container()) : c(c) {}

			~stack() {}

			stack&	operator=(const stack& rhs)
			{
				c = rhs.c;
				return *this;
			}

			value_type&	top()
			{
				return c.back();
			}

			const value_type&	top() const
			{
				return c.back();
			}

			bool	empty() const
			{
				return c.empty();
			}

			size_type	size() const
			{
				return c.size();
			}

			void	push(const value_type& value)
			{
				c.push_back(value);
			}

			void	pop()
			{
				c.pop_back();
			}

			template<typename T1, typename C1>
			friend bool operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

			template<typename T1, typename C1>
			friend bool operator!=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

			template<typename T1, typename C1>
			friend bool operator<(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

			template<typename T1, typename C1>
			friend bool operator>(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

			template<typename T1, typename C1>
			friend bool operator<=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

			template<typename T1, typename C1>
			friend bool operator>=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
	};

	template<typename T, typename Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template<typename T, typename Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs.c == rhs.c);
	}

	template<typename T, typename Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c < rhs.c;
	}

	template<typename T, typename Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(rhs.c < lhs.c);
	}

	template<typename T, typename Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return rhs.c < lhs.c;
	}

	template<typename T, typename Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs.c < rhs.c);
	}
}

#endif
