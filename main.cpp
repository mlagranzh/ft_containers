/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <celys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:44:08 by celys             #+#    #+#             */
/*   Updated: 2022/05/02 20:26:53 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

#include <stdlib.h>

int main() 
{

  ft::map <int, int>  street;
  street.insert(ft::make_pair(1, 2));  
  street.insert(ft::make_pair(1, 2));  
  street.insert(ft::make_pair(5, 3));  
  std::cout << street.count(1) << std::endl;
  street.erase(1);
  std::cout << street.count(1) << std::endl;
  std::cout << street[5] << std::endl;

  for (ft::map <int, int>::iterator it = street.begin(); it != street.end(); it++ )
  {
    std::cout << it->first <<';' << it->second << std::endl;
  }

  std::cout << "|||||||||||||||||||||||||||" << std::endl;

  ft::vector<int> vec;
  vec.push_back(1);
  vec.push_back(13);
  vec.push_back(2);

  std::cout << vec[0] << std::endl;
  vec.erase(vec.begin());
  std::cout << vec[0] << std::endl;

  std::cout << "|||||||||||||||||||||||||||" << std::endl;

  ft::stack<int> st;
  st.push(1);
  st.push(13);
  st.push(2);

  std::cout << st.top() << std::endl;
  st.pop();
  std::cout << st.top() << std::endl;

  return (0);
}