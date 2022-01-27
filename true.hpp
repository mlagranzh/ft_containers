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

			/*
			** Default constructor.
			** Construct an empty stack container adaptor object.
			**
			** @param Container object, is the type of the
			** underlying container type.
			*/
			explicit stack (const container_type& ctnr = container_type())
			:
				ct(ctnr)
			{}


			const value_type& top() const { return (this->ct.back()); }


			template <class Tn, class ContainerN>
				friend bool operator== (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator!= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);
			
			template <class Tn, class ContainerN>
				friend bool operator< (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator<= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator> (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

			template <class Tn, class ContainerN>
				friend bool operator>= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

		protected:
			container_type ct;
	};

	template <class T, class Container>
		bool operator== (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct == rhs.ct); }

    /*
    ** @brief Compare stack container to know
    ** if they are different. Equivalent to !(lsh == rhs).
    **
    ** @param lhs stack to compare with "rhs".
    ** @param rhs stack for comparison of "lhs".
    ** @return true if they are different, false otherwise.
    */
	template <class T, class Container>
		bool operator!= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct != rhs.ct); }

    /*
    ** @brief Compare stack container to know
    ** if "lhs" elements are less than "rhs".
    **
    ** @param lhs stack to compare with "rhs".
    ** @param rhs stack for comparison of "lhs".
    ** @return true if "lhs" is less, false otherwise.
    */
	template <class T, class Container>
		bool operator< (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct < rhs.ct); }

    /*
    ** @brief Compare stack container to know
    ** if "lhs" elements are less or equal than "rhs".
    **
    ** @param lhs stack to compare with "rhs".
    ** @param rhs stack for comparison of "lhs".
    ** @return true if "lhs" is less of equal, false otherwise.
    */
	template <class T, class Container>
		bool operator<= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct <= rhs.ct); }	
	
    /*
    ** @brief Compare stack container to know
    ** if "lhs" elements are superior than "rhs".
    **
    ** @param lhs stack to compare with "rhs".
    ** @param rhs stack for comparison of "lhs".
    ** @return true if "lhs" is superior, false otherwise.
    */
	template <class T, class Container>
		bool operator> (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct > rhs.ct); }

    /*
    ** @brief Compare stack container to know
    ** if "lhs" elements are superior or equal than "rhs".
    **
    ** @param lhs stack to compare with "rhs".
    ** @param rhs stack for comparison of "lhs".
    ** @return true if "lhs" is superior or equal, false otherwise.
    */
	template <class T, class Container>
		bool operator>= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
		{ return (lhs.ct >= rhs.ct); }	
}

#endif
