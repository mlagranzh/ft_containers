#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft
{
	template <class T, class Container=ft::vector<T> >

	class stack
	{
	public:
		typedef		Container	container_type;

		stack(const container_type &container=container_type()): _container(container) {}
		stack(const stack &copy): _container(copy._container) {}
		virtual ~stack() {}

		stack &operator=(stack const &other)
		{
			this->_container = other._container;
			return (*this);
		}

		size_t		size (void) const { return (_container.size()); }
		bool		empty (void) const { return (_container.empty()); }
		T			&top (void) { return (_container.back()); }
		const T		&top (void) const { return (_container.back()); }
		void		push (const T & value) { _container.push_back(value); }
		void		pop (void) { _container.pop_back(); }

		friend bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs._container == rhs._container); }
		friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs._container != rhs._container); }
		friend bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs._container < rhs._container); }
		friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs._container > rhs._container); }
		friend bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs._container <= rhs._container); }
		friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs._container >= rhs._container); }
	private:
		container_type			_container;
	};
}

#endif