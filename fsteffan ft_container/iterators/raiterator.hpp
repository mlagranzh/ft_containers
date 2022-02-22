#ifndef RAITERATOR_HPP
# define RAITERATOR_HPP

namespace ft
{
	template < typename T, typename Pointer, typename Reference, class Category = std::random_access_iterator_tag >
	class RandomAccessIterator {
	public:
		typedef RandomAccessIterator<T, Pointer, Reference>			this_type;
		typedef RandomAccessIterator<T, T*, T&>						iterator;
		typedef RandomAccessIterator<T, const T*, const T&>			const_iterator;
		typedef Pointer												pointer;
		typedef Reference											reference;
		typedef size_t												size_type;
		typedef ptrdiff_t											difference_type;

		pointer	_array;

		RandomAccessIterator() : _array(NULL) {}
		RandomAccessIterator(const pointer elem) : _array(elem) {}
		RandomAccessIterator(const iterator& copy) : _array(const_cast<pointer>(copy._array)) { }
		virtual ~RandomAccessIterator() {}

		this_type&	operator=(const iterator& other)
		{
			this->_array = other._array;
			return (*this);
		}

		this_type&	operator++() { this->_array++; return *this; }
		this_type&	operator--() { --this->_array; return *this; }
		this_type&	operator+=(difference_type n) {
			this->_array += n;
			return *this;
		}
		this_type&	operator-=(difference_type n) { this->_array -= n; return *this; }

		this_type	operator++(int) {
			this_type out(*this);
			++this->_array;
			return out;
		}

		this_type	operator--(int) {
			this_type out(*this);
			--this->_array;
			return out;
		}

		this_type	operator+(difference_type n) const {
			this_type out(*this);

			out._array += n;
			return out;
		}

		this_type	operator-(difference_type n) const {
			this_type out(*this);
			out -= n;
			return out;
		}
		
		reference	operator*() { return *this->_array; }
		pointer		operator->() { return *(&(this->_array)); }
		difference_type	operator-(RandomAccessIterator it) const { return this->_array - it._array;}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator==(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs) {
			return (lhs._array == rhs._array);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator!=(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs) { return !(lhs == rhs); }

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator<(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs) {
			return (lhs._array < rhs._array);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator>(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs) { return (rhs < lhs); }

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator<=(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs) { return !(rhs < lhs); }

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator>=(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs) { return !(lhs < rhs); }

		reference	operator[](difference_type n) { return (*(this->_array + n)); }
	};
	template <typename T, typename P, typename R, typename C>
	inline RandomAccessIterator<T,P,R,C>	operator+
		(typename RandomAccessIterator<T,P,R,C>::difference_type lhs, const RandomAccessIterator<T,P,R,C>& rhs) { return rhs + lhs; }
}


#endif