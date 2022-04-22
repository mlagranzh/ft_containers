/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:53:26 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/20 01:17:30 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>

template<typename Container>
void	print(Container& x)
{
	for (typename Container::iterator it = x.begin(); it != x.end(); ++it)
		std::cout << *it;
	std::cout << '\n';
}

int	main(void)
{
	std::cout << "--------------------VECTOR's TESTS---------------------------\n\n";
	{
		std::cout << "--------------------vector<char> tests-----------------------\n";

		std::vector<char>	a;
		ft::vector<char>	b;

		for (char letter = 'a'; letter <= 'z'; ++letter)
		{
			a.push_back(letter);
			b.push_back(letter);
		}

		{
			std::cout << "vector()\n";

			std::vector<char>	a1;
			ft::vector<char>	b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector(size, value)\n";

			std::vector<char>	a1(10, 'x');
			ft::vector<char>	b1(10, 'x');

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector(it, it)\n";

			std::vector<char>	a1(a.begin(), a.end());
			ft::vector<char>	b1(b.begin(), b.end());

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector(src_vector)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.operator=(rhs_vector)\n";

			std::vector<char>	a1 = a;
			ft::vector<char>	b1 = b;

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.assign(size, value)\n";

			std::vector<char>	a1;
			ft::vector<char>	b1;

			a1.assign(10, 'x');
			b1.assign(10, 'x');
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.assign(it, it)\n";

			std::vector<char>	a1;
			ft::vector<char>	b1;

			a1.assign(a.begin(), a.end());
			b1.assign(b.begin(), b.end());
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.at(num)\n";

			std::cout << "a.at(2) = " << a.at(2) << '\n';
			std::cout << "b.at(2) = " << b.at(2) << '\n';
			try
			{
				std::cout << "a.at(26) = " << a.at(26) << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				std::cout << "b.at(26) = " << b.at(26) << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << '\n';
		}

		{
			std::cout << "vector[num]\n";

			std::cout << "a[2] = " << a[2] << '\n';
			std::cout << "b[2] = " << b[2] << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.front()\n";

			std::cout << "a.front() = " << a.front() << '\n';
			std::cout << "b.front() = " << b.front() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.back()\n";

			std::cout << "a.back() = " << a.back() << '\n';
			std::cout << "b.back() = " << b.back() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.data()\n";

			std::cout << "*(a.data() + 2) = " << *(a.data() + 2) << '\n';
			std::cout << "*(b.data() + 2) = " << *(b.data() + 2) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.begin()\n";

			std::cout << "*(a.begin()) = " << *(a.begin()) << '\n';
			std::cout << "*(b.begin()) = " << *(b.begin()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.end()\n";

			std::cout << "*(a.end() - 1) = " << *(a.end() - 1) << '\n';
			std::cout << "*(b.end() - 1) = " << *(b.end() - 1) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.rbegin()\n";

			std::cout << "*(a.rbegin()) = " << *(a.rbegin()) << '\n';
			std::cout << "*(b.rbegin()) = " << *(b.rbegin()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.rend()\n";

			std::cout << "*(a.rend() - 1) = " << *(a.rend() - 1) << '\n';
			std::cout << "*(b.rend() - 1) = " << *(b.rend() - 1) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.max_size()\n";

			std::cout << "a.max_size() = " << a.max_size() << '\n';
			std::cout << "b.max_size() = " << b.max_size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.reserve(size)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.reserve(33)\n";
			std::cout << "b.reserve(33)\n";
			a1.reserve(33);
			b1.reserve(33);
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.reserve(a.max_size() + 1)\n";
			std::cout << "b.reserve(b.max_size() + 1)\n";
			try
			{
				a1.reserve(a1.max_size() + 1);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				b1.reserve(b1.max_size() + 1);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << '\n';
		}

		{
			std::cout << "vector.capasity()\n";

			std::cout << "a.capacity() = " << a.capacity() << '\n';
			std::cout << "b.capacity() = " << b.capacity() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.clear()\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.clear()\n";
			std::cout << "b.clear()\n";
			a1.clear();
			b1.clear();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.insert(it, value)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.insert(a.begin() + 3, 'X')\t return: iterator(" \
				<< *(a1.insert(a1.begin() + 3, 'X')) << ")\n";
			std::cout << "b.insert(b.begin() + 3, 'X')\t return: iterator(" \
				<< *(b1.insert(b1.begin() + 3, 'X')) << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.insert(it, num, value)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.insert(a.begin() + 3, 3, 'X')\n";
			std::cout << "b.insert(b.begin() + 3, 3, 'X')\n";
			a1.insert(a1.begin() + 3, 3, 'X');
			b1.insert(b1.begin() + 3, 3, 'X');
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.insert(it, InputIt, InputIt)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);
			std::vector<char>	c(5, 'X');

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.insert(a.begin() + 5, c.begin(), c.end())\n";
			std::cout << "b.insert(b.begin() + 5, d.begin(), d.end())\n";
			a1.insert(a1.begin() + 5, c.begin(), c.end());
			b1.insert(b1.begin() + 5, c.begin(), c.end());
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.erase(it)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.erase(a.begin() + 2)\t return: iterator(" \
				<< *(a1.erase(a1.begin() + 2)) << ")\n";
			std::cout << "b.erase(b.begin() + 2)\t return: iterator(" \
				<< *(b1.erase(b1.begin() + 2)) << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.erase(it, it)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.erase(a.begin() + 2, a1.end() - 2)\t return: iterator(" \
				<< *(a1.erase(a1.begin() + 2, a1.end() - 2)) << ")\n";
			std::cout << "b.erase(b.begin() + 2, b1.end() - 2)\t return: iterator(" \
				<< *(b1.erase(b1.begin() + 2, b1.end() - 2)) << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.push_back(value)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.push_back('X')\n";
			std::cout << "b.push_back('X')\n";
			a1.push_back('X');
			b1.push_back('X');
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.pop_back()\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.pop_back()\n";
			std::cout << "b.pop_back()\n";
			a1.pop_back();
			b1.pop_back();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.resize(size, value)\n";

			std::vector<char>	a1(a);
			ft::vector<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.resize(10, 'X')\n";
			std::cout << "b.resize(10, 'X')\n";
			a1.resize(10, 'X');
			b1.resize(10, 'X');
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.resize(15, 'X')\n";
			std::cout << "b.resize(15, 'X')\n";
			a1.resize(15, 'X');
			b1.resize(15, 'X');
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.resize(20)\n";
			std::cout << "b.resize(20)\n";
			a1.resize(20);
			b1.resize(20);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.resize(33)\n";
			std::cout << "b.resize(33)\n";
			a1.resize(33);
			b1.resize(33);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.swap(other)\n";

			ft::vector<char>	a1(b);
			ft::vector<char>	b1(10, 'X');

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.swap(b)\n";
			a1.swap(b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "swap(vector_x, vector_y)\n";

			ft::vector<char>	a1(b);
			ft::vector<char>	b1(10, 'X');

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "swap(a, b)\n";
			swap(a1, b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector relational operators\n";

			ft::vector<char>	a1(b);
			ft::vector<char>	b1(10, 'X');
			ft::vector<char>	c(b);

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

	/* ----------------------------------------------------------------------------------- */

	{
		std::cout << "------------------vector<std::string> tests-------------------\n";

		std::vector<std::string>	a;
		ft::vector<std::string>		b;

		for (std::string letter = "a"; letter != "z"; ++letter[0])
		{
			a.push_back(letter);
			b.push_back(letter);
		}
		a.push_back("z");
		b.push_back("z");
	
		{
			std::cout << "vector()\n";

			std::vector<std::string>	a1;
			ft::vector<std::string>		b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector(size, value)\n";

			std::vector<std::string>	a1(10, "x");
			ft::vector<std::string>		b1(10, "x");

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector(it, it)\n";

			std::vector<std::string>	a1(a.begin(), a.end());
			ft::vector<std::string>		b1(b.begin(), b.end());

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector(src_vector)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.operator=(rhs_vector)\n";

			std::vector<std::string>	a1 = a;
			ft::vector<std::string>		b1 = b;

			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.assign(size, value)\n";

			std::vector<std::string>	a1;
			ft::vector<std::string>		b1;

			a1.assign(10, "x");
			b1.assign(10, "x");
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.assign(it, it)\n";

			std::vector<std::string>	a1;
			ft::vector<std::string>		b1;

			a1.assign(a.begin(), a.end());
			b1.assign(b.begin(), b.end());
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.at(num)\n";

			std::cout << "a.at(2) = " << a.at(2) << '\n';
			std::cout << "b.at(2) = " << b.at(2) << '\n';
			try
			{
				std::cout << "a.at(26) = " << a.at(26) << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				std::cout << "b.at(26) = " << b.at(26) << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << '\n';
		}

		{
			std::cout << "vector[num]\n";

			std::cout << "a[2] = " << a[2] << '\n';
			std::cout << "b[2] = " << b[2] << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.front()\n";

			std::cout << "a.front() = " << a.front() << '\n';
			std::cout << "b.front() = " << b.front() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.back()\n";

			std::cout << "a.back() = " << a.back() << '\n';
			std::cout << "b.back() = " << b.back() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.data()\n";

			std::cout << "*(a.data() + 2) = " << *(a.data() + 2) << '\n';
			std::cout << "*(b.data() + 2) = " << *(b.data() + 2) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.begin()\n";

			std::cout << "*(a.begin()) = " << *(a.begin()) << '\n';
			std::cout << "*(b.begin()) = " << *(b.begin()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.end()\n";

			std::cout << "*(a.end() - 1) = " << *(a.end() - 1) << '\n';
			std::cout << "*(b.end() - 1) = " << *(b.end() - 1) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.rbegin()\n";

			std::cout << "*(a.rbegin()) = " << *(a.rbegin()) << '\n';
			std::cout << "*(b.rbegin()) = " << *(b.rbegin()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.rend()\n";

			std::cout << "*(a.rend() - 1) = " << *(a.rend() - 1) << '\n';
			std::cout << "*(b.rend() - 1) = " << *(b.rend() - 1) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.max_size()\n";

			std::cout << "a.max_size() = " << a.max_size() << '\n';
			std::cout << "b.max_size() = " << b.max_size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.reserve(size)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.reserve(33)\n";
			std::cout << "b.reserve(33)\n";
			a1.reserve(33);
			b1.reserve(33);
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.reserve(a.max_size() + 1)\n";
			std::cout << "b.reserve(b.max_size() + 1)\n";
			try
			{
				a1.reserve(a1.max_size() + 1);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				b1.reserve(b1.max_size() + 1);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << '\n';
		}

		{
			std::cout << "vector.capasity()\n";

			std::cout << "a.capacity() = " << a.capacity() << '\n';
			std::cout << "b.capacity() = " << b.capacity() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.clear()\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.clear()\n";
			std::cout << "b.clear()\n";
			a1.clear();
			b1.clear();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "vector.insert(it, value)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.insert(a.begin() + 3, \"X\")\t return: iterator(" \
				<< *(a1.insert(a1.begin() + 3, "X")) << ")\n";
			std::cout << "b.insert(b.begin() + 3, \"X\")\t return: iterator(" \
				<< *(b1.insert(b1.begin() + 3, "X")) << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.insert(it, num, value)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.insert(a.begin() + 3, 3, \"X\")\n";
			std::cout << "b.insert(b.begin() + 3, 3, \"X\")\n";
			a1.insert(a1.begin() + 3, 3, "X");
			b1.insert(b1.begin() + 3, 3, "X");
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.insert(it, InputIt, InputIt)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);
			std::vector<std::string>	c(5, "X");

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.insert(a.begin() + 5, c.begin(), c.end())\n";
			std::cout << "b.insert(b.begin() + 5, d.begin(), d.end())\n";
			a1.insert(a1.begin() + 5, c.begin(), c.end());
			b1.insert(b1.begin() + 5, c.begin(), c.end());
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.erase(it)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.erase(a.begin() + 2)\t return: iterator(" \
				<< *(a1.erase(a1.begin() + 2)) << ")\n";
			std::cout << "b.erase(b.begin() + 2)\t return: iterator(" \
				<< *(b1.erase(b1.begin() + 2)) << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.erase(it, it)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.erase(a.begin() + 2, a1.end() - 2)\t return: iterator(" \
				<< *(a1.erase(a1.begin() + 2, a1.end() - 2)) << ")\n";
			std::cout << "b.erase(b.begin() + 2, b1.end() - 2)\t return: iterator(" \
				<< *(b1.erase(b1.begin() + 2, b1.end() - 2)) << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.push_back(value)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.push_back(\"X\")\n";
			std::cout << "b.push_back(\"X\")\n";
			a1.push_back("X");
			b1.push_back("X");
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.pop_back()\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.pop_back()\n";
			std::cout << "b.pop_back()\n";
			a1.pop_back();
			b1.pop_back();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.resize(size, value)\n";

			std::vector<std::string>	a1(a);
			ft::vector<std::string>		b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			std::cout << "a.resize(10, \"X\")\n";
			std::cout << "b.resize(10, \"X\")\n";
			a1.resize(10, "X");
			b1.resize(10, "X");
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.resize(15, \"X\")\n";
			std::cout << "b.resize(15, \"X\")\n";
			a1.resize(15, "X");
			b1.resize(15, "X");
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.resize(20)\n";
			std::cout << "b.resize(20)\n";
			a1.resize(20);
			b1.resize(20);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.resize(33)\n";
			std::cout << "b.resize(33)\n";
			a1.resize(33);
			b1.resize(33);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector.swap(other)\n";

			ft::vector<std::string>	a1(b);
			ft::vector<std::string>	b1(10, "X");

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.swap(b)\n";
			a1.swap(b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "swap(vector_x, vector_y)\n";

			ft::vector<std::string>	a1(b);
			ft::vector<std::string>	b1(10, "X");

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << "swap(a, b)\n";
			swap(a1, b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.capacity() = " << a1.capacity() << '\n';
			std::cout << "b.capacity() = " << b1.capacity() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "vector relational operators\n";

			ft::vector<std::string>	a1(b);
			ft::vector<std::string>	b1(10, "X");
			ft::vector<std::string>	c(b);

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
