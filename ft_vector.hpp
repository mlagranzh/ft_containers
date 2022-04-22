/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:52:27 by celys             #+#    #+#             */
/*   Updated: 2022/04/18 16:42:57 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <iostream>
#include "iterators/RAI.hpp"
#include "enable_if.hpp"

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
            // typedef ft::RandomAccessIterator<const_pointer> const_iterator;
            // typedef ft::ReverseRandomAccessIterator<iterator>  reverse_iterator;
            // typedef ft::ReverseRandomAccessIterator<const_iterator>    const_reverse_iterator;

        private:
            pointer _arr;
            size_type _len;
            size_type _cap;
			allocator_type	_alloc;

	    public:
            vector() : _arr(NULL), _len(0), _cap(0){};


            // explicit vector(const allocator_type& alloc) : 
            // {
                
            // };

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
                this->_array = this->_alloc.allocate(this->_cap);

                iterator    it = other.begin();

                for (int i = 0; it != other.end(); i++, it++){
                    this->_alloc.construct(&this->_array[i], *it);
                }
            }

            allocator_type get_allocator() const
            {
                return (this -> _alloc);
            };
                        
/* 
    Element access
*/
            reference at(size_type pos)
            {
                if (pos >= this->_len)
                    throw std::out_of_range("out of range");
                return (this->_arr[pos]);
            };
            
            const_reference at(size_type pos) const
            {
                if (pos >= this->_len)
                    throw std::out_of_range("out of range");
                return (this->_arr[pos]);
            };

            reference operator[] (size_type pos)
            {
                return (this->_arr[pos]);
            };

            const_reference operator[] (size_type pos) const
            {
                return (this->_array[pos]);
            };
            
            reference front()
            {
                return (this->_array[0]);
            };

            const_reference front() const
            {
                return (this->_array[0]);
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
        return (this -> _size);
    };
    
    bool empty() const
    {
        return (!this -> _size);
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
        for (size_type i = 0; i < this->_len; i++)
		    this->_alloc.destroy(&_arr[i]);
		_len = 0;
    };

		// template<class InputIterator>
		// void insert( iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		// {
		// 	vector tmp(pos, end());
		// 	this->_size -= ft::distance(pos, end());
		// 	while (first != last) {
		// 		push_back(*first);
		// 		++first;
		// 	}
		// 	iterator it = tmp.begin();
		// 	while (it != tmp.end()) {
		// 		push_back(*it);
		// 		++it;
		// 	}
		// }
        
		iterator insert( iterator pos, const T& value )
		{
			size_type n = ft::distance(begin(), pos);
			insert(pos, 1, value);
			return (iterator(&this->_arr[n]));
		}

		// iterator insert( const_iterator pos, T& value )
		// {
		// 	size_type n = ft::distance(begin(), pos);
		// 	insert(pos, 1, value);
		// 	return (iterator(&this->_array[n]));
		// }

		template <class InputIterator>
		vector( InputIterator first, InputIterator last, const allocator_type& alloc = A(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0): _arr(0), _len(0), _cap(0), _alloc(alloc)
		{
			InputIterator tmp(first);
			while (tmp!= last)
			{
				this->_len++;
				tmp++;
			}

			this->_cap = this->_len;
			this->_arr = this->_alloc.allocate(this->_cap);
			for (int i = 0; first != last; i++, first++){
				this->_alloc.construct(&this->_arr[i], *first);
			}
		}

		void insert( iterator pos, size_type count, const T& value )
		{
			vector tmp(pos, end());
			this->_len -= ft::distance(pos, end());
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

    void pop_back()
    {
        _alloc.destroy(&this->_arr[this->_len]);
        this->size -= 1;
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


//надо поправить!!!!
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

		void resize( size_type count ) const
		{
			while (count < this->_len)
				pop_back();
		}

		void    resize (size_type count, value_type value = value_type()) {
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
			swap(this->_len, other._len);
			swap(this->_cap, other._cap);
			swap(this->_arr, other._arr);
		}


/*
    Iterators
*/
		iterator begin() { return iterator(this->_arr);}
		// const_iterator begin() const { return const_iterator(this->_array);}
		iterator end() { return iterator(this->_arr + this->_len);}
		// const_iterator end() const { return const_iterator(this->_array + this->_size);}
		// reverse_iterator rbegin() { return reverse_iterator(this->_array + this->_size - 1);}
		// const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_array + this->_size - 1);}
		// reverse_iterator rend() { return reverse_iterator(this->_array - 1);}
		// const_reverse_iterator rend() const { return const_reverse_iterator(this->_array - 1);}

        // iterator begin()
        // {
            
        // }
        // const_iterator begin() const;
        //  iterator end();
        //     const_iterator end() const;
        //     reverse_iterator rbegin();
        //     const_reverse iterator rbegin() const;
        //     reverse iterator rend();
        //     const_reverse iterator rend() const;
        //     template<class InIt>
        //     void assign(InIt first, InIt last);
        //     void assign(size_type n, const T& x);
            
    };
}

#endif