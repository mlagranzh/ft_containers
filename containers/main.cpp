#include "vector.hpp"
#include <iostream>
#include <vector>
#include <map>
#include "map.hpp"
#include <iostream>
#include <map>

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
  return 0;
}