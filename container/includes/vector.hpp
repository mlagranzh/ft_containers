/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:09:15 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/18 19:33:13 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator.hpp"
# include "utility.hpp"
# include "algorithm.hpp"
# include <memory>
# include <stdexcept>

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::normal_iterator<pointer, vector>		iterator;
			typedef ft::normal_iterator<const_pointer, vector>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:
			allocator_type	_allocator;
			pointer			_start;
			pointer			_finish;
			pointer			_end_of_storage;

		public:
			explicit vector(const allocator_type& alloc = allocator_type()) \
				: _allocator(alloc), _start(0), _finish(0), _end_of_storage(0) {}

			explicit vector(size_type n, const value_type& value = value_type(), \
				const allocator_type& alloc = allocator_type())
			{
				_allocator = alloc;
				if (n > _allocator.max_size())
					throw std::length_error("vector");
				_start = _allocator.allocate(n);
				_finish = _start + n;
				_end_of_storage = _finish;
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(_start + i, value);
			}

			template<typename InputIterator>
			vector(InputIterator first, \
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, \
				const allocator_type& alloc = allocator_type())
			{
				size_type	n = last - first;

				_allocator = alloc;
				_start = _allocator.allocate(n);
				_finish = _start + n;
				_end_of_storage = _finish;
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(_start + i, *(first + i));
			}

			vector(const vector& src)
			{
				size_type	n = src._finish - src._start;

				_allocator = src._allocator;
				_start = _allocator.allocate(n);
				_finish = _start + n;
				_end_of_storage = _finish;
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(_start + i, *(src._start + i));
			}

			~vector()
			{
				size_type	n = _finish - _start;
				size_type	capacity = _end_of_storage - _start;

				for (size_type i = 0; i < n; ++i)
					_allocator.destroy(_start + i);
				_allocator.deallocate(_start, capacity);
			}

			vector&	operator=(const vector& rhs)
			{
				if (this != &rhs)
					assign(rhs.begin(), rhs.end());
				return *this;
			}

			void	assign (size_type n, const value_type& value)
			{
				size_type	n_old = _finish - _start;
				size_type	capacity_old = _end_of_storage - _start;

				if (!n)
					return ;
				for (size_type i = 0; i < n_old; ++i)
					_allocator.destroy(_start + i);
				if (n > capacity_old)
				{
					_allocator.deallocate(_start, capacity_old);
					_start = _allocator.allocate(n);
					_end_of_storage = _start + n;
				}
				_finish = _start + n;
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(_start + i, value);
			}

			template<typename InputIterator>
			void	assign(InputIterator first, \
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
			{
				size_type	n = last - first;
				size_type	n_old = _finish - _start;
				size_type	capacity_old = _end_of_storage - _start;

				if (!n)
					return ;
				for (size_type i = 0; i < n_old; ++i)
					_allocator.destroy(_start + i);
				if (n > capacity_old)
				{
					_allocator.deallocate(_start, capacity_old);
					_start = _allocator.allocate(n);
					_end_of_storage = _start + n;
				}
				_finish = _start + n;
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(_start + i, *(first + i));
			}

			allocator_type	get_allocator() const
			{
				return _allocator;
			}

			reference	at(size_type n)
			{
				if (n >= static_cast<size_type>(_finish - _start))
					throw std::out_of_range("vector::at");
				return *(_start + n);
			}

			const_reference	at(size_type n) const
			{
				if (n >= static_cast<size_type>(_finish - _start))
					throw std::out_of_range("vector::at");
				return *(_start + n);
			}

			reference operator[](size_type n)
			{
				return *(_start + n);
			}

			const_reference operator[](size_type n) const
			{
				return *(_start + n);
			}

			reference	front()
			{
				return *_start;
			}

			const_reference	front() const
			{
				return *_start;
			}

			reference	back()
			{
				return *(_finish - 1);
			}

			const_reference	back() const
			{
				return *(_finish - 1);
			}

			value_type* data()
			{
				return _start;
			}

			const value_type* data() const
			{
				return _start;
			}

			iterator	begin()
			{
				return iterator(_start);
			}

			const_iterator	begin() const
			{
				return const_iterator(_start);
			}

			iterator end()
			{
				return iterator(_finish);
			}

			const_iterator end() const
			{
				return const_iterator(_finish);
			}

			reverse_iterator 	rbegin()
			{
				return reverse_iterator(_finish);
			}

			const_reverse_iterator 	rbegin() const
			{
				return const_reverse_iterator(_finish);
			}

			reverse_iterator  rend()
			{
				return iterator(_start);
			}

			const_reverse_iterator  rend() const
			{
				return const_iterator(_start);
			}

			bool	empty() const
			{
				return !(_finish - _start);
			}

			size_type	size() const
			{
				return _finish - _start;
			}

			size_type	max_size() const
			{
				return _allocator.max_size();
			}

			void	reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n <= static_cast<size_type>(_end_of_storage - _start))
					return ;

				size_type	size = _finish - _start;
				pointer		start_new = _allocator.allocate(n);
				pointer		finish_new = start_new + size;
				pointer		end_of_storage_new = start_new + n;

				for (size_type i = 0; i < size; ++i)
				{
					_allocator.construct(start_new + i, *(_start + i));
					_allocator.destroy(_start + i);
				}
				_allocator.deallocate(_start, _end_of_storage - _start);
				_start = start_new;
				_finish = finish_new;
				_end_of_storage = end_of_storage_new;
			}

			size_type	capacity() const
			{
				return _end_of_storage - _start;
			}

			void	clear()
			{
				size_type	size = _finish - _start;

				for (size_type i = 0; i < size; ++i)
					_allocator.destroy(_start + i);
				_finish = _start;
			}

			iterator	insert(iterator position, const value_type& value)
			{
				size_type	offset = position - begin();

				if (_finish != _end_of_storage)
				{
					if (position == end())
					{
						_allocator.construct(_finish, value);
						++_finish;
					}
					else
					{
						size_type	i = size() - 1;

						_allocator.construct(_finish, *(_start + i));
						++_finish;
						for (; i > offset; --i)
							_start[i] = _start[i - 1];
						_start[i] = value;
					}
				}
				else
				{
					size_type	capacity_new = size() * 2 + !size();

					if (capacity_new > max_size())
						capacity_new = max_size();
					if (capacity_new < size() + 1)
						throw std::length_error("vector::insert");

					pointer		start_new = _allocator.allocate(capacity_new);
					pointer		finish_new = start_new + size() + 1;
					pointer		end_of_storage_new = start_new + capacity_new;
					size_type	i = 0;

					for (; i < offset; ++i)
					{
						_allocator.construct(start_new + i, *(_start + i));
						_allocator.destroy(_start + i);
					}
					_allocator.construct(start_new + i, value);
					for (; i < size(); ++i)
					{
						_allocator.construct(start_new + i + 1, *(_start + i));
						_allocator.destroy(_start + i);
					}
					_allocator.deallocate(_start, _end_of_storage - _start);
					_start = start_new;
					_finish = finish_new;
					_end_of_storage = end_of_storage_new;
				}
				return begin() + offset;
			}

			void	insert(iterator position, size_type n, const value_type& value)
			{
				size_type	offset = position - begin();

				if (!n)
					return ;
				if (size() + n <= capacity())
				{
					if (position == end())
					{
						for (size_type i = 0; i < n; ++i)
							_allocator.construct(_finish + i, value);
						_finish += n;
					}
					else
					{
						size_type	i = size() - 1;

						for (; i >= offset; --i)
							_start[i + n] = _start[i];
						for (; i < offset + n; ++i)
							_start[i] = value;
						_finish += n;
					}
				}
				else
				{
					size_type	capacity_new = size() * 2 + !size();

					if (capacity_new > max_size())
						capacity_new = max_size();
					if (capacity_new < size() + n)
						throw std::length_error("vector::insert");

					pointer		start_new = _allocator.allocate(capacity_new);
					pointer		finish_new = start_new + size() + n;
					pointer		end_of_storage_new = start_new + capacity_new;
					size_type	i = 0;

					for (; i < offset; ++i)
					{
						_allocator.construct(start_new + i, *(_start + i));
						_allocator.destroy(_start + i);
					}
					for (; i < offset + n; ++i)
						_allocator.construct(start_new + i, value);
					for (; i < size() + n; ++i)
					{
						_allocator.construct(start_new + i, *(_start + i - n));
						_allocator.destroy(_start + i - n);
					}
					_allocator.deallocate(_start, _end_of_storage - _start);
					_start = start_new;
					_finish = finish_new;
					_end_of_storage = end_of_storage_new;
				}
			}

			template<class InputIterator>
			void	insert(iterator position, InputIterator first, \
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
			{
				size_type	offset = position - begin();
				size_type	n = last - first;

				if (!n)
					return ;
				if (size() + n <= capacity())
				{
					if (position == end())
					{
						for (size_type i = 0; i < n; ++i)
							_allocator.construct(_finish + i, *(first + i));
						_finish += n;
					}
					else
					{
						size_type	i = size() - 1;

						for (; i >= offset; --i)
							_start[i + n] = _start[i];
						for (i = 0; i < n; ++i)
							_start[offset + i] = first[i];
						_finish += n;
					}
				}
				else
				{
					size_type	capacity_new = size() * 2 + !size();

					if (capacity_new > max_size())
						capacity_new = max_size();
					if (capacity_new < size() + n)
						throw std::length_error("vector::insert");

					pointer		start_new = _allocator.allocate(capacity_new);
					pointer		finish_new = start_new + size() + n;
					pointer		end_of_storage_new = start_new + capacity_new;
					size_type	i = 0;

					for (; i < offset; ++i)
					{
						_allocator.construct(start_new + i, *(_start + i));
						_allocator.destroy(_start + i);
					}
					for (i = 0; i < n; ++i)
						_allocator.construct(start_new + offset + i, first[i]);
					for (i = offset + n; i < size() + n; ++i)
					{
						_allocator.construct(start_new + i, *(_start + i - n));
						_allocator.destroy(_start + i - n);
					}
					_allocator.deallocate(_start, _end_of_storage - _start);
					_start = start_new;
					_finish = finish_new;
					_end_of_storage = end_of_storage_new;
				}
			}

			iterator	erase(iterator position)
			{
				size_type	offset = position - begin();
				size_type	i = offset;

				for (; i < size() - 1; ++i)
				{
					_allocator.destroy(_start + i);
					_allocator.construct(_start + i, *(_start + i + 1));
				}
				_allocator.destroy(_start + i);
				--_finish;
				return begin() + offset;
			}

			iterator	erase(iterator first, iterator last)
			{
				size_type	offset = first - begin();
				size_type	n = last - first;
				size_type	i = offset;

				if (!n)
					return last;
				for (; i < offset + n; ++i)
					_allocator.destroy(_start + i);
				if (last != end())
				{
					for (; i < size(); ++i)
					{
						_allocator.construct(_start + i - n, *(_start + i));
						_allocator.destroy(_start + i);
					}
				}
				_finish -= n;
				return begin() + offset;
			}

			void	push_back(const value_type& value)
			{
				if (size() + 1 <= capacity())
				{
					_allocator.construct(_finish, value);
					++_finish;
				}
				else
				{
					size_type	capacity_new = size() * 2 + !size();

					if (capacity_new > max_size())
						capacity_new = max_size();
					if (capacity_new < size() + 1)
						throw std::length_error("vector::push_back");

					pointer		start_new = _allocator.allocate(capacity_new);
					pointer		finish_new = start_new + size() + 1;
					pointer		end_of_storage_new = start_new + capacity_new;
					size_type	i = 0;

					for (; i < size(); ++i)
					{
						_allocator.construct(start_new + i, *(_start + i));
						_allocator.destroy(_start + i);
					}
					_allocator.construct(start_new + i, value);
					_allocator.deallocate(_start, _end_of_storage - _start);
					_start = start_new;
					_finish = finish_new;
					_end_of_storage = end_of_storage_new;
				}
			}

			void	pop_back()
			{
				if (size())
					_allocator.destroy(--_finish);
			}

			void	resize(size_type n, value_type value = value_type())
			{
				if (n < size())
				{
					for (size_type i = n; i < size(); ++i)
						_allocator.destroy(_start + i);
					_finish = _start + n;
				}
				else if (n > size())
				{
					if (n > capacity())
					{
						if (n > size() * 2)
							reserve(n);
						else
							reserve(size() * 2);
					}
					for (size_type i = size(); i < n; ++i)
						_allocator.construct(_start + i, value);
					_finish = _start + n;
				}
			}

			void	swap(vector& other)
			{
				if (this != &other)
				{
					allocator_type	allocator_tmp = _allocator;
					pointer			start_tmp = _start;
					pointer			finish_tmp = _finish;
					pointer			end_of_storage_tmp = _end_of_storage;

					_allocator = other._allocator;
					_start = other._start;
					_finish = other._finish;
					_end_of_storage = other._end_of_storage;

					other._allocator = allocator_tmp;
					other._start = start_tmp;
					other._finish = finish_tmp;
					other._end_of_storage = end_of_storage_tmp;
				}
			}
	};

	template<typename T, typename Allocator>
	void	swap(vector<T, Allocator>& x, vector<T, Allocator>& y)
	{
		x.swap(y);
	}

	template<typename T, typename Allocator>
	bool	operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<typename T, typename Allocator>
	bool	operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T, typename Allocator>
	bool	operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<typename T, typename Allocator>
	bool	operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return rhs < lhs;
	}

	template<typename T, typename Allocator>
	bool	operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename T, typename Allocator>
	bool	operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
