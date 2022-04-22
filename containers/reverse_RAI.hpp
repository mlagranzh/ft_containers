#ifndef REVERSE_RAITERATOR_HPP
# define REVERSE_RAITERATOR_HPP

# include "RAI.hpp"

namespace ft
{
	template < typename T, typename Pointer, typename Reference, class Category = std::random_access_iterator_tag >
	class ReverseRandomAccessIterator {
	public:
		typedef ReverseRandomAccessIterator<T, Pointer, Reference>		this_type;
		typedef ReverseRandomAccessIterator<T, T*, T&>					reverse_iterator;
		typedef ReverseRandomAccessIterator<T, const T*, const T&>		reverse_const_iterator;
		typedef RandomAccessIterator<T, T*, T&>							iterator;
		typedef RandomAccessIterator<T, const T*, const T&>				const_iterator;
		typedef Pointer													pointer;
		typedef Reference												reference;
		typedef size_t													size_type;
		typedef ptrdiff_t												difference_type;

		pointer	_array;

		ReverseRandomAccessIterator() : _array(NULL) {}
		ReverseRandomAccessIterator(const pointer elem) : _array(elem) {}
		ReverseRandomAccessIterator(const reverse_iterator& copy){
			this->_array = copy._array;
		}

		ReverseRandomAccessIterator(const reverse_const_iterator& copy){
			this->_array = copy._array;
		}

		explicit ReverseRandomAccessIterator(const iterator& copy){
			this->_array = copy._array - 1;
		}

		explicit ReverseRandomAccessIterator(const const_iterator& copy){
			this->_array = copy._array - 1;
		}

		// explicit rev_vector_iterator(const vector_iterator<T, false>& copy) { _val = copy.getElemPtr() - 1; }
		virtual ~ReverseRandomAccessIterator() {}

		this_type&	operator=(const reverse_iterator& other)
		{
			this->_array = other._array;
			return *this;
		}

		this_type&	operator++() { --this->_array; return *this; }
		this_type&	operator--() { ++this->_array; return *this; }
		this_type&	operator+=(difference_type n) { this->_array -= n; return *this; }
		this_type&	operator-=(difference_type n) { this->_array += n; return *this; }

		iterator	base() const { return this->_array; }

		this_type	operator++(int) {
			this_type out(*this);
			--this->_array;
			return out;
		}

		this_type	operator--(int) {
			this_type out(*this);
			++this->_array;
			return out;
		}

		this_type	operator+(difference_type n) const {
			this_type out(*this);
			out._array -= n;
			return out;
		}

		this_type	operator-(difference_type n) const {
			this_type out(*this);
			out += n;
			return out;
		}
		
		reference	operator*() { return *this->_array; }
		pointer		operator->() { return *(&(this->_array)); }
		difference_type	operator-(ReverseRandomAccessIterator it) const { return this->_array - it._array;}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator==(const this_type& lhs, const ReverseRandomAccessIterator<T2, P, R, C>& rhs) {
			return (lhs._array == rhs._array);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator!=(const this_type& lhs, const ReverseRandomAccessIterator<T2, P, R, C>& rhs) { return !(lhs._array == rhs._array); }

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator<(const this_type& lhs, const ReverseRandomAccessIterator<T2, P, R, C>& rhs) {
			return (lhs._array < rhs._array);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator>(const this_type& lhs, const ReverseRandomAccessIterator<T2, P, R, C>& rhs) { return (rhs._array < lhs._array); }

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator<=(const this_type& lhs, const ReverseRandomAccessIterator<T2, P, R, C>& rhs) { return !(rhs._array < lhs._array); }

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator>=(const this_type& lhs, const ReverseRandomAccessIterator<T2, P, R, C>& rhs) { return !(lhs._array < rhs._array); }

		reference	operator[](difference_type n) { return (*(this->_array + n)); }
	};
	template <typename T, typename P, typename R, typename C>
	inline ReverseRandomAccessIterator<T,P,R,C>	operator+
		(typename ReverseRandomAccessIterator<T,P,R,C>::difference_type lhs, const ReverseRandomAccessIterator<T,P,R,C>& rhs) { return rhs + lhs; }
}

# endif