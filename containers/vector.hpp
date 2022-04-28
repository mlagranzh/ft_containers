/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:52:27 by celys             #+#    #+#             */
/*   Updated: 2022/04/28 09:17:10 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <iostream>
#include "RAI.hpp"
#include "reverse_RAI.hpp"
#include "utils.hpp"

namespace ft
{
template<typename Iterator>
	ptrdiff_t distance(Iterator first, Iterator last) {
		ptrdiff_t dist = 0;

		for (; first != last; ++first){
			dist++;
		}
		return dist;
	}
}

namespace ft
{
    template<class T, class A = std::allocator<T> >
    class vector 
    {
        public:
            typedef T value_type;
            typedef A allocator_type;
            typedef size_t size_type ;
            typedef ptrdiff_t difference_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef typename A::pointer pointer;
            typedef typename A::const_pointer const_pointer;
            typedef ft::RandomAccessIterator<value_type, value_type*,value_type&>   iterator;
            typedef ft::RandomAccessIterator<T, const T*, const T&> const_iterator;
			typedef ft::ReverseRandomAccessIterator<T, T*, T&>					reverse_iterator;
			typedef ft::ReverseRandomAccessIterator<T, const T*, const T&>		const_reverse_iterator;

        private:
            pointer _arr;
            size_type _len;
            size_type _cap;
			allocator_type	_alloc;

	    public:
            vector() : _arr(NULL), _len(0), _cap(0){};

            explicit vector(size_type count, const T& value = T(),
                            const allocator_type& alloc = A()) 
                            : _len(count), _cap(count), _alloc(alloc)
            {
                this->_arr = this->_alloc.allocate(this->_cap);
				if (count > this->_alloc.max_size())
					throw std::length_error("vector");

                for (size_type i = 0; i < this->_len; i++)
                    this->_alloc.construct(&this->_arr[i], value);
            };
            
            
            vector(const vector& other): _len(other._len), _cap(other._cap), _alloc(other._alloc) 
            {
				this->_arr = this->_alloc.allocate(this->_cap);

				const_iterator	it = other.begin();

				for (int i = 0; it != other.end(); i++, it++)
				{
					this->_alloc.construct(&this->_arr[i], *it);
				}
            }
		template <class InputIterator>
		vector( InputIterator first, InputIterator last, const allocator_type& alloc = A(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0): _arr(0), _len(0), _cap(0), _alloc(alloc)
		{
			if (first > last)
				throw std::length_error("vector");
			_len = last - first;
			_cap = _len;
			_arr = _alloc.allocate(_cap);
			for (difference_type i = 0; i < static_cast<difference_type>(_len); i++)
				_alloc.construct(_arr + i, *(_arr + i));
		}
					
		vector& operator=(const vector& other)
		 {
			this->~vector();

			this->_alloc = other._alloc;
			this->_len = other._len;
			this->_cap = other._cap;

			this->_arr = this->_alloc.allocate(this->_cap);
			const_iterator	it = other.begin();

			for (int i = 0; it != other.end(); i++, it++){
				this->_alloc.construct(&this->_arr[i], *it);
			}
			return *this;
		}

            allocator_type get_alloc() const
            {
                return (this -> _alloc);
            };
			
		~vector() 
		{
			for (iterator it = this->begin(); it != this->end(); ++it)
				this->_alloc.destroy(&(*it));
			this->_alloc.deallocate(this->_arr, this->_cap);
		}
        
/* 
    Element access
*/
            reference at(size_type pos)
            {
                if (pos > this->_len)
                    throw std::out_of_range("out of range");
                return (this->_arr[pos]);
            };
            
            const_reference at(size_type pos) const
            {
                if (pos > this->_len)
                    throw std::out_of_range("out of range");
                return (this->_arr[pos]);
            };

            reference operator[] (size_type pos)
            {
                return (this->_arr[pos]);
            };

            const_reference operator[] (size_type pos) const
            {
                return (this->_arr[pos]);
            };
            
            reference front()
            {
                return (this->_arr[0]);
            };

            const_reference front() const
            {
                return (this->_arr[0]);
            };

            reference back()
            {
                return this->_arr[this->_len - 1]; 
            };
            
            const_reference back() const
            {
                return this->_arr[this->_len - 1]; 
            };
            
/*
    Capacity:
*/
    size_type max_size() const
    {
        return (this->_alloc.max_size());
    };
    
    size_type size() const
    {
        return (this -> _len);
    };
    
    bool empty() const
    {
        return (!this -> _len);
    };

    void reserve(size_type n)
    {
        if (n <= this->_cap)
            return;

        pointer new_arr = this->_alloc.allocate(n);
        
        try
        {       
            for (size_type i = 0; i < _len; i++)
            {
                this->_alloc.construct(&new_arr[i], this->_arr[i]);
                this->_alloc.destroy(&this->_arr[i]);
            }
        }
        catch (std::exception &e)
        {
			for (size_type i = 0; i < n; i++)
			    this->_alloc.destroy(&new_arr[i]);
			this->_alloc.deallocate(new_arr, n);
			throw;
		}


        this->_alloc.deallocate(this->_arr, this->_cap);
        this->_arr = new_arr;
        this->_cap = n;
    };
        
    size_type capacity() const
    {
        return (this->_cap);
    };
        
/*
    Modifiers
*/
    void clear()
    {
        // for (size_type i = 0; i < this->_len; i++)
		//     this->_alloc.destroy(&_arr + i);
		_len = 0;
    };

		template<class InputIterator>
		void insert( iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			vector tmp(pos, end());
			this->_len -= ft::distance(pos, end());
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

			iterator insert(iterator pos, const_reference value) {
				size_type n = ft::distance(begin(), pos);
				insert(pos, 1, value);
				return (iterator(&this->_arr[n]));
			}


		void insert(iterator pos, size_type count, const_reference value) {
				size_type indexToInsert = 0;
				for (iterator it = begin(); it != pos; ++it, ++indexToInsert);
				if (!_cap)
					reserve(count);
				if (_len + count > _cap)
					reserve(_len + count > _cap * 2 ? _len + count : _cap * 2);
				for (size_type i = _len; i > indexToInsert; --i) {
					_alloc.destroy(_arr + i + count - 1);
					_alloc.construct(_arr + i + count - 1, _arr[i - 1]);
				}
				for (size_type i = 0; i < count; ++i) {
					_alloc.destroy(_arr + indexToInsert);
					_alloc.construct(_arr + indexToInsert++, value);
				}
				_len += count;
			}

    void pop_back()
    {
        // _alloc.destroy(this->_arr + this->_len - 1);
        this->_len -= 1;
    };
    
    void push_back(const value_type& value)
    {
        if (this->_len + 1 > this->_cap)
            reserve(this->_len == 0 ? 1 : this->_cap * 2);
        this->_alloc.construct(&this->_arr[this->_len], value);
		this->_len++;
    };

		iterator erase( iterator pos )
		{
			return erase(pos, pos + 1);
		}

		iterator erase (iterator first, iterator last) {
			difference_type start = ft::distance(begin(), first);
			difference_type need_to_copy = ft::distance(last, end());
			bool last_is_end = (last == end());
			while (first != last){
				_alloc.destroy(&(*first));
				first++;
			}
			size_type i = start;
			while (last < end()) {
				if (_arr + start)
					_alloc.destroy(_arr + i);
				_alloc.construct(_arr + i, *last);
				i++;
				last++;
			}
			for (size_type i = start + need_to_copy; i < _len; i++)
				_alloc.destroy(_arr + i);
			_len = start + need_to_copy;
			return last_is_end ? end() : iterator(_arr + start);
		}


		void resize( size_type count ) const
		{
			while (count < this->_len)
				pop_back();
		}

		void    resize (size_type count, value_type value = value_type()) 
		{
			if(count < _len){
				for(size_type i = count; i < _len; i++)
					_alloc.destroy(_arr + i);
				_len = count;
			}
			else if (count > _len){
				if (_cap < count)
					this->reserve(_cap * 2 > count ? _cap * 2 : count);
				for (size_type i = _len; i < count; i++){
					_alloc.construct(_arr + i, value);
					_len++;
				}
			}
		}
		
		template <typename U>
        void swap(U& a, U&b)
        {
            U tmp = a;
            a = b;
            b = tmp;
        }

		void swap( vector& other )
		{
			swap(this->_alloc, other._alloc);
			swap(this->_len, other._len);
			swap(this->_cap, other._cap);
			swap(this->_arr, other._arr);
		}


/*
    Iterators
*/
		iterator begin() { return iterator(this->_arr);}
		const_iterator begin() const { return const_iterator(this->_arr);}
		iterator end() { return iterator(this->_arr + this->_len);}
		const_iterator end() const { return const_iterator(this->_arr + this->_len);}
		reverse_iterator rbegin() { return reverse_iterator(this->_arr + this->_len - 1);}
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_arr + this->_len - 1);}
		reverse_iterator rend() { return reverse_iterator(begin());}
		const_reverse_iterator rend() const { return const_reverse_iterator(begin());}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0){
			if(first > last)
				throw std::logic_error("vector");
			difference_type count = last - first;
			clear();
			if (count > static_cast<difference_type>(capacity())){
				_alloc.deallocate(_arr, _cap);
				_arr = _alloc.allocate(count);
				_cap = count;
			}
			iterator pos = begin();
			while (first < last)
			{
				_alloc.construct(&(*pos), *first);
				pos++;
				first++;
			}
			_len = count;
		}

		void assign( size_type count, const T& value )
		{
			clear();
			if (count > _cap){
				_alloc.deallocate(_arr, _cap);
				_arr = _alloc.allocate(count);
				_cap = count;
			}
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_arr + i, value);
			_len = count;
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