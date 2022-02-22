#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	class pair
	{
		public:
			T1	first;
			T2	second;

			pair(): first(), second() {}
			pair( const T1& x, const T2& y ): first(x), second(y) {}
			pair( const pair<T1, T2> &copy): first(copy.first), second(copy.second) {}

			template <typename U, typename V>
			pair(const pair<U, V>& copy) : first(copy.first), second(copy.second) {}

			pair& operator=( const pair& other )
			{
				this->first = other.first;
				this->second = other.second;
				return *this;
			}

			~pair() {};
	};

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u ) {
		return (pair<T1, T2>(t, u));
	}
}

#endif