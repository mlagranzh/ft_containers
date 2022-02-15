/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:52:27 by celys             #+#    #+#             */
/*   Updated: 2022/02/15 13:11:20 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <iostream>

    // template <class T, class A>
    // class Vector_val
    // {
    //     protected:
    //         Vector val(A Al = A()) : Alval(Al) {}
    //     typedef typename A::template rebind<T>::other Alty;
        
    //     Alty Alval;
    // };
    
namespace ft
{
    template<class T, class A = std::allocator<T> >
    class vector 
    {
        typedef T value_type;
        typedef A allocator_type;
        typedef size_t size_type ;
        typedef ptrdiff_t difference_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename A::pointer pointer;
        typedef typename A::const_pointer const_pointer;
        private:
            pointer _arr;
            size_type _len;
            size_type _cap;
			allocator_type	_alloc;

	    public:
            // typedef TO iterator;
            // typedef T1 const iterator;
            // typedef reverse_iterator<const_iterator>;
            // const reverse_iterator;
            vector() : _arr(NULL), _len(0), _cap(0){};


            // explicit vector(const allocator_type& alloc) : 
            // {
                
            // };

            explicit vector(size_type count, const T& value = T(),
                            const allocator_type& alloc = A()) 
                            : _len(count), _cap(count), _alloc(alloc)
            {
                this->_arr = this->_alloc.allocate(this->_cap);

                for (size_type i = 0; i < this->_len; i++)
                    this->_alloc.construct(&this->_arr[i], value);
            };
            
            vector(const vector& other): _len(other._len), _cap(other._cap), _alloc(other._alloc) 
            {
                this->_array = this->_alloc.allocate(this->_cap);

                // const_iterator	it = other.begin();

                // for (int i = 0; it != other.end(); i++, it++){
                //     this->_alloc.construct(&this->_array[i], *it);
                // }
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
    
    // void insert(iterator it, InIt first, InIt last)
    // {
        
    // };
    
    // iterator insert(iterator it, const T& x)
    // {
        
    // };
    
    // void insert( iterator pos, size_type count, const T& value)
    // {

    // };
    
    // template< class InputIt >
    // void insert( iterator pos, InputIt first, InputIt last )
    // {
        
    // };

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

    // iterator erase(iterator it)
    // {

    // };
    
    // iterator erase(iterator first, iterator last)
    // {
        
    // };


    void resize(size_type n)
    {

    };
    
    void resize(size_type n, T x)
    {

    };
    
    // void swap(vectors x)
    // {
        
    // };

/*
    Iterators
*/
        // iterator begin();
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