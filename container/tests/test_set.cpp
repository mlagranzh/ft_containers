/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:30:12 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/20 03:09:17 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
#include <set>
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
	std::cout << "--------------------SET's TESTS---------------------------\n\n";
	{
		std::cout << "--------------------set<char> tests------------------\n";

		std::set<char>	a;
		ft::set<char>	b;

		for (char letter = 'a'; letter <= 'z'; ++letter)
		{
			a.insert(letter);
			b.insert(letter);
		}

		{
			std::cout << "set()\n";

			std::set<char>	a1;
			ft::set<char>	b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set(it, it)\n";

			std::set<char>	a1(a.begin(), a.end());
			ft::set<char>	b1(b.begin(), b.end());

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set(src_set)\n";

			std::set<char>	a1(a);
			ft::set<char>	b1(b);

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.operator=(src_set)\n";

			std::set<char>	a1 = a;
			ft::set<char>	b1 = b;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.begin()\n";

			std::cout << "*a.begin() = " << *a.begin() << '\n';
			std::cout << "*b.begin() = " << *b.begin() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.end()\n";

			std::cout << "*(--a.end()) = " << *(--a.end()) << '\n';
			std::cout << "*(--b.end()) = " << *(--b.end()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.rbegin()\n";

			std::cout << "*a.rbegin() = " << *a.rbegin() << '\n';
			std::cout << "*b.rbegin() = " << *b.rbegin() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.rend()\n";

			std::cout << "*(--a.rend()) = " << *(--a.rend()) << '\n';
			std::cout << "*(--b.rend()) = " << *(--b.rend()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.max_size()\n";

			std::cout << "a.max_size() = " << a.max_size() << '\n';
			std::cout << "b.max_size() = " << b.max_size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.clear()\n";

			std::set<char>	a1(a);
			ft::set<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.clear()\n";
			std::cout << "b.clear()\n";
			a1.clear();
			b1.clear();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.insert(value)\n";

			std::set<char>	a1(a);
			ft::set<char>	b1(b);

			std::pair<std::set<char>::iterator, bool>	ret_a;
			ft::pair<ft::set<char>::iterator, bool>		ret_b;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			ret_a = a1.insert('X');
			ret_b = b1.insert('X');
			std::cout << "a.insert('X')\t return: pair<" \
				<< *ret_a.first << ", " << ret_a.second << ">\n";
			std::cout << "b.insert('X')\t return: pair<" \
				<< *ret_b.first << ", " << ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert('Z');
			ret_b = b1.insert('Z');
			std::cout << "a.insert('Z')\t return: pair<" \
				<< *ret_a.first << ", " << ret_a.second << ">\n";
			std::cout << "b.insert('Z')\t return: pair<" \
				<< *ret_b.first << ", " << ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert('c');
			ret_b = b1.insert('c');
			std::cout << "a.insert('c')\t return: pair<" \
				<< *ret_a.first << ", " << ret_a.second << ">\n";
			std::cout << "b.insert('c')\t return: pair<" \
				<< *ret_b.first << ", " << ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.insert(it, value)\n";

			std::set<char>	a1(a);
			ft::set<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.insert(a.begin(), 'X')\t return: iterator(" \
				<< *a1.insert(a1.begin(), 'X') << ")\n";
			std::cout << "b.insert(b.begin(), 'X')\t return: iterator(" \
				<< *b1.insert(b1.begin(), 'X') << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.insert(a.begin(), 'c')\t return: iterator(" \
				<< *a1.insert(a1.begin(), 'c') << ")\n";
			std::cout << "b.insert(b.begin(), 'c')\t return: iterator(" \
				<< *b1.insert(b1.begin(), 'c') << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.insert(it, it)\n";

			std::set<char>	a1;
			ft::set<char>	b1;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.insert(other.begin(), other.find('k'))\n";
			std::cout << "b.insert(other.begin(), other.find('k'))\n";
			a1.insert(a.begin(), a.find('k'));
			b1.insert(b.begin(), b.find('k'));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.erase(it)\n";

			std::set<char>	a1(a);
			ft::set<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.find('c'))\n";
			std::cout << "b.erase(b.find('c'))\n";
			a1.erase(a1.find('c'));
			b1.erase(b1.find('c'));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.erase(key)\n";

			std::set<char>	a1(a);
			ft::set<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase('c')\t return: " << a1.erase('c') << '\n';
			std::cout << "b.erase('c')\t return: " << b1.erase('c') << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.erase('X')\t return: " << a1.erase('X') << '\n';
			std::cout << "b.erase('X')\t return: " << b1.erase('X') << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.erase(it, it)\n";

			std::set<char>	a1(a);
			ft::set<char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.begin(), a.find('k'))\n";
			std::cout << "b.erase(b.begin(), b.find('k'))\n";
			a1.erase(a1.begin(), a1.find('k'));
			b1.erase(b1.begin(), b1.find('k'));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.swap(other)\n";

			ft::set<char>	a1(b);
			ft::set<char>	b1(b.begin(), b.find('k'));

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.swap(b)\n";
			a1.swap(b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.count(key)\n";

			std::cout << "a.count('c')\t return: " << a.count('c') << '\n';
			std::cout << "b.count('c')\t return: " << b.count('c') << '\n';
			std::cout << "a.count('X')\t return: " << a.count('X') << '\n';
			std::cout << "b.count('X')\t return: " << b.count('X') << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.find(key)\n";

			std::set<char>::iterator	ret_a;
			ft::set<char>::iterator		ret_b;

			std::cout << "a.find('c')\t return: ";
			ret_a = a.find('c');
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find('c')\t return: ";
			ret_b = b.find('c');
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.find('X')\t return: ";
			ret_a = a.find('X');
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find('X')\t return: ";
			ret_b = b.find('X');
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.equal_range(key)\n";

			std::pair<std::set<char>::iterator, std::set<char>::iterator>	ret_a;
			ft::pair<ft::set<char>::iterator, ft::set<char>::iterator>		ret_b;

			std::cout << "a.equal_range('c')\t return: ";
			ret_a = a.equal_range('c');
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(" << *ret_a.first << "), " \
				<< "iterator(" << *ret_a.second << ")>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range('c')\t return: ";
			ret_b = b.equal_range('c');
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(" << *ret_b.first << "), " \
				<< "iterator(" << *ret_b.second << ")>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			std::cout << "a.equal_range('X')\t return: ";
			ret_a = a.equal_range('X');
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(" << *ret_a.first << "), " \
				<< "iterator(" << *ret_a.second << ")>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range('X')\t return: ";
			ret_b = b.equal_range('X');
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(" << *ret_b.first << "), " \
				<< "iterator(" << *ret_b.second << ")>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.lower_bound(key)\n";

			std::set<char>::iterator	ret_a;
			ft::set<char>::iterator		ret_b;

			std::cout << "a.lower_bound('c')\t return: ";
			ret_a = a.lower_bound('c');
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound('c')\t return: ";
			ret_b = b.lower_bound('c');
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.lower_bound('X')\t return: ";
			ret_a = a.lower_bound('X');
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound('X')\t return: ";
			ret_b = b.lower_bound('X');
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.upper_bound(key)\n";

			std::set<char>::iterator	ret_a;
			ft::set<char>::iterator		ret_b;

			std::cout << "a.upper_bound('c')\t return: ";
			ret_a = a.upper_bound('c');
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound('c')\t return: ";
			ret_b = b.upper_bound('c');
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.upper_bound('X')\t return: ";
			ret_a = a.upper_bound('X');
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound('X')\t return: ";
			ret_b = b.upper_bound('X');
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "swap(set_x, set_y)\n";

			ft::set<char>	a1(b);
			ft::set<char>	b1(b.begin(), b.find('k'));

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "swap(a, b)\n";
			swap(a1, b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set relational operators\n";

			ft::set<char>	a1(b);
			ft::set<char>	b1(b.begin(), b.find('k'));
			ft::set<char>	c(b);

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
		std::cout << "--------------------set<std::string> tests------------------\n";

		std::set<std::string>	a;
		ft::set<std::string>	b;

		for (std::string letter = "a"; letter <= "z"; ++letter[0])
		{
			a.insert(letter);
			b.insert(letter);
		}

		{
			std::cout << "set()\n";

			std::set<std::string>	a1;
			ft::set<std::string>	b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set(it, it)\n";

			std::set<std::string>	a1(a.begin(), a.end());
			ft::set<std::string>	b1(b.begin(), b.end());

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set(src_set)\n";

			std::set<std::string>	a1(a);
			ft::set<std::string>	b1(b);

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.operator=(src_set)\n";

			std::set<std::string>	a1 = a;
			ft::set<std::string>	b1 = b;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.begin()\n";

			std::cout << "*a.begin() = " << *a.begin() << '\n';
			std::cout << "*b.begin() = " << *b.begin() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.end()\n";

			std::cout << "*(--a.end()) = " << *(--a.end()) << '\n';
			std::cout << "*(--b.end()) = " << *(--b.end()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.rbegin()\n";

			std::cout << "*a.rbegin() = " << *a.rbegin() << '\n';
			std::cout << "*b.rbegin() = " << *b.rbegin() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.rend()\n";

			std::cout << "*(--a.rend()) = " << *(--a.rend()) << '\n';
			std::cout << "*(--b.rend()) = " << *(--b.rend()) << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.max_size()\n";

			std::cout << "a.max_size() = " << a.max_size() << '\n';
			std::cout << "b.max_size() = " << b.max_size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.clear()\n";

			std::set<std::string>	a1(a);
			ft::set<std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.clear()\n";
			std::cout << "b.clear()\n";
			a1.clear();
			b1.clear();
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "set.insert(value)\n";

			std::set<std::string>	a1(a);
			ft::set<std::string>	b1(b);

			std::pair<std::set<std::string>::iterator, bool>	ret_a;
			ft::pair<ft::set<std::string>::iterator, bool>		ret_b;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			ret_a = a1.insert("X");
			ret_b = b1.insert("X");
			std::cout << "a.insert(\"X\")\t return: pair<" \
				<< *ret_a.first << ", " << ret_a.second << ">\n";
			std::cout << "b.insert(\"X\")\t return: pair<" \
				<< *ret_b.first << ", " << ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert("Z");
			ret_b = b1.insert("Z");
			std::cout << "a.insert(\"Z\")\t return: pair<" \
				<< *ret_a.first << ", " << ret_a.second << ">\n";
			std::cout << "b.insert(\"Z\")\t return: pair<" \
				<< *ret_b.first << ", " << ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert("c");
			ret_b = b1.insert("c");
			std::cout << "a.insert(\"c\")\t return: pair<" \
				<< *ret_a.first << ", " << ret_a.second << ">\n";
			std::cout << "b.insert(\"c\")\t return: pair<" \
				<< *ret_b.first << ", " << ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.insert(it, value)\n";

			std::set<std::string>	a1(a);
			ft::set<std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.insert(a.begin(), \"X\")\t return: iterator(" \
				<< *a1.insert(a1.begin(), "X") << ")\n";
			std::cout << "b.insert(b.begin(), \"X\")\t return: iterator(" \
				<< *b1.insert(b1.begin(), "X") << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.insert(a.begin(), \"c\")\t return: iterator(" \
				<< *a1.insert(a1.begin(), "c") << ")\n";
			std::cout << "b.insert(b.begin(), \"c\")\t return: iterator(" \
				<< *b1.insert(b1.begin(), "c") << ")\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.insert(it, it)\n";

			std::set<std::string>	a1;
			ft::set<std::string>	b1;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.insert(other.begin(), other.find(\"k\"))\n";
			std::cout << "b.insert(other.begin(), other.find(\"k\"))\n";
			a1.insert(a.begin(), a.find("k"));
			b1.insert(b.begin(), b.find("k"));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.erase(it)\n";

			std::set<std::string>	a1(a);
			ft::set<std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.find(\"c\"))\n";
			std::cout << "b.erase(b.find(\"c\"))\n";
			a1.erase(a1.find("c"));
			b1.erase(b1.find("c"));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.erase(key)\n";

			std::set<std::string>	a1(a);
			ft::set<std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(\"c\")\t return: " << a1.erase("c") << '\n';
			std::cout << "b.erase(\"c\")\t return: " << b1.erase("c") << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.erase(\"X\")\t return: " << a1.erase("X") << '\n';
			std::cout << "b.erase(\"X\")\t return: " << b1.erase("X") << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.erase(it, it)\n";

			std::set<std::string>	a1(a);
			ft::set<std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.begin(), a.find(\"k\"))\n";
			std::cout << "b.erase(b.begin(), b.find(\"k\"))\n";
			a1.erase(a1.begin(), a1.find("k"));
			b1.erase(b1.begin(), b1.find("k"));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.swap(other)\n";

			ft::set<std::string>	a1(b);
			ft::set<std::string>	b1(b.begin(), b.find("k"));

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.swap(b)\n";
			a1.swap(b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set.count(key)\n";

			std::cout << "a.count(\"c\")\t return: " << a.count("c") << '\n';
			std::cout << "b.count(\"c\")\t return: " << b.count("c") << '\n';
			std::cout << "a.count(\"X\")\t return: " << a.count("X") << '\n';
			std::cout << "b.count(\"X\")\t return: " << b.count("X") << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.find(key)\n";

			std::set<std::string>::iterator	ret_a;
			ft::set<std::string>::iterator		ret_b;

			std::cout << "a.find(\"c\")\t return: ";
			ret_a = a.find("c");
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find(\"c\")\t return: ";
			ret_b = b.find("c");
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.find(\"X\")\t return: ";
			ret_a = a.find("X");
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find(\"X\")\t return: ";
			ret_b = b.find("X");
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.equal_range(key)\n";

			std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator>	ret_a;
			ft::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator>		ret_b;

			std::cout << "a.equal_range(\"c\")\t return: ";
			ret_a = a.equal_range("c");
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(" << *ret_a.first << "), " \
				<< "iterator(" << *ret_a.second << ")>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range(\"c\")\t return: ";
			ret_b = b.equal_range("c");
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(" << *ret_b.first << "), " \
				<< "iterator(" << *ret_b.second << ")>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			std::cout << "a.equal_range(\"X\")\t return: ";
			ret_a = a.equal_range("X");
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(" << *ret_a.first << "), " \
				<< "iterator(" << *ret_a.second << ")>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range(\"X\")\t return: ";
			ret_b = b.equal_range("X");
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(" << *ret_b.first << "), " \
				<< "iterator(" << *ret_b.second << ")>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.lower_bound(key)\n";

			std::set<std::string>::iterator	ret_a;
			ft::set<std::string>::iterator		ret_b;

			std::cout << "a.lower_bound(\"c\")\t return: ";
			ret_a = a.lower_bound("c");
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound(\"c\")\t return: ";
			ret_b = b.lower_bound("c");
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.lower_bound(\"X\")\t return: ";
			ret_a = a.lower_bound("X");
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound(\"X\")\t return: ";
			ret_b = b.lower_bound("X");
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "set.upper_bound(key)\n";

			std::set<std::string>::iterator	ret_a;
			ft::set<std::string>::iterator		ret_b;

			std::cout << "a.upper_bound(\"c\")\t return: ";
			ret_a = a.upper_bound("c");
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound(\"c\")\t return: ";
			ret_b = b.upper_bound("c");
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.upper_bound(\"X\")\t return: ";
			ret_a = a.upper_bound("X");
			if (ret_a != a.end())
				std::cout << "iterator(" << *ret_a << ")\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound(\"X\")\t return: ";
			ret_b = b.upper_bound("X");
			if (ret_b != b.end())
				std::cout << "iterator(" << *ret_b << ")\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "swap(set_x, set_y)\n";

			ft::set<std::string>	a1(b);
			ft::set<std::string>	b1(b.begin(), b.find("k"));

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "swap(a, b)\n";
			swap(a1, b1);
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "set relational operators\n";

			ft::set<std::string>	a1(b);
			ft::set<std::string>	b1(b.begin(), b.find("k"));
			ft::set<std::string>	c(b);

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
