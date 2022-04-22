/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:35:39 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/20 00:26:35 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "iterator_base_types.hpp"
# include "type_traits.hpp"

namespace ft
{
	template<typename Iterator, typename Container>
	class normal_iterator
	{
		protected:
			Iterator	_it;

			typedef iterator_traits<Iterator>	_traits_type;

		public:
			typedef	Iterator									iterator_type;
			typedef typename _traits_type::iterator_category	iterator_category;
			typedef typename _traits_type::value_type			value_type;
			typedef typename _traits_type::difference_type		difference_type;
			typedef typename _traits_type::pointer				pointer;
			typedef typename _traits_type::reference			reference;

			normal_iterator() : _it() {}
			normal_iterator(const Iterator& it) : _it(it) {}
			template<typename Iter>
			normal_iterator(const normal_iterator<Iter, \
				typename enable_if< \
				(are_same<Iter, typename Container::pointer>::value),
				Container>::type>& src) : _it(src._it) {}

			template<typename Iter, typename Cont>
			normal_iterator&	operator=(const normal_iterator<Iter, Cont>& rhs)
			{
				new (this) normal_iterator<Iter, Cont>(rhs);
				return *this;
			}

			Iterator	base() const
			{
				return _it;
			}
			
			reference	operator*() const
			{
				return *_it;
			}
			
			pointer	operator->() const
			{
				return _it;
			}

			normal_iterator&	operator++()
			{
				++_it;
				return *this;
			}

			normal_iterator	operator++(int)
			{
				return normal_iterator(_it++);
			}

			normal_iterator&	operator--()
			{
				--_it;
				return *this;
			}

			normal_iterator	operator--(int)
			{
				return normal_iterator(_it--);
			}

			normal_iterator	operator+(difference_type n) const
			{
				return normal_iterator(_it + n);
			}

			normal_iterator	operator-(difference_type n) const
			{
				return normal_iterator(_it - n);
			}

			normal_iterator&	operator+=(difference_type n)
			{
				_it += n;
				return *this;
			}

			normal_iterator&	operator-=(difference_type n)
			{
				_it -= n;
				return *this;
			}

			reference	operator[](difference_type n) const
			{
				return _it[n];
			}
	};

	template<typename Iterator, typename Container>
	bool	operator==(const normal_iterator<Iterator, Container>& lhs, \
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator==(const normal_iterator<IteratorL, Container>& lhs, \
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename Iterator, typename Container>
	bool	operator!=(const normal_iterator<Iterator, Container>& lhs, \
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator!=(const normal_iterator<IteratorL, Container>& lhs, \
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename Iterator, typename Container>
	bool	operator<(const normal_iterator<Iterator, Container>& lhs, \
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<(const normal_iterator<IteratorL, Container>& lhs, \
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename Iterator, typename Container>
	bool	operator>(const normal_iterator<Iterator, Container>& lhs, \
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>(const normal_iterator<IteratorL, Container>& lhs, \
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<typename Iterator, typename Container>
	bool	operator<=(const normal_iterator<Iterator, Container>& lhs, \
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<=(const normal_iterator<IteratorL, Container>& lhs, \
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator, typename Container>
	bool	operator>=(const normal_iterator<Iterator, Container>& lhs, \
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>=(const normal_iterator<IteratorL, Container>& lhs, \
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename Iterator, typename Container>
	normal_iterator<Iterator, Container>	\
		operator+(typename normal_iterator<Iterator, Container>::difference_type n, \
		const normal_iterator<Iterator, Container>& it)
	{
		return normal_iterator<Iterator, Container>(it.base() + n);
	}

	template<typename Iterator, typename Container>
	typename normal_iterator<Iterator, Container>::difference_type	\
		operator-(const normal_iterator<Iterator, Container>& lhs, \
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template<typename IteratorL,  typename IteratorR, typename Container>
	typename normal_iterator<IteratorL, Container>::difference_type	\
		operator-(const normal_iterator<IteratorL, Container>& lhs, \
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template<typename Iterator>
	class reverse_iterator : public iterator< \
		typename iterator_traits<Iterator>::iterator_category, \
		typename iterator_traits<Iterator>::value_type, \
		typename iterator_traits<Iterator>::difference_type, \
		typename iterator_traits<Iterator>::pointer, \
		typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator	_it;

			typedef iterator_traits<Iterator>	_traits_type;

		public:
			typedef	Iterator									iterator_type;
			typedef typename _traits_type::iterator_category	iterator_category;
			typedef typename _traits_type::value_type			value_type;
			typedef typename _traits_type::difference_type		difference_type;
			typedef typename _traits_type::pointer				pointer;
			typedef typename _traits_type::reference			reference;

			reverse_iterator() : _it() {}
			reverse_iterator(const Iterator& it) : _it(it) {}
			template<typename Iter>
			reverse_iterator(const reverse_iterator<Iter>& src) : _it(src.base()) {}

			template<typename Iter>
			reverse_iterator&	operator=(const reverse_iterator<Iter>& rhs)
			{
				new (this) reverse_iterator<Iter>(rhs);
				return *this;
			}

			Iterator	base() const
			{
				return _it;
			}
			
			reference	operator*() const
			{
				Iterator	tmp = _it;
				return *--tmp;
			}
			
			pointer	operator->() const
			{
				return &(operator*());
			}

			reverse_iterator&	operator++()
			{
				--_it;
				return *this;
			}

			reverse_iterator	operator++(int)
			{
				reverse_iterator	tmp = *this;
				--_it;
				return tmp;
			}

			reverse_iterator&	operator--()
			{
				++_it;
				return *this;
			}

			reverse_iterator	operator--(int)
			{
				reverse_iterator	tmp = *this;
				++_it;
				return tmp;
			}

			reverse_iterator	operator+(difference_type n) const
			{
				return reverse_iterator(_it - n);
			}

			reverse_iterator	operator-(difference_type n) const
			{
				return reverse_iterator(_it + n);
			}

			reverse_iterator&	operator+=(difference_type n)
			{
				_it -= n;
				return *this;
			}

			reverse_iterator&	operator-=(difference_type n)
			{
				_it += n;
				return *this;
			}

			reference	operator[](difference_type n) const
			{
				return _it[-n - 1];
			}
	};

	template<typename Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs, \
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	bool	operator==(const reverse_iterator<IteratorL>& lhs, \
		const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, \
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	bool	operator!=(const reverse_iterator<IteratorL>& lhs, \
		const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, \
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	bool	operator<(const reverse_iterator<IteratorL>& lhs, \
		const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<typename Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, \
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	bool	operator>(const reverse_iterator<IteratorL>& lhs, \
		const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, \
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	bool	operator<=(const reverse_iterator<IteratorL>& lhs, \
		const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, \
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	bool	operator>=(const reverse_iterator<IteratorL>& lhs, \
		const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator>
	reverse_iterator<Iterator>	\
		operator+(typename reverse_iterator<Iterator>::difference_type n, \
		const reverse_iterator<Iterator>& it)
	{
		return reverse_iterator<Iterator>(it.base() - n);
	}

	template<typename Iterator>
	typename reverse_iterator<Iterator>::difference_type \
		operator-(const reverse_iterator<Iterator>& lhs, \
		const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}

	template<typename IteratorL,  typename IteratorR>
	typename reverse_iterator<IteratorL>::difference_type \
		operator-(const reverse_iterator<IteratorL>& lhs, \
		const reverse_iterator<IteratorR>& rhs)
	{
		return rhs.base() - lhs.base();
	}
}

#endif
