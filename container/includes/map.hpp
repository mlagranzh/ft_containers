/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:03:34 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/20 17:34:01 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "tree.hpp"
# include <stdexcept>

namespace ft
{
	template<typename Key, typename T, typename Compare = ft::less<Key>, \
		typename Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
			typedef Key					key_type;
			typedef T					mapped_type;
			typedef pair<const Key, T>	value_type;
			typedef Compare				key_compare;
			typedef Allocator			allocator_type;

			class value_compare : public binary_function<value_type, value_type, bool>
			{
				friend class map<Key, T, Compare, Allocator>;

				protected:
					Compare	comp;

					value_compare(Compare c) : comp(c) {}

				public:
					bool	operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			typedef typename Allocator::template \
				rebind<value_type>::other									Pair_alloc_type;
			typedef Rb_tree<key_type, value_type, \
				ft::Select1st<value_type>, key_compare, Pair_alloc_type>	Tree_type;

			Tree_type	_tree;

		public:
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename Tree_type::size_type				size_type;
			typedef typename Tree_type::difference_type			difference_type;
			typedef typename Tree_type::iterator				iterator;
			typedef typename Tree_type::const_iterator			const_iterator;
			typedef typename Tree_type::reverse_iterator		reverse_iterator;
			typedef typename Tree_type::const_reverse_iterator	const_reverse_iterator;

			explicit map(const key_compare& comp = key_compare(), \
				const allocator_type& alloc = allocator_type()) \
      			: _tree(comp, Pair_alloc_type(alloc)) {}

			template <class InputIterator>
			map (InputIterator first, \
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, \
				const key_compare& comp = key_compare(), \
				const allocator_type& alloc = allocator_type()) \
				: _tree(comp, Pair_alloc_type(alloc))
			{
				_tree.insert(first, last);
			}

			map(const map& src) : _tree(src._tree) {}

			~map() {}

			map&	operator=(const map& src)
			{
				_tree = src._tree;
				return *this;
			}

			allocator_type	get_allocator()const
			{
				return allocator_type(_tree.get_allocator());
			}

			mapped_type&	at(const key_type& key)
			{
				iterator	it = lower_bound(key);

				if (it == end() || key_comp()(key, (*it).first))
					throw std::out_of_range("map::at");
				return (*it).second;
			}
			const mapped_type&	at(const key_type& key) const
			{
				const_iterator	it = lower_bound(key);

				if (it == end() || key_comp()(key, (*it).first))
					throw std::out_of_range("map::at");
				return (*it).second;
			}

			mapped_type&	operator[](const key_type& key)
			{
				return (*((this->insert(ft::make_pair(key,mapped_type()))).first)).second;
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

			void	swap(map& other)
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
				return value_compare(_tree.key_comp());
			}

			template<typename K1, typename T1, typename C1, typename A1>
			friend bool	operator==(const map<K1, T1, C1, A1>& lhs, \
				const map<K1, T1, C1, A1>& rhs);

			template<typename K1, typename T1, typename C1, typename A1>
			friend bool	operator!=(const map<K1, T1, C1, A1>& lhs, \
				const map<K1, T1, C1, A1>& rhs);

			template<typename K1, typename T1, typename C1, typename A1>
			friend bool	operator<(const map<K1, T1, C1, A1>& lhs, \
				const map<K1, T1, C1, A1>& rhs);

			template<typename K1, typename T1, typename C1, typename A1>
			friend bool	operator>(const map<K1, T1, C1, A1>& lhs, \
				const map<K1, T1, C1, A1>& rhs);

			template<typename K1, typename T1, typename C1, typename A1>
			friend bool	operator<=(const map<K1, T1, C1, A1>& lhs, \
				const map<K1, T1, C1, A1>& rhs);

			template<typename K1, typename T1, typename C1, typename A1>
			friend bool	operator>=(const map<K1, T1, C1, A1>& lhs, \
				const map<K1, T1, C1, A1>& rhs);
	};

	template<typename Key, typename T, typename Compare, typename Allocator>
	void	swap(map<Key, T, Compare, Allocator>& x, \
		map<Key, T, Compare, Allocator>& y)
	{
		x.swap(y);
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator>& lhs, \
		const map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._tree == rhs._tree;
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator>& lhs, \
		const map<Key, T, Compare, Allocator>& rhs)
	{
		return !(lhs._tree == rhs._tree);
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator<(const map<Key, T, Compare, Allocator>& lhs, \
		const map<Key, T, Compare, Allocator>& rhs)
	{
		return lhs._tree < rhs._tree;
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator>(const map<Key, T, Compare, Allocator>& lhs, \
		const map<Key, T, Compare, Allocator>& rhs)
	{
		return rhs._tree < lhs._tree;
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator>& lhs, \
		const map<Key, T, Compare, Allocator>& rhs)
	{
		return !(rhs._tree < lhs._tree);
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator>& lhs, \
		const map<Key, T, Compare, Allocator>& rhs)
	{
		return !(lhs._tree < rhs._tree);
	}
}

#endif
