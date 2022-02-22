#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include <memory>
# include <cstddef>
# include <cassert>
# include "iterators/raiterator.hpp"
# include "iterators/reverse_raiterator.hpp"
# include "utils/utils.hpp"
# include "utils/enable_if.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef	T														value_type;
		typedef	Allocator												allocator_type;
		typedef	size_t													size_type;
		typedef	value_type&												reference;
		typedef long int                                   				difference_type;
		typedef const value_type&										const_reference;
		typedef RandomAccessIterator<T, T*, T&>							iterator;
		typedef RandomAccessIterator<T, const T*, const T&>				const_iterator;
		typedef ReverseRandomAccessIterator<T, T*, T&>					reverse_iterator;
		typedef ReverseRandomAccessIterator<T, const T*, const T&>		const_reverse_iterator;

	private:
		T*				_array;
		size_type		_size;
		size_type		_cap;
		allocator_type	_alloc;

		template <typename U>
        void swap(U& a, U&b)
        {
            U tmp = a;
            a = b;
            b = tmp;
        }

		void moveElementsToTheLeft(iterator first, iterator last)
		{
			for (; first != end(); ++first, ++last)
			{
				this->_alloc.destroy(&(*first));

				if (last < end())
					this->_alloc.construct(&(*(first)), *last);
			}
		}

	public:

	/*		MAIN	*/
		explicit vector( const allocator_type& alloc = Allocator() ):_size(0), _cap(0), _alloc(alloc) {
			this->_array = this->_alloc.allocate(this->_cap);
		}

		explicit vector size_type count, const value_type& value = value_type(), const allocator_type& alloc = Aсllocator() ) : _size(count), _cap(count), _alloc(alloc) {
			this->_array = this->_alloc.allocate(this->_cap);

			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_array[i], value);
		}

		vector( const vector& other ): _size(other._size), _cap(other._cap), _alloc(other._alloc) {
			this->_array = this->_alloc.allocate(this->_cap);

			const_iterator	it = other.begin();

			for (int i = 0; it != other.end(); i++, it++){
				this->_alloc.construct(&this->_array[i], *it);
			}
		}

		template <class InputIterator>
		vector( InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0): _array(0), _size(0), _cap(0), _alloc(alloc)
		{
			InputIterator tmp(first);
			while (tmp!= last)
			{
				this->_size++;
				tmp++;
			}

			this->_cap = this->_size;
			this->_array = this->_alloc.allocate(this->_cap);
			for (int i = 0; first != last; i++, first++){
				this->_alloc.construct(&this->_array[i], *first);
			}
		}

		vector& operator=(const vector& other) {
			this->~vector();

			this->_alloc = other._alloc;
			this->_size = other._size;
			this->_cap = other._cap;

			this->_array = this->_alloc.allocate(this->_cap);
			const_iterator	it = other.begin();

			for (int i = 0; it != other.end(); i++, it++){
				this->_alloc.construct(&this->_array[i], *it);
			}
			return *this;
		}

		allocator_type get_allocator() const { return this->_alloc; }

		~vector() {
			for (iterator it = this->begin(); it != this->end(); ++it)
				this->_alloc.destroy(&(*it));
			this->_alloc.deallocate(this->_array, this->_cap);
		}

	/*		ITERATORS		*/
		iterator begin() { return iterator(this->_array);}
		const_iterator begin() const { return const_iterator(this->_array);}
		iterator end() { return iterator(this->_array + this->_size);}
		const_iterator end() const { return const_iterator(this->_array + this->_size);}
		reverse_iterator rbegin() { return reverse_iterator(this->_array + this->_size - 1);}
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_array + this->_size - 1);}
		reverse_iterator rend() { return reverse_iterator(this->_array - 1);}
		const_reverse_iterator rend() const { return const_reverse_iterator(this->_array - 1);}

	/*		MODIFIERS		*/
		void clear() { while (this->_size) pop_back(); }

		void assign( size_type count, const T& value )
		{
			clear();
			while (count)
			{
				push_back(value);
				count--;}
		}

		template <class InputIterator>
		void assign( InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			InputIterator it = first;
			clear();

			while (it != last)
			{
				push_back(*it);
				it++;
			}
		}

		template<class InputIterator>
		void insert( iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			vector tmp(pos, end());
			this->_size -= ft::distance(pos, end());
			while (first != last) {
				push_back(*first);
				++first;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) {
				push_back(*it);
				++it;
			}
		}

		iterator insert( iterator pos, const T& value )
		{
			size_type n = ft::distance(begin(), pos);
			insert(pos, 1, value);
			return (iterator(&this->_array[n]));
		}

		iterator insert( const_iterator pos, T& value )
		{
			size_type n = ft::distance(begin(), pos);
			insert(pos, 1, value);
			return (iterator(&this->_array[n]));
		}

		void insert( iterator pos, size_type count, const T& value )
		{
			vector tmp(pos, end());
			this->_size -= ft::distance(pos, end());
			while (count) {
				push_back(value);
				--count;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) {
				push_back(*it);
				++it;
			}
		}

		iterator erase( iterator pos )
		{
			return erase(pos, pos + 1);
		}

		iterator erase( iterator first, iterator last )
		{
			difference_type index = first - begin();

			if (last < end())
			{
				moveElementsToTheLeft(first, last);
				this->_size -= static_cast<size_type>(last - first);
			}
			else
			{
				size_type newSize = this->_size - static_cast<size_type>(last - first);
				while (this->_size != newSize)
					pop_back();
			}
			return (iterator(&this->_array[index]));
		}

		void push_back( const T& value )
		{
			if (this->_size >= this->_cap)
				reserve(this->_size == 0 ? 1 : (this->_cap * 2));
			this->_alloc.construct(&this->_array[this->_size], value);
			this->_size++;
		}

		void push_back( T& value )
		{
			if (this->_size >= this->_cap)
				reserve(this->_size == 0 ? 1 : (this->_cap * 2));
			this->_alloc.construct(&this->_array[this->_size], value);
			this->_size++;
		}

		void pop_back() { this->_size--; }

		void resize( size_type count ) const
		{
			while (count < this->_size)
				pop_back();
		}

		void		resize (size_type count, value_type value = value_type()) {
			while (count < this->_size)
				pop_back();
			if (count > this->_cap)
				reserve(count);
			while (count > this->_size)
				push_back(value);
		}

		void swap( vector& other )
		{
			swap(this->_alloc, other._alloc);
			swap(this->_size, other._size);
			swap(this->_cap, other._cap);
			swap(this->_array, other._array);
		}

	/*		ELEMENT ACCESS		*/
		reference at( size_type pos ) { if (pos >= this->_size) throw std::out_of_range("out of range"); return this->_array[pos]; }
		const_reference at( size_type pos ) const { if (pos >= this->_size) throw std::out_of_range("out of range"); return this->_array[pos]; }

		reference operator[]( size_type pos ){ return this->_array[pos]; }
		const_reference operator[]( size_type pos ) const{ return this->_array[pos]; }

		reference front() { return this->_array[0]; }
		const_reference front() const { return this->_array[0]; }

		reference back() { return this->_array[this->_size - 1]; }
		const_reference back() const { return this->_array[this->_size - 1]; }

		T* data() { return this->_array; }
		const T* data() const { return this->_array; }
	
	/*		CAPACITY		*/
		bool		empty() const { return !(this->_size); }
		size_type	size() const { return this->_size; }
		size_type	max_size() const { return this->_alloc.max_size(); }
		size_type	capacity() const { return this->_cap; }

		void		reserve(size_type new_cap) {
			if (new_cap <= this->_cap)
				return ;

			T* tmp = this->_alloc.allocate(new_cap);

			for (size_type i = 0; i < this->_size; i++) 
				this->_alloc.construct(&tmp[i], this->_array[i]);
			
			this->~vector();
			this->_array = tmp;
			this->_cap = new_cap;
		}
	};

	template< class T, class Alloc >
	bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ){ return !(lhs == rhs); }

	template< class T, class Alloc >
	bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	template< class T, class Alloc >
	bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return !(rhs < lhs); }

	template< class T, class Alloc >
	bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return rhs < lhs; }

	template< class T, class Alloc >
	bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return !(lhs < rhs); }

	template< class T, class Alloc >
	void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs )
	{
		vector<T,Alloc>& tmp(lhs);
		lhs = rhs;
		rhs = tmp;
	}
}

#endif