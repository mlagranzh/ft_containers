#include "vector.hpp"
#include <iostream>
#include <vector>



int main()
{
  ft::vector<int> first;

  first.assign (7,100);             // 7 ints with a value of 100
  std::cout << "Size of first: " << int (first[6]) << '\n';
  
}