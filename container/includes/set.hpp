/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:57:20 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/20 02:25:02 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "tree.hpp"

namespace ft
{
	template<typename Key, typename Compare = ft::less<Key>, \
		typename Allocator = std::allocator<Key> >
	class set
	{
		public:
			typedef Key			key_type;
			typedef Key			value_type;
			typedef Compare		key_compare;
			typedef Compare		value_compare;
			typedef Allocator	allocator_type;

		private:
			typedef typename Allocator::template \
				rebind<value_type>::other									Key_alloc_type;
			typedef Rb_tree<key_type, value_type, \
				ft::Identity<value_type>, key_compare, Key_alloc_type>		Set_type;

			Set_type	_tree;

		public:
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename Set_type::size_type				size_type;
			typedef typename Set_type::difference_type			difference_type;
			typedef typename Set_type::iterator					iterator;
			typedef typename Set_type::const_iterator			const_iterator;
			typedef typename Set_type::const_reverse_iterator	reverse_iterator;
			typedef typename Set_type::const_reverse_iterator	const_reverse_iterator;

			explicit	set(const key_compare& comp = key_compare(), \
				const allocator_type& alloc = allocator_type()) \
				: _tree(comp, Key_alloc_type(alloc)) {}

			template<typename InputIterator>
			set(InputIterator first, \
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, \
				const key_compare& comp = key_compare(), \
				const allocator_type& alloc = allocator_type()) \
				: _tree(comp, Key_alloc_type(alloc))
			{
				_tree.insert(first, last);
			}

			set(const set& src) : _tree(src._tree) {}

			~set() {}

			set&	operator=(const set& src)
			{
				_tree = src._tree;
				return *this;
			}

			allocator_type	get_allocator()const
			{
				return allocator_type(_tree.get_allocator());
			}

			iterator	begin()
			{
				return _tree.begin();
			}

			const_iterator	begin() const
			{
				return _tree.begin();
			}

			iterator	end()
			{
				return _tree.end();
			}

			const_iterator	end() const
			{
				return _tree.end();
			}

			reverse_iterator	rbegin()
			{
				return _tree.rbegin();
			}

			const_reverse_iterator	rbegin() const
			{
				return _tree.rbegin();
			}

			reverse_iterator	rend()
			{
				return _tree.rend();
			}

			const_reverse_iterator	rend() const
			{
				return _tree.rend();
			}

			bool	empty() const
			{
				return _tree.empty();
			}

			size_type	size() const
			{
				return _tree.size();
			}

			size_type	max_size() const
			{
				return _tree.max_size();
			}

			void	clear()
			{
				_tree.clear();
			}

			pair<iterator,bool>	insert(const value_type& value)
			{
				return _tree.insert(value);
			}

			iterator	insert(iterator position, const value_type& value)
			{
				return _tree.insert(position, value);
			}

			template <class InputIterator>
			void	insert(InputIterator first, \
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
			{
				_tree.insert(first, last);
			}

			void	erase(iterator position)
			{
				_tree.erase(position);
			}

			size_type	erase(const key_type& key)
			{
				return _tree.erase(key);
			}

			void	erase(iterator first, iterator last)
			{
				_tree.erase(first, last);
			}

			void	swap(set& other)
			{
				_tree.swap(other._tree);
			}

			size_type	count(const key_type& key) const
			{
				return _tree.count(key);
			}

			iterator	find(const key_type& key)
			{
				return _tree.find(key);
			}

			const_iterator	find(const key_type& key) const
			{
				return _tree.find(key);
			}

			pair<iterator,iterator>	equal_range(const key_type& key)
			{
				return _tree.equal_range(key);
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& key) const
			{
				return _tree.equal_range(key);
			}

			iterator	lower_bound(const key_type& key)
			{
				return _tree.lower_bound(key);
			}

			const_iterator	lower_bound(const key_type& key) const
			{
				return _tree.lower_bound(key);
			}

			iterator	upper_bound(const key_type& key)
			{
				return _tree.upper_bound(key);
			}

			const_iterator	upper_bound(const key_type& key) const
			{
				return _tree.upper_bound(key);
			}

			key_compare	key_comp() const
			{
				return _tree.key_comp();
			}

			value_compare	value_comp() const
			{
				return _tree.key_comp();
			}

			template<typename K1, typename C1, typename A1>
			friend bool	operator==(const set<K1, C1, A1>& lhs, const set<K1, C1, A1>& rhs);

			template<typename K1, typename C1, typename A1>
			friend bool	operator!=(const set<K1, C1, A1>& lhs, const set<K1, C1, A1>& rhs);

			template<typename K1, typename C1, typename A1>
			friend bool	operator<(const set<K1, C1, A1>& lhs, const set<K1, C1, A1>& rhs);

			template<typename K1, typename C1, typename A1>
			friend bool	operator>(const set<K1, C1, A1>& lhs, const set<K1, C1, A1>& rhs);

			template<typename K1, typename C1, typename A1>
			friend bool	operator<=(const set<K1, C1, A1>& lhs, const set<K1, C1, A1>& rhs);

			template<typename K1, typename C1, typename A1>
			friend bool	operator>=(const set<K1, C1, A1>& lhs, const set<K1, C1, A1>& rhs);
	};

	template<typename Key, typename Compare, typename Allocator>
	void	swap(set<Key, Compare, Allocator>& x, set<Key, Compare, Allocator>& y)
	{
		x.swap(y);
	}

	template<typename Key, typename Compare, typename Allocator>
	bool	operator==(const set<Key, Compare, Allocator>& lhs, \
		const set<Key, Compare, Allocator>& rhs)
	{
		return lhs._tree == rhs._tree;
	}

	template<typename Key, typename Compare, typename Allocator>
	bool	operator!=(const set<Key, Compare, Allocator>& lhs, \
		const set<Key, Compare, Allocator>& rhs)
	{
		return !(lhs._tree == rhs._tree);
	}

	template<typename Key, typename Compare, typename Allocator>
	bool	operator<(const set<Key, Compare, Allocator>& lhs, \
		const set<Key, Compare, Allocator>& rhs)
	{
		return lhs._tree < rhs._tree;
	}

	template<typename Key, typename Compare, typename Allocator>
	bool	operator>(const set<Key, Compare, Allocator>& lhs, \
		const set<Key, Compare, Allocator>& rhs)
	{
		return rhs._tree < lhs._tree;
	}

	template<typename Key, typename Compare, typename Allocator>
	bool	operator<=(const set<Key, Compare, Allocator>& lhs, \
		const set<Key, Compare, Allocator>& rhs)
	{
		return !(rhs._tree < lhs._tree);
	}

	template<typename Key, typename Compare, typename Allocator>
	bool	operator>=(const set<Key, Compare, Allocator>& lhs, \
		const set<Key, Compare, Allocator>& rhs)
	{
		return !(lhs._tree < rhs._tree);
	}
}

#endif
