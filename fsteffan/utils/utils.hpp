#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <functional>

namespace ft 
{
	template <class T>
    struct cmp
    {        
        bool operator() (const T& x, const T& y) const {return x<y;}
    };

	template<typename Iterator>
	ptrdiff_t distance(Iterator first, Iterator last) {
		ptrdiff_t dist = 0;

		for (; first != last; ++first){
			dist++;
		}
		return dist;
	}

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n) {
		if (n > 0)
			while (n) {
				++it;
				--n;
			}
		else while (n) {
			--it;
			++n;
		}
	}

	template <class Iterator1, class Iterator2>
	bool equal(Iterator1 first1, Iterator1 last1, Iterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <bool isConst, typename isFalse, typename isTrue>
	struct chooseConst {};

	template <typename isFalse, typename isTrue>
	struct chooseConst<false, isFalse, isTrue> {
		typedef isFalse type;
	};

	template <typename isFalse, typename isTrue>
	struct chooseConst<true, isFalse, isTrue> {
		typedef isTrue type;
	};
}

#endif
