// #include "ft_vector.hpp"
#include <vector>
#include <map>
#include "fsteffan/map.hpp"
#include <iostream>

template<typename Map>
void print_map(Map& m)
{
   std::cout << '{';
   for(auto& p: m)
        std::cout << p.first << ':' << p.second << ' ';
   std::cout << "}\n";
}


// void test_vector()
// {
//     {
//         ft::vector<int> a(15);
//         a.push_back(20);
//         std::cout << a[15];
//         ft::vector <int>::iterator it = a.begin();
//         a.insert (it,200); ///И первым элементом записывается 200
//         a.clear();
//         std::cout << a[0] << std::endl;
//     }

//     std::cout << "----------------------------------------------------------------" << std::endl;
    
//     {
//         std::vector<int> a(15);
//         a.push_back(20);
//         std::cout << a[15];
//         std::vector <int>::iterator it = a.begin();
//         a.insert (it,200); ///И первым элементом записывается 200
//         a.clear();
//         std::cout << a[0] << std::endl;
//     }

// }

void test_map()
{
    {
        std::map<std::string, int> map1;
        map1["something"] = 69;
        map1["anything"] = 199;
        map1["that thing"] = 50;
        std::cout << "map1 = "; print_map(map1);
    }

    {
        ft::map<std::string, int> map1;
        map1["something"] = 69;
        map1["anything"] = 199;
        map1["that thing"] = 50;
        std::cout << "map1 = "; print_map(map1);
    }

}

int main()
{
    test_map();
    return (0);
}