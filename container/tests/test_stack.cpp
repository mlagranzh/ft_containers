/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:48:05 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/19 23:27:37 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>
#include <iostream>
#include <string>

template<typename Container>
void	print(Container& x)
{
	for (typename Container::iterator it = x.begin(); it != x.end(); ++it)
		std::cout << *it;
	std::cout << '\n';
}

template<typename T, typename Container >
class MutantStack : public Container
{
	public:
		MutantStack() {}

		MutantStack(const MutantStack<T, Container>& src)
		{
			*this = src;
		}

		MutantStack<T, Container>& operator=(const MutantStack<T, Container>& rhs) 
		{
			this->c = rhs.c;
			return *this;
		}

		~MutantStack() {}

		typedef typename Container::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}
};

int	main(void)
{
	std::cout << "--------------------STACK's TESTS---------------------------\n\n";
	{
		std::cout << "--------------------stack<char> tests-----------------------\n";

		MutantStack<char, std::stack<char> >	a;
		MutantStack<char, ft::stack<char> >		b;

		for (char letter = 'a'; letter <= 'z'; ++letter)
		{
			a.push(letter);
			b.push(letter);
		}

		{
			std::cout << "stack()\n";

			MutantStack<char, std::stack<char> >	a1;
			MutantStack<char, ft::stack<char> >		b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "stack.operator=(rhs_stack)\n";

			MutantStack<char, std::stack<char> >	a1 = a;
			MutantStack<char, ft::stack<char> >		b1 = b;

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack.top()\n";

			MutantStack<char, std::stack<char> >	a1(a);
			MutantStack<char, ft::stack<char> >		b1(b);

			std::cout << "a.top() = " << a1.top() << '\n';
			std::cout << "b.top() = " << b1.top() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "stack.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "stack.push()\n";

			MutantStack<char, std::stack<char> >	a1(a);
			MutantStack<char, ft::stack<char> >		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.push('X')\n";
			std::cout << "b.push('X')\n";
			a1.push('X');
			b1.push('X');
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack.pop()\n";

			MutantStack<char, std::stack<char> >	a1(a);
			MutantStack<char, ft::stack<char> >		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.pop()\n";
			std::cout << "b.pop()\n";
			a1.pop();
			b1.pop();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack relational operators\n";

			MutantStack<char, ft::stack<char> >	a1(b);
			MutantStack<char, ft::stack<char> >	b1(b);
			MutantStack<char, ft::stack<char> >	c(b);

			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			print(a1);
			print(b1);
			std::cout << "a == b\t" << (a1 == b1) << '\n';
			std::cout << "a != b\t" << (a1 != b1) << '\n';
			std::cout << "a <  b\t" << (a1 <  b1) << '\n';
			std::cout << "a >  b\t" << (a1 >  b1) << '\n';
			std::cout << "a <= b\t" << (a1 <= b1) << '\n';
			std::cout << "a >= b\t" << (a1 >= b1) << '\n';
			std::cout << '\n';
			print(a1);
			print(c);
			std::cout << "a == c\t" << (a1 == c) << '\n';
			std::cout << "a != c\t" << (a1 != c) << '\n';
			std::cout << "a <  c\t" << (a1 <  c) << '\n';
			std::cout << "a >  c\t" << (a1 >  c) << '\n';
			std::cout << "a <= c\t" << (a1 <= c) << '\n';
			std::cout << "a >= c\t" << (a1 >= c) << '\n';
			std::cout << '\n';
		}
	}

	{
		std::cout << "--------------------stack<std::string> tests-----------------------\n";

		MutantStack<std::string, std::stack<std::string> >	a;
		MutantStack<std::string, ft::stack<std::string> >	b;

		for (std::string letter = "a"; letter <= "z"; ++letter[0])
		{
			a.push(letter);
			b.push(letter);
		}

		{
			std::cout << "stack()\n";

			MutantStack<std::string, std::stack<std::string> >	a1;
			MutantStack<std::string, ft::stack<std::string> >	b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "stack.operator=(rhs_stack)\n";

			MutantStack<std::string, std::stack<std::string> >	a1 = a;
			MutantStack<std::string, ft::stack<std::string> >	b1 = b;

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack.top()\n";

			MutantStack<std::string, std::stack<std::string> >	a1(a);
			MutantStack<std::string, ft::stack<std::string> >	b1(b);

			std::cout << "a.top() = " << a1.top() << '\n';
			std::cout << "b.top() = " << b1.top() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "stack.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "stack.push()\n";

			MutantStack<std::string, std::stack<std::string> >	a1(a);
			MutantStack<std::string, ft::stack<std::string> >	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.push('X')\n";
			std::cout << "b.push('X')\n";
			a1.push("X");
			b1.push("X");
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack.pop()\n";

			MutantStack<std::string, std::stack<std::string> >	a1(a);
			MutantStack<std::string, ft::stack<std::string> >	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.pop()\n";
			std::cout << "b.pop()\n";
			a1.pop();
			b1.pop();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "stack relational operators\n";

			MutantStack<std::string, ft::stack<std::string> >	a1(b);
			MutantStack<std::string, ft::stack<std::string> >	b1(b);
			MutantStack<std::string, ft::stack<std::string> >	c(b);

			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			b1.pop();
			print(a1);
			print(b1);
			std::cout << "a == b\t" << (a1 == b1) << '\n';
			std::cout << "a != b\t" << (a1 != b1) << '\n';
			std::cout << "a <  b\t" << (a1 <  b1) << '\n';
			std::cout << "a >  b\t" << (a1 >  b1) << '\n';
			std::cout << "a <= b\t" << (a1 <= b1) << '\n';
			std::cout << "a >= b\t" << (a1 >= b1) << '\n';
			std::cout << '\n';
			print(a1);
			print(c);
			std::cout << "a == c\t" << (a1 == c) << '\n';
			std::cout << "a != c\t" << (a1 != c) << '\n';
			std::cout << "a <  c\t" << (a1 <  c) << '\n';
			std::cout << "a >  c\t" << (a1 >  c) << '\n';
			std::cout << "a <= c\t" << (a1 <= c) << '\n';
			std::cout << "a >= c\t" << (a1 >= c) << '\n';
			std::cout << '\n';
		}
	}
	return (0);
}
