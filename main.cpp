#include "ft_vector.hpp"
#include <vector>

int main()
{
    // ft::vector<int>();
    ft::vector<int> a(15);
    a.push_back(20);
    std::cout << a[15];
    a.clear();
    std::cout << a[0] << std::endl;
    
    std::cout << "----------------------------------------------------------------" << std::endl;
    
    std::vector<int> b(15);
    b.push_back(20);
    std::cout << b[15];
    b.clear();
    std::cout << b[0];

    return (0);
}