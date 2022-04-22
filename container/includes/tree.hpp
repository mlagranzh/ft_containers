/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:52:13 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/20 04:03:24 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include "iterator.hpp"
# include "utility.hpp"
# include "algorithm.hpp"
# include "function.hpp"
# include <memory>

namespace ft
{
	enum Rb_tree_color { red = false, black = true };

	template<typename T>
	struct Rb_tree_node
	{
		typedef T					value_type;
		typedef Rb_tree_node<T>		node_type;
		typedef Rb_tree_node<T>*	node_pointer;

		value_type		value;
		Rb_tree_color	color;
		node_pointer	parent;
		node_pointer	left;
		node_pointer	right;

		Rb_tree_node() : color(red), parent(0), \
			left(0), right(0) {}

		Rb_tree_node(const value_type& x) : value(x), color(red), \
			parent(0), left(0), right(0) {}

		Rb_tree_node(const node_pointer& x) : value(x->value), color(x->color), \
			parent(0), left(0), right(0) {}

		Rb_tree_node(const node_type& src) : value(src.value), color(src.color), \
			parent(0), left(0), right(0) {}
	};

	template<typename T>
	Rb_tree_node<T>*	Rb_tree_minimum(Rb_tree_node<T>* x)
	{
		while (x->left)
			x = x->left;
		return x;
	}

	template<typename T>
	const Rb_tree_node<T>*	Rb_tree_minimum(const Rb_tree_node<T>* x)
	{
		return Rb_tree_minimum(const_cast<Rb_tree_node<T>*>(x));
	}

	template<typename T>
	Rb_tree_node<T>*	Rb_tree_maximum(Rb_tree_node<T>* x)
	{
		while (x->right)
			x = x->right;
		return x;
	}

	template<typename T>
	const Rb_tree_node<T>*	Rb_tree_maximum(const Rb_tree_node<T>* x)
	{
		return const_cast<Rb_tree_node<T>*>(x);
	}

	template<typename T>
	Rb_tree_node<T>*	Rb_tree_increment(Rb_tree_node<T>* x)
	{
		if (x->right) 
		{
			x = x->right;
			x = Rb_tree_minimum(x);
		}
		else 
		{
			Rb_tree_node<T>*	y = x->parent;

			while (x == y->right) 
			{
				x = y;
				y = y->parent;
			}
			if (x->right != y)
				x = y;
		}
		return x;
	}

	template<typename T>
	const Rb_tree_node<T>*	Rb_tree_increment(const Rb_tree_node<T>* x)
	{
		return Rb_tree_increment(const_cast<Rb_tree_node<T>*>(x));
	}

	template<typename T>
	Rb_tree_node<T>*	Rb_tree_decrement(Rb_tree_node<T>* x)
	{
		if (x->color == red && x->parent->parent == x)
			x = x->right;
		else if (x->left)
		{
			Rb_tree_node<T>*	y = x->left;

			x = Rb_tree_maximum(x);
			x = y;
		}
		else
		{
			Rb_tree_node<T>*	y = x->parent;

			while (x == y->left)
			{
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return x;
	}

	template<typename T>
	const Rb_tree_node<T>*	Rb_tree_decrement(const Rb_tree_node<T>* x)
	{
		return Rb_tree_decrement(const_cast<Rb_tree_node<T>*>(x));
	}

	template<typename T>
	struct Rb_tree_iterator
	{
		typedef T							value_type;
		typedef T&							reference;
		typedef T*							pointer;
		typedef bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t					difference_type;
		typedef Rb_tree_node<T>*			node_pointer;
		typedef	Rb_tree_iterator<T>			iterator;

		node_pointer	node;

		Rb_tree_iterator() : node() {}

		Rb_tree_iterator(node_pointer x) : node(x) {}

		reference	operator*() const
		{
			return node->value;
		}

		pointer	operator->() const
		{
			return &node->value;
		}

		iterator&	operator++()
		{
			node = Rb_tree_increment(node);
			return *this;
		}

		iterator	operator++(int)
		{
			iterator	tmp = *this;

			node = Rb_tree_increment(node);
			return tmp;
		}

		iterator&	operator--()
		{
			node = Rb_tree_decrement(node);
			return *this;
		}

		iterator	operator--(int)
		{
			iterator	tmp = *this;

			node = Rb_tree_decrement(node);
			return tmp;
		}
	};

	template<typename T>
	bool	operator==(const Rb_tree_iterator<T>& lhs, \
		const Rb_tree_iterator<T>& rhs)
	{
		return lhs.node == rhs.node;
	}

	template<typename T>
	bool	operator!=(const Rb_tree_iterator<T>& lhs, \
		const Rb_tree_iterator<T>& rhs)
	{
		return lhs.node != rhs.node;
	}

	template<typename T>
	struct Rb_tree_const_iterator
	{
		typedef T									value_type;
		typedef const T&							reference;
		typedef const T*							pointer;
		typedef bidirectional_iterator_tag			iterator_category;
		typedef ptrdiff_t							difference_type;
		typedef const Rb_tree_node<T>*				node_pointer;
		typedef	Rb_tree_iterator<T>					iterator;
		typedef	Rb_tree_const_iterator<T>			const_iterator;

		node_pointer	node;

		Rb_tree_const_iterator() : node() {}

		Rb_tree_const_iterator(node_pointer x) : node(x) {}

		Rb_tree_const_iterator(const iterator& src) : node(src.node) {}

		iterator	it_const_cast() const
		{
			return iterator(const_cast<typename iterator::node_pointer>(node));
		}

		reference	operator*() const
		{
			return node->value;
		}

		pointer	operator->() const
		{
			return &node->value;
		}

		const_iterator&	operator++()
		{
			node = Rb_tree_increment(node);
			return *this;
		}

		const_iterator	operator++(int)
		{
			const_iterator	tmp = *this;

			node = Rb_tree_increment(node);
			return tmp;
		}

		const_iterator&	operator--()
		{
			node = Rb_tree_decrement(node);
			return *this;
		}

		const_iterator	operator--(int)
		{
			const_iterator	tmp = *this;

			node = Rb_tree_decrement(node);
			return tmp;
		}
	};

	template<typename T>
	bool	operator==(const Rb_tree_const_iterator<T>& lhs, \
		const Rb_tree_const_iterator<T>& rhs)
	{
		return lhs.node == rhs.node;
	}

	template<typename T>
	bool	operator!=(const Rb_tree_const_iterator<T>& lhs, \
		const Rb_tree_const_iterator<T>& rhs)
	{
		return lhs.node != rhs.node;
	}

	template<typename T>
	void	Rb_tree_rotate_left(Rb_tree_node<T>* const x, Rb_tree_node<T>*& root)
	{
		Rb_tree_node<T>* const	y = x->right;

		x->right = y->left;
		if (y->left)
			y->left->parent = x;
		y->parent = x->parent;

		if (x == root)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	template<typename T>
	void Rb_tree_rotate_right(Rb_tree_node<T>* const x, Rb_tree_node<T>*& root)
	{
		Rb_tree_node<T>* const	y = x->left;

		x->left = y->right;
		if (y->right)
			y->right->parent = x;
		y->parent = x->parent;
		if (x == root)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	template<typename T>
	void	Rb_tree_insert_and_rebalance( const bool insert_left, \
		Rb_tree_node<T>* x, Rb_tree_node<T>* p, Rb_tree_node<T>& header)
	{
		Rb_tree_node<T>*&	root = header.parent;

		x->color = red;
		x->parent = p;
		x->left = 0;
		x->right = 0;

		if (insert_left)
		{
			p->left = x;

			if (p == &header)
			{
				header.parent = x;
				header.right = x;
			}
			else if (p == header.left)
			header.left = x;
		}
		else
		{
			p->right = x;

			if (p == header.right)
			header.right = x;
		}
		while (x != root && x->parent->color == red)
		{
			Rb_tree_node<T>* const	xpp = x->parent->parent;

			if (x->parent == xpp->left)
			{
				Rb_tree_node<T>* const	y = xpp->right;

				if (y && y->color == red)
				{
					x->parent->color = black;
					y->color = black;
					xpp->color = red;
					x = xpp;
				}
				else
				{
					if (x == x->parent->right)
					{
						x = x->parent;
						Rb_tree_rotate_left(x, root);
					}
					x->parent->color = black;
					xpp->color = red;
					Rb_tree_rotate_right(xpp, root);
				}
			}
			else
			{
				Rb_tree_node<T>* const	y = xpp->left;

				if (y && y->color == red)
				{
					x->parent->color = black;
					y->color = black;
					xpp->color = red;
					x = xpp;
				}
				else
				{
					if (x == x->parent->left)
					{
						x = x->parent;
						Rb_tree_rotate_right(x, root);
					}
					x->parent->color = black;
					xpp->color = red;
					Rb_tree_rotate_left(xpp, root);
				}
			}
		}
		root->color = black;
	}

	template<typename T>
	Rb_tree_node<T>*	Rb_tree_rebalance_for_erase(Rb_tree_node<T>* z, Rb_tree_node<T>& header)
	{
		Rb_tree_node<T>*&	root = header.parent;
		Rb_tree_node<T>*&	leftmost = header.left;
		Rb_tree_node<T>*&	rightmost = header.right;
		Rb_tree_node<T>*	y = z;
		Rb_tree_node<T>*	x = 0;
		Rb_tree_node<T>*	x_parent = 0;

		if (!y->left)
			x = y->right;
		else if (!y->right)
			x = y->left;
		else
		{
			y = y->right;
			y = Rb_tree_minimum(y);
			x = y->right;
		}
		if (y != z)
		{
			z->left->parent = y;
			y->left = z->left;
			if (y != z->right)
			{
				x_parent = y->parent;
				if (x)
					x->parent = y->parent;
				y->parent->left = x;
				y->right = z->right;
				z->right->parent = y;
			}
			else
				x_parent = y;
			if (root == z)
				root = y;
			else if (z->parent->left == z)
				z->parent->left = y;
			else
				z->parent->right = y;
			y->parent = z->parent;
			std::swap(y->color, z->color);
			y = z;
		}
		else
		{
			x_parent = y->parent;
			if (x)
				x->parent = y->parent;
			if (root == z)
				root = x;
			else if (z->parent->left == z)
				z->parent->left = x;
			else
				z->parent->right = x;
			if (leftmost == z)
			{
				if (!z->right)
					leftmost = z->parent;
				else
					leftmost = Rb_tree_minimum(x);
			}
			if (rightmost == z)
			{
				if (!z->left)
					rightmost = z->parent;
				else
					rightmost = Rb_tree_maximum(x);
			}
		}
		if (y->color != red)
		{
			while (x != root && (!x || x->color == black))
			{
				if (x == x_parent->left)
				{
					Rb_tree_node<T>*	w = x_parent->right;

					if (w->color == red)
					{
						w->color = black;
						x_parent->color = red;
						Rb_tree_rotate_left(x_parent, root);
						w = x_parent->right;
					}
					if ((!w->left || w->left->color == black) \
						&& (!w->right || w->right->color == black))
					{
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else
					{
						if (!w->right || w->right->color == black)
						{
							w->left->color = black;
							w->color = red;
							Rb_tree_rotate_right(w, root);
							w = x_parent->right;
						}
						w->color = x_parent->color;
						x_parent->color = black;
						if (w->right)
							w->right->color = black;
						Rb_tree_rotate_left(x_parent, root);
						break;
					}
				}
				else
				{
					Rb_tree_node<T>*	w = x_parent->left;

					if (w->color == red)
					{
						w->color = black;
						x_parent->color = red;
						Rb_tree_rotate_right(x_parent, root);
						w = x_parent->left;
					}
					if ((!w->right || w->right->color == black) \
						&& (!w->left || w->left->color == black))
					{
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else
					{
						if (!w->left || w->left->color == black)
						{
							w->right->color = black;
							w->color = red;
							Rb_tree_rotate_left(w, root);
							w = x_parent->left;
						}
						w->color = x_parent->color;
						x_parent->color = black;
						if (w->left)
							w->left->color = black;
						Rb_tree_rotate_right(x_parent, root);
						break;
					}
				}
			}
			if (x)
				x->color = black;
		}
		return y;
	}

	template<typename Key, typename T, typename KeyOfValue, \
		typename Compare, typename Allocator = std::allocator<T> >
	class Rb_tree
	{
		public:
			typedef Key										key_type;
			typedef T										value_type;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef size_t									size_type;
			typedef ptrdiff_t								difference_type;
			typedef Allocator								allocator_type;
			typedef ft::Rb_tree_iterator<value_type>		iterator;
			typedef ft::Rb_tree_const_iterator<value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		protected:
			typedef Rb_tree_node<T>							node_type;
			typedef Rb_tree_node<T>*						node_pointer;
			typedef const Rb_tree_node<T>*					const_node_pointer;
			typedef typename Allocator::template \
				rebind<Rb_tree_node<T> >::other				Node_allocator;

			allocator_type	_allocator;
			Node_allocator	_node_allocator;
			Compare			_key_compare;
			node_type		_header;
			size_type		_size;

		private:

			void	reset_header()
			{
				_header.parent = 0;
				_header.left = &_header;
				_header.right = &_header;
				_size = 0;
			}

			void	move_header(Rb_tree& other)
			{
				_header.color = other._header.color;
				_header.parent = other._header.parent;
				_header.left = other._header.left;
				_header.right = other._header.right;
				_header.parent->parent = &_header;
				_size = other._size;
				other.reset_header();
			}

			node_pointer	copy(const_node_pointer x, node_pointer p)
			{
				node_pointer	top;

				top = _node_allocator.allocate(1);
				_node_allocator.construct(top, *x);
				top->parent = p;
				try
				{
					if (x->right)
						top->right = copy(x->right, top);
					p = top;
					x = x->left;
					while (x)
					{
						node_pointer	y;

						y = _node_allocator.allocate(1);
						_node_allocator.construct(y, *x);
						p->left = y;
						y->parent = p;
						if (x->right)
							y->right = copy(x->right, y);
						p = y;
						x = x->left;
					}
				}
				catch(...)
				{
					erase_tree(top);
					throw ;
				}
				return top;
			}

			void	erase_tree(node_pointer x)
			{
				while (x)
				{
					erase_tree(x->right);

					node_pointer	y = x->left;

					_node_allocator.destroy(x);
					_node_allocator.deallocate(x, 1);
					x = y;
				}
			}

			void	erase_node(node_pointer x)
			{
				node_pointer	pos;
				
				pos = Rb_tree_rebalance_for_erase(x, _header);
				_node_allocator.destroy(x);
				_node_allocator.deallocate(x, 1);
				--_size;
			}

			void	erase_range(iterator first, iterator last)
			{
				if (first == begin() && last == end())
					clear();
				else
				{
					while (first != last)
						erase_node((first++).node);
				}
			}

			pair<node_pointer, node_pointer>	get_insert_pos(const key_type& key)
			{
				node_pointer	x = _header.parent;
				node_pointer	p = &_header;
				bool			comp = true;

				while (x)
				{
					p = x;
					comp = _key_compare(key, KeyOfValue()(x->value));
					if (comp)
						x = x->left;
					else
						x = x->right;
				}

				iterator	it = iterator(p);

				if (comp)
				{
					if (it == begin())
						return pair<node_pointer, node_pointer>(x, p);
					else
						--it;
				}
				if (_key_compare(KeyOfValue()(it.node->value), key))
					return pair<node_pointer, node_pointer>(x, p);
				return pair<node_pointer, node_pointer>(it.node, 0);
			}

			pair<node_pointer, node_pointer> \
				get_insert_hint_pos(const_iterator position, const key_type& key)
			{
				iterator	pos = position.it_const_cast();

				if (pos.node == &_header)
				{
					if (_size && _key_compare(KeyOfValue()(_header.right->value), key))
						return pair<node_pointer, node_pointer>(0, _header.right);
					else
						return get_insert_pos(key);
				}
				else if (_key_compare(key, KeyOfValue()(pos.node->value)))
				{
					iterator	before = pos;

					if (pos.node == _header.left)
						return pair<node_pointer, node_pointer>(_header.left, _header.left);
					else if (_key_compare(KeyOfValue()((--before).node->value), key))
					{
						if (!before.node->right)
							return pair<node_pointer, node_pointer>(0, before.node);
						else
							return pair<node_pointer, node_pointer>(pos.node, pos.node);
					}
					else
						return get_insert_pos(key);
				}
				else if (_key_compare(KeyOfValue()(pos.node->value), key))
				{
					iterator	after = pos;

					if (pos.node == _header.right)
						return pair<node_pointer, node_pointer>(0, _header.right);
					else if (_key_compare(key, KeyOfValue()((++after).node->value)))
					{
						if (!pos.node->right)
							return pair<node_pointer, node_pointer>(0, pos.node);
						else
							return pair<node_pointer, node_pointer>(after.node, after.node);
					}
					else
						return get_insert_pos(key);
				}
				else
					return pair<node_pointer, node_pointer>(pos.node, 0);
			}

			iterator	insert_pos(node_pointer x, node_pointer p, const value_type& value)
			{
				bool			insert_left;
				node_pointer	z;
				
				insert_left = (x || p == &_header \
					|| _key_compare(KeyOfValue()(value), KeyOfValue()(p->value)));
				z = _node_allocator.allocate(1);
				_node_allocator.construct(z, value);
				Rb_tree_insert_and_rebalance(insert_left, z, p, _header);
				++_size;
				return iterator(z);
			}

			iterator	lower_bound_range(node_pointer x, node_pointer y, \
				const key_type& key)
			{
				while (x)
				{
					if (!_key_compare(KeyOfValue()(x->value), key))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return iterator(y);
			}

			const_iterator	lower_bound_range(const_node_pointer x, const_node_pointer y, \
				const key_type& key) const
			{
				while (x)
				{
					if (!_key_compare(KeyOfValue()(x->value), key))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return const_iterator(y);
			}

			iterator	upper_bound_range(node_pointer x, node_pointer y, \
				const key_type& key)
			{
				while (x)
				{
					if (_key_compare(key, KeyOfValue()(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return iterator(y);
			}

			const_iterator	upper_bound_range(const_node_pointer x, const_node_pointer y, \
				const key_type& key) const
			{
				while (x)
				{
					if (_key_compare(key, KeyOfValue()(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
						x = x->right;
				}
				return const_iterator(y);
			}

		public:
			Rb_tree()
			{
				_header.color = red;
				reset_header();
			}

			Rb_tree(const Compare& comp, const allocator_type& alloc = allocator_type())
			{
				_header.color = red;
				reset_header();
				_key_compare = comp;
				_allocator = alloc;
				_node_allocator = Node_allocator(alloc);
			}

			Rb_tree(const Rb_tree& src)
			{
				_header.color = red;
				reset_header();
				_key_compare = src._key_compare;
				_allocator = src._allocator;
				_node_allocator = src._node_allocator;
				if (src._header.parent)
				{
					_header.parent = copy(src._header.parent, &_header);
					_header.left = Rb_tree_minimum(_header.parent);
					_header.right = Rb_tree_maximum(_header.parent);
					_size = src._size;
				}
			}

			~Rb_tree()
			{
				erase_tree(_header.parent);
			}

			Rb_tree&	operator=(const Rb_tree& src)
			{
				if (this != &src)
				{
					erase_tree(_header.left);
					reset_header();
					_key_compare = src._key_compare;
					if (src._header.parent)
					{
						_header.parent = copy(src._header.parent, &_header);
						_header.left = Rb_tree_minimum(_header.parent);
						_header.right = Rb_tree_maximum(_header.parent);
						_size = src._size;
					}
				}
				return *this;
			}

			allocator_type	get_allocator() const
			{
				return _allocator;
			}

			iterator	begin()
			{
				return _header.left;
			}

			const_iterator	begin() const
			{
				return _header.left;
			}

			iterator	end()
			{
				return &_header;
			}

			const_iterator	end() const
			{
				return &_header;
			}

			reverse_iterator	rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator	rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator	rend() const
			{
				return const_reverse_iterator(begin());
			}

			bool	empty() const
			{
				return !_size;
			}

			size_type	size() const
			{
				return _size;
			}

			size_type	max_size() const
			{
				return _node_allocator.max_size();
			}

			void	clear()
			{
				erase_tree(_header.parent);
				reset_header();
			}

			pair<iterator,bool>	insert(const value_type& value)
			{
				pair<node_pointer, node_pointer>	pos;

				pos = get_insert_pos(KeyOfValue()(value));
				if (pos.second)
					return pair<iterator, bool>\
						(insert_pos(pos.first, pos.second, value), true);
				return pair<iterator, bool>(iterator(pos.first), false);
			}

			iterator	insert(iterator position, const value_type& value)
			{
				pair<node_pointer, node_pointer>	pos;

				pos = get_insert_hint_pos(position, KeyOfValue()(value));
				if (pos.second)
					return insert_pos(pos.first, pos.second, value);
				return iterator(pos.first);
			}

			template <class InputIterator>
			void	insert(InputIterator first, \
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
			{
				for (; first != last; ++first)
					insert(end(), *first);
			}

			void	erase(iterator position)
			{
				if (position == end())
					throw ;
				erase_node(position.node);
			}

			void	erase(const_iterator position)
			{
				if (position == end())
					throw ;
				erase_node(position.node);
			}

			size_type	erase(const key_type& key)
			{
				const size_type				old_size = _size;
				pair<iterator, iterator>	pos = equal_range(key);

				erase_range(pos.first, pos.second);
				return old_size - _size;
			}

			void	erase(iterator first, iterator last)
			{
				erase_range(first, last);
			}

			void	erase(const_iterator first, const_iterator last)
			{
				erase_range(first, last);
			}

			void	swap(Rb_tree& other)
			{
				if (!_header.parent)
				{
					if (other._header.parent)
					move_header(other);
				}
				else if (!other._header.parent)
					other.move_header(*this);
				else
				{
					std::swap(_header.parent,other._header.parent);
					std::swap(_header.left,other._header.left);
					std::swap(_header.right,other._header.right);
					_header.parent->parent = &_header;
					other._header.parent->parent = &other._header;
					std::swap(_size, other._size);
				}
				std::swap(_key_compare, other._key_compare);
				std::swap(_node_allocator, other._node_allocator);
			}

			size_type	count(const key_type& key) const
			{
				if (find(key) == end())
					return 0;
				return 1;
			}

			iterator	find(const key_type& key)
			{
				iterator	it = lower_bound_range(_header.parent, &_header, key);
				
				if (it == end() || _key_compare(key, KeyOfValue()(it.node->value)))
					return end();
				return it;
			}

			const_iterator	find(const key_type& key) const
			{
				const_iterator	it = lower_bound_range(_header.parent, &_header, key);
				
				if (it == end() || _key_compare(key, KeyOfValue()(it.node->value)))
					return end();
				return it;
			}

			pair<iterator,iterator>	equal_range(const key_type& key)
			{
				node_pointer	x = _header.parent;
				node_pointer	y = &_header;

				while (x)
				{
					if (_key_compare(KeyOfValue()(x->value), key))
						x = x->right;
					else if (_key_compare(key, KeyOfValue()(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
					{
						node_pointer	x2(x);
						node_pointer	y2(y);

						y = x;
						x = x->left;
						x2 = x2->right;
						return pair<iterator, iterator>\
							(lower_bound_range(x, y, key), upper_bound_range(x2, y2, key));
					}
				}
				return pair<iterator, iterator>(iterator(y), iterator(y));
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& key) const
			{
				const_node_pointer	x = _header.left;
				const_node_pointer	y = &_header;

				while (x)
				{
					if (_key_compare(KeyOfValue()(x->value), key))
						x = x->right;
					else if (_key_compare(key, KeyOfValue()(x->value)))
					{
						y = x;
						x = x->left;
					}
					else
					{
						const_node_pointer	x2(x);
						const_node_pointer	y2(y);

						y = x;
						x = x->left;
						x2 = x2->right;
						return pair<const_iterator, const_iterator>\
							(lower_bound_range(x, y, key), upper_bound_range(x2, y2, key));
					}
				}
				return pair<const_iterator, const_iterator>\
					(const_iterator(y), const_iterator(y));
			}

			iterator	lower_bound(const key_type& key)
			{
				return lower_bound_range(_header.parent, &_header, key);
			}

			const_iterator	lower_bound(const key_type& key) const
			{
				return lower_bound_range(_header.parent, &_header, key);
			}

			iterator	upper_bound(const key_type& key)
			{
				return upper_bound_range(_header.parent, &_header, key);
			}

			const_iterator	upper_bound(const key_type& key) const
			{
				return upper_bound_range(_header.parent, &_header, key);
			}

			Compare	key_comp() const
			{
				return _key_compare;
			}
	};

	template<typename Key, typename Value, typename KeyOfValue,	\
		typename Compare, typename Allocator>
	void	swap(Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& x,
		Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& y)
	{
		x.swap(y);
	}

	template<typename Key, typename Value, typename KeyOfValue,	\
		typename Compare, typename Allocator>
	bool	operator==(const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& lhs, \
		const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<typename Key, typename Value, typename KeyOfValue,	\
		typename Compare, typename Allocator>
	bool	operator!=(const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& lhs, \
		const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Key, typename Value, typename KeyOfValue,	\
		typename Compare, typename Allocator>
	bool	operator<(const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& lhs, \
		const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<typename Key, typename Value, typename KeyOfValue,	\
		typename Compare, typename Allocator>
	bool	operator>(const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& lhs, \
		const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& rhs)
	{
		return rhs < lhs;
	}

	template<typename Key, typename Value, typename KeyOfValue,	\
		typename Compare, typename Allocator>
	bool	operator<=(const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& lhs, \
		const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename Key, typename Value, typename KeyOfValue,	\
		typename Compare, typename Allocator>
	bool	operator>=(const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& lhs, \
		const Rb_tree<Key, Value, KeyOfValue, Compare, Allocator>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
