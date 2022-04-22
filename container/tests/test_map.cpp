/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:30:58 by pllucian          #+#    #+#             */
/*   Updated: 2022/02/20 04:19:51 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>
#include <string>

template<typename Container>
void	print(Container& x)
{
	for (typename Container::iterator it = x.begin(); it != x.end(); ++it)
		std::cout << (*it).second;
	std::cout << '\n';
}

int	main(void)
{
	std::cout << "--------------------MAP's TESTS---------------------------\n\n";
	{
		std::cout << "--------------------map<int, char> tests------------------\n";

		std::map<int, char>	a;
		ft::map<int, char>	b;
		char				letter = 'a';

		for (int i = 0; i < 26; ++i)
		{
			a.insert(std::make_pair(i, letter));
			b.insert(ft::make_pair(i, letter));
			++letter;
		}

		{
			std::cout << "map()\n";

			std::map<int, char>	a1;
			ft::map<int, char>	b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map(it, it)\n";

			std::map<int, char>	a1(a.begin(), a.end());
			ft::map<int, char>	b1(b.begin(), b.end());

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map(src_map)\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.operator=(src_map)\n";

			std::map<int, char>	a1 = a;
			ft::map<int, char>	b1 = b;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.at(key)\n";

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
			std::cout << "map[key]\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

			std::cout << "a[2] = " << a1[2] << '\n';
			std::cout << "b[2] = " << b1[2] << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a[33] = " << a1[33] << '\n';
			std::cout << "b[33] = " << b1[33] << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.begin()\n";

			std::cout << "(*a.begin()).second = " << (*a.begin()).second << '\n';
			std::cout << "(*b.begin()).second = " << (*b.begin()).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.end()\n";

			std::cout << "(*(--a.end())).second = " << (*(--a.end())).second << '\n';
			std::cout << "(*(--b.end())).second = " << (*(--b.end())).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.rbegin()\n";

			std::cout << "(*a.rbegin()).second = " << (*a.rbegin()).second << '\n';
			std::cout << "(*b.rbegin()).second = " << (*b.rbegin()).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.rend()\n";

			std::cout << "(*(--a.rend())).second = " << (*(--a.rend())).second << '\n';
			std::cout << "(*(--b.rend())).second = " << (*(--b.rend())).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.max_size()\n";

			std::cout << "a.max_size() = " << a.max_size() << '\n';
			std::cout << "b.max_size() = " << b.max_size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.clear()\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

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
			std::cout << "map.insert(value)\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

			std::pair<std::map<int, char>::iterator, bool>	ret_a;
			ft::pair<ft::map<int, char>::iterator, bool>	ret_b;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			ret_a = a1.insert(std::pair<int, char>(33, 'X'));
			ret_b = b1.insert(ft::pair<int, char>(33, 'X'));
			std::cout << "a.insert(std::pair<int, char>(33, 'X'))\t return: pair<pair<" \
				<< (*ret_a.first).first << ", " << (*ret_a.first).second << ">, " \
				<< ret_a.second << ">\n";
			std::cout << "b.insert(ft::pair<int, char>(33, 'X'))\t return: pair<pair<" \
				<< (*ret_b.first).first << ", " << (*ret_b.first).second << ">, " \
				<< ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert(std::pair<int, char>(30, 'Q'));
			ret_b = b1.insert(ft::pair<int, char>(30, 'Q'));
			std::cout << "a.insert(std::pair<int, char>(30, 'Q'))\t return: pair<pair<" \
				<< (*ret_a.first).first << ", " << (*ret_a.first).second << ">, " \
				<< ret_a.second << ">\n";
			std::cout << "b.insert(ft::pair<int, char>(30, 'Q'))\t return: pair<pair<" \
				<< (*ret_b.first).first << ", " << (*ret_b.first).second << ">, " \
				<< ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert(std::pair<int, char>(2, 'X'));
			ret_b = b1.insert(ft::pair<int, char>(2, 'X'));
			std::cout << "a.insert(std::pair<int, char>(2, 'X'))\t return: pair<pair<" \
				<< (*ret_a.first).first << ", " << (*ret_a.first).second << ">, " \
				<< ret_a.second << ">\n";
			std::cout << "b.insert(ft::pair<int, char>(2, 'X'))\t return: pair<pair<" \
				<< (*ret_b.first).first << ", " << (*ret_b.first).second << ">, " \
				<< ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.insert(it, value)\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

			std::map<int, char>::iterator	ret_a;
			ft::map<int, char>::iterator	ret_b;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			ret_a = a1.insert(a1.begin(), std::pair<int, char>(33, 'X'));
			ret_b = b1.insert(b1.begin(), ft::pair<int, char>(33, 'X'));
			std::cout << "a.insert(a.begin(), std::pair<int, char>(33, 'X'))\t return: iterator(pair<" \
				<< (*ret_a).first << ", " << (*ret_a).second << ">)\n";
			std::cout << "b.insert(b.begin(), ft::pair<int, char>(33, 'X'))\t return: iterator(pair<" \
				<< (*ret_b).first << ", " << (*ret_b).second << ">)\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert(a1.begin(), std::pair<int, char>(2, 'X'));
			ret_b = b1.insert(b1.begin(), ft::pair<int, char>(2, 'X'));
			std::cout << "a.insert(a.begin(), std::pair<int, char>(2, 'X'))\t return: iterator(pair<" \
				<< (*ret_a).first << ", " << (*ret_a).second << ">)\n";
			std::cout << "b.insert(b.begin(), ft::pair<int, char>(2, 'X'))\t return: iterator(pair<" \
				<< (*ret_b).first << ", " << (*ret_b).second << ">)\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.insert(it, it)\n";

			std::map<int, char>	a1;
			ft::map<int, char>	b1;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.insert(other.begin(), other.find(10))\n";
			std::cout << "b.insert(other.begin(), other.find(10))\n";
			a1.insert(a.begin(), a.find(10));
			b1.insert(b.begin(), b.find(10));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.erase(it)\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.find(2))\n";
			std::cout << "b.erase(b.find(2))\n";
			a1.erase(a1.find(2));
			b1.erase(b1.find(2));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.erase(key)\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(2)\t return: " << a1.erase(2) << '\n';
			std::cout << "b.erase(2)\t return: " << b1.erase(2) << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.erase(33)\t return: " << a1.erase(33) << '\n';
			std::cout << "b.erase(33)\t return: " << b1.erase(33) << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.erase(it, it)\n";

			std::map<int, char>	a1(a);
			ft::map<int, char>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.begin(), a.find(10))\n";
			std::cout << "b.erase(b.begin(), b.find(10))\n";
			a1.erase(a1.begin(), a1.find(10));
			b1.erase(b1.begin(), b1.find(10));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.swap(other)\n";

			ft::map<int, char>	a1(b);
			ft::map<int, char>	b1(b.begin(), b.find(10));

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
			std::cout << "map.count(key)\n";

			std::cout << "a.count(2)\t return: " << a.count(2) << '\n';
			std::cout << "b.count(2)\t return: " << b.count(2) << '\n';
			std::cout << "a.count(33)\t return: " << a.count(33) << '\n';
			std::cout << "b.count(33)\t return: " << b.count(33) << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.find(key)\n";

			std::map<int, char>::iterator	ret_a;
			ft::map<int, char>::iterator	ret_b;

			std::cout << "a.find(2)\t return: ";
			ret_a = a.find(2);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find(2)\t return: ";
			ret_b = b.find(2);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.find(33)\t return: ";
			ret_a = a.find(33);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find(33)\t return: ";
			ret_b = b.find(33);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.equal_range(key)\n";

			std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator>	ret_a;
			ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator>	ret_b;

			std::cout << "a.equal_range(2)\t return: ";
			ret_a = a.equal_range(2);
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(pair<" << (*ret_a.first).first << ", " \
				<< (*ret_a.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_a.second).first << ", " \
				<< (*ret_a.second).second << ">)>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range(2)\t return: ";
			ret_b = b.equal_range(2);
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(pair<" << (*ret_b.first).first << ", " \
				<< (*ret_b.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_b.second).first << ", " \
				<< (*ret_b.second).second << ">)>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			std::cout << "a.equal_range(33)\t return: ";
			ret_a = a.equal_range(33);
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(pair<" << (*ret_a.first).first << ", " \
				<< (*ret_a.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_a.second).first << ", " \
				<< (*ret_a.second).second << ">)>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range(33)\t return: ";
			ret_b = b.equal_range(33);
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(pair<" << (*ret_b.first).first << ", " \
				<< (*ret_b.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_b.second).first << ", " \
				<< (*ret_b.second).second << ">)>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.lower_bound(key)\n";

			std::map<int, char>::iterator	ret_a;
			ft::map<int, char>::iterator	ret_b;

			std::cout << "a.lower_bound(2)\t return: ";
			ret_a = a.lower_bound(2);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound(2)\t return: ";
			ret_b = b.lower_bound(2);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.lower_bound(33)\t return: ";
			ret_a = a.lower_bound(33);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound(33)\t return: ";
			ret_b = b.lower_bound(33);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.upper_bound(key)\n";

			std::map<int, char>::iterator	ret_a;
			ft::map<int, char>::iterator	ret_b;

			std::cout << "a.upper_bound(2)\t return: ";
			ret_a = a.upper_bound(2);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound(2)\t return: ";
			ret_b = b.upper_bound(2);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.upper_bound(33)\t return: ";
			ret_a = a.upper_bound(33);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound(33)\t return: ";
			ret_b = b.upper_bound(33);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "swap(map_x, map_y)\n";

			ft::map<int, char>	a1(b);
			ft::map<int, char>	b1(b.begin(), b.find(10));

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
			std::cout << "map relational operators\n";

			ft::map<int, char>	a1(b);
			ft::map<int, char>	b1(b.begin(), b.find(10));
			ft::map<int, char>	c(b);

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
		std::cout << "--------------------map<int, std::string> tests-----------------------\n";

		std::map<int, std::string>	a;
		ft::map<int, std::string>	b;
		std::string			letter = "a";

		for (int i = 0; i < 26; ++i)
		{
			a.insert(std::make_pair(i, letter));
			b.insert(ft::make_pair(i, letter));
			++letter[0];
		}

		{
			std::cout << "map()\n";

			std::map<int, std::string>	a1;
			ft::map<int, std::string>	b1;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map(it, it)\n";

			std::map<int, std::string>	a1(a.begin(), a.end());
			ft::map<int, std::string>	b1(b.begin(), b.end());

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map(src_map)\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.operator=(src_map)\n";

			std::map<int, std::string>	a1 = a;
			ft::map<int, std::string>	b1 = b;

			std::cout << "a.size = " << a1.size() << '\n';
			std::cout << "b.size = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.at(key)\n";

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
			std::cout << "map[key]\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

			std::cout << "a[2] = " << a1[2] << '\n';
			std::cout << "b[2] = " << b1[2] << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a[33] = " << a1[33] << '\n';
			std::cout << "b[33] = " << b1[33] << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.begin()\n";

			std::cout << "(*a.begin()).second = " << (*a.begin()).second << '\n';
			std::cout << "(*b.begin()).second = " << (*b.begin()).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.end()\n";

			std::cout << "(*(--a.end())).second = " << (*(--a.end())).second << '\n';
			std::cout << "(*(--b.end())).second = " << (*(--b.end())).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.rbegin()\n";

			std::cout << "(*a.rbegin()).second = " << (*a.rbegin()).second << '\n';
			std::cout << "(*b.rbegin()).second = " << (*b.rbegin()).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.rend()\n";

			std::cout << "(*(--a.rend())).second = " << (*(--a.rend())).second << '\n';
			std::cout << "(*(--b.rend())).second = " << (*(--b.rend())).second << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.empty()\n";

			std::cout << "a.empty() = " << a.empty() << '\n';
			std::cout << "b.empty() = " << b.empty() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.size()\n";

			std::cout << "a.size() = " << a.size() << '\n';
			std::cout << "b.size() = " << b.size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.max_size()\n";

			std::cout << "a.max_size() = " << a.max_size() << '\n';
			std::cout << "b.max_size() = " << b.max_size() << '\n';
			std::cout << '\n';
		}

		{
			std::cout << "map.clear()\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

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
			std::cout << "map.insert(value)\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

			std::pair<std::map<int, std::string>::iterator, bool>	ret_a;
			ft::pair<ft::map<int, std::string>::iterator, bool>	ret_b;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			ret_a = a1.insert(std::pair<int, std::string>(33, "X"));
			ret_b = b1.insert(ft::pair<int, std::string>(33, "X"));
			std::cout << "a.insert(std::pair<int, std::string>(33, \"X\"))\t return: pair<pair<" \
				<< (*ret_a.first).first << ", " << (*ret_a.first).second << ">, " \
				<< ret_a.second << ">\n";
			std::cout << "b.insert(ft::pair<int, std::string>(33, \"X\"))\t return: pair<pair<" \
				<< (*ret_b.first).first << ", " << (*ret_b.first).second << ">, " \
				<< ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert(std::pair<int, std::string>(30, "Q"));
			ret_b = b1.insert(ft::pair<int, std::string>(30, "Q"));
			std::cout << "a.insert(std::pair<int, std::string>(30, \"Q\"))\t return: pair<pair<" \
				<< (*ret_a.first).first << ", " << (*ret_a.first).second << ">, " \
				<< ret_a.second << ">\n";
			std::cout << "b.insert(ft::pair<int, std::string>(30, \"Q\"))\t return: pair<pair<" \
				<< (*ret_b.first).first << ", " << (*ret_b.first).second << ">, " \
				<< ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert(std::pair<int, std::string>(2, "X"));
			ret_b = b1.insert(ft::pair<int, std::string>(2, "X"));
			std::cout << "a.insert(std::pair<int, std::string>(2, \"X\"))\t return: pair<pair<" \
				<< (*ret_a.first).first << ", " << (*ret_a.first).second << ">, " \
				<< ret_a.second << ">\n";
			std::cout << "b.insert(ft::pair<int, std::string>(2, \"X\"))\t return: pair<pair<" \
				<< (*ret_b.first).first << ", " << (*ret_b.first).second << ">, " \
				<< ret_b.second << ">\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.insert(it, value)\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

			std::map<int, std::string>::iterator	ret_a;
			ft::map<int, std::string>::iterator	ret_b;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			ret_a = a1.insert(a1.begin(), std::pair<int, std::string>(33, "X"));
			ret_b = b1.insert(b1.begin(), ft::pair<int, std::string>(33, "X"));
			std::cout << "a.insert(a.begin(), std::pair<int, std::string>(33, \"X\"))\t return: iterator(pair<" \
				<< (*ret_a).first << ", " << (*ret_a).second << ">)\n";
			std::cout << "b.insert(b.begin(), ft::pair<int, std::string>(33, \"X\"))\t return: iterator(pair<" \
				<< (*ret_b).first << ", " << (*ret_b).second << ">)\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			ret_a = a1.insert(a1.begin(), std::pair<int, std::string>(2, "X"));
			ret_b = b1.insert(b1.begin(), ft::pair<int, std::string>(2, "X"));
			std::cout << "a.insert(a.begin(), std::pair<int, std::string>(2, \"X\"))\t return: iterator(pair<" \
				<< (*ret_a).first << ", " << (*ret_a).second << ">)\n";
			std::cout << "b.insert(b.begin(), ft::pair<int, std::string>(2, \"X\"))\t return: iterator(pair<" \
				<< (*ret_b).first << ", " << (*ret_b).second << ">)\n";
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.insert(it, it)\n";

			std::map<int, std::string>	a1;
			ft::map<int, std::string>	b1;

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.insert(other.begin(), other.find(10))\n";
			std::cout << "b.insert(other.begin(), other.find(10))\n";
			a1.insert(a.begin(), a.find(10));
			b1.insert(b.begin(), b.find(10));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.erase(it)\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.find(2))\n";
			std::cout << "b.erase(b.find(2))\n";
			a1.erase(a1.find(2));
			b1.erase(b1.find(2));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.erase(key)\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(2)\t return: " << a1.erase(2) << '\n';
			std::cout << "b.erase(2)\t return: " << b1.erase(2) << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << "a.erase(33)\t return: " << a1.erase(33) << '\n';
			std::cout << "b.erase(33)\t return: " << b1.erase(33) << '\n';
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.erase(it, it)\n";

			std::map<int, std::string>	a1(a);
			ft::map<int, std::string>	b1(b);

			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			std::cout << "a.erase(a.begin(), a.find(10))\n";
			std::cout << "b.erase(b.begin(), b.find(10))\n";
			a1.erase(a1.begin(), a1.find(10));
			b1.erase(b1.begin(), b1.find(10));
			std::cout << "a.size() = " << a1.size() << '\n';
			std::cout << "b.size() = " << b1.size() << '\n';
			print(a1);
			print(b1);
			std::cout << '\n';
		}

		{
			std::cout << "map.swap(other)\n";

			ft::map<int, std::string>	a1(b);
			ft::map<int, std::string>	b1(b.begin(), b.find(10));

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
			std::cout << "map.count(key)\n";

			std::cout << "a.count(2)\t return: " << a.count(2) << '\n';
			std::cout << "b.count(2)\t return: " << b.count(2) << '\n';
			std::cout << "a.count(33)\t return: " << a.count(33) << '\n';
			std::cout << "b.count(33)\t return: " << b.count(33) << '\n';
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.find(key)\n";

			std::map<int, std::string>::iterator	ret_a;
			ft::map<int, std::string>::iterator		ret_b;

			std::cout << "a.find(2)\t return: ";
			ret_a = a.find(2);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find(2)\t return: ";
			ret_b = b.find(2);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.find(33)\t return: ";
			ret_a = a.find(33);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.find(33)\t return: ";
			ret_b = b.find(33);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.equal_range(key)\n";

			std::pair<std::map<int, std::string>::iterator, \
				std::map<int, std::string>::iterator>			ret_a;
			ft::pair<ft::map<int, std::string>::iterator, \
				ft::map<int, std::string>::iterator>			ret_b;

			std::cout << "a.equal_range(2)\t return: ";
			ret_a = a.equal_range(2);
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(pair<" << (*ret_a.first).first << ", " \
				<< (*ret_a.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_a.second).first << ", " \
				<< (*ret_a.second).second << ">)>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range(2)\t return: ";
			ret_b = b.equal_range(2);
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(pair<" << (*ret_b.first).first << ", " \
				<< (*ret_b.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_b.second).first << ", " \
				<< (*ret_b.second).second << ">)>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			std::cout << "a.equal_range(33)\t return: ";
			ret_a = a.equal_range(33);
			if (ret_a.first != a.end())
				std::cout << "pair<iterator(pair<" << (*ret_a.first).first << ", " \
				<< (*ret_a.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_a.second).first << ", " \
				<< (*ret_a.second).second << ">)>\n";
			else
				std::cout << "pair<a.end(), a.end()>\n";
			std::cout << "b.equal_range(33)\t return: ";
			ret_b = b.equal_range(33);
			if (ret_b.first != b.end())
				std::cout << "pair<iterator(pair<" << (*ret_b.first).first << ", " \
				<< (*ret_b.first).second << ">)" \
				<< ", iterator(pair<" << (*ret_b.second).first << ", " \
				<< (*ret_b.second).second << ">)>\n";
			else
				std::cout << "pair<b.end(), b.end()>\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.lower_bound(key)\n";

			std::map<int, std::string>::iterator	ret_a;
			ft::map<int, std::string>::iterator		ret_b;

			std::cout << "a.lower_bound(2)\t return: ";
			ret_a = a.lower_bound(2);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound(2)\t return: ";
			ret_b = b.lower_bound(2);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.lower_bound(33)\t return: ";
			ret_a = a.lower_bound(33);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.lower_bound(33)\t return: ";
			ret_b = b.lower_bound(33);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "map.upper_bound(key)\n";

			std::map<int, std::string>::iterator	ret_a;
			ft::map<int, std::string>::iterator	ret_b;

			std::cout << "a.upper_bound(2)\t return: ";
			ret_a = a.upper_bound(2);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound(2)\t return: ";
			ret_b = b.upper_bound(2);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			std::cout << "a.upper_bound(33)\t return: ";
			ret_a = a.upper_bound(33);
			if (ret_a != a.end())
				std::cout << "iterator(pair<" << (*ret_a).first << ", " \
				<< (*ret_a).second << ">)\n";
			else
				std::cout << "a.end()\n";
			std::cout << "b.upper_bound(33)\t return: ";
			ret_b = b.upper_bound(33);
			if (ret_b != b.end())
				std::cout << "iterator(pair<" << (*ret_b).first << ", " \
				<< (*ret_b).second << ">)\n";
			else
				std::cout << "b.end()\n";
			print(a);
			print(b);
			std::cout << '\n';
		}

		{
			std::cout << "swap(map_x, map_y)\n";

			ft::map<int, std::string>	a1(b);
			ft::map<int, std::string>	b1(b.begin(), b.find(10));

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
			std::cout << "map relational operators\n";

			ft::map<int, std::string>	a1(b);
			ft::map<int, std::string>	b1(b.begin(), b.find(10));
			ft::map<int, std::string>	c(b);

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
