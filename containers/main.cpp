#include "vector.hpp"
#include <iostream>
#include <vector>
#include <map>
#include "map.hpp"


int main()
{
  ft::map<std::string, int> m;
  m["привет"] = 12;
  std::cout << m["привет"];
}
