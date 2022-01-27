#ifndef STACK_HPP
# define STACK_HPP

# include <deque>
#include <iostream>

namespace ft
{
	template <class T, class Container = std::deque<T> > class stack
	{
		public:

			/*
			** The first template parameter (T)
			*/
			typedef T	value_type;

			/*
			** The second template parameter (container)
			** It's the type of underlying container object.
			*/
			typedef Container container_type;

			/*
			** The size type (usually size_t)
			*/
			typedef size_t	size_type;

		
	};

	template <class T, class Container>
		bool operator== (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct == rhs.ct); }

	template <class T, class Container>
		bool operator!= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct != rhs.ct); }

	template <class T, class Container>
		bool operator< (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct < rhs.ct); }

	template <class T, class Container>
		bool operator<= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct <= rhs.ct); }	
	
	template <class T, class Container>
		bool operator> (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct > rhs.ct); }

	template <class T, class Container>
		bool operator>= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct >= rhs.ct); }	
}

#endif
