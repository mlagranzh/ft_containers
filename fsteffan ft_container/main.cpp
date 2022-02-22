#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <map>
#include <stack>
#include <vector>

#include <stdio.h>
#include <time.h>

void	vector_test()
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	std::cout << "Input 100\n";
	clock_t start = clock();
	for (int i = 0; i < 100; i++) {
		v1.push_back(i);
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector push_back %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 100; i++) {
		v2.push_back(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector push_back %f seconds\n", seconds);

	std::cout << "Input 1000\n";
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v1.push_back(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector push_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v2.push_back(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector push_back %f seconds\n", seconds);

	std::cout << "Input 10000\n";
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector push_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v2.push_back(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector push_back %f seconds\n", seconds);

	std::cout << "Input 10000000\n";
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v1.push_back(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector push_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v2.push_back(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector push_back %f seconds\n", seconds);

	std::cout << "\n\n";

	std::cout << "Delete 100\n";
	start = clock();
	for (int i = 0; i < 100; i++) {
		v1.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector pop_back %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 100; i++) {
		v2.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector pop_back %f seconds\n", seconds);

	std::cout << "Delete 1000\n";
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v1.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector pop_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v2.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector pop_back %f seconds\n", seconds);

	std::cout << "Delete 10000\n";
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v1.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector pop_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v2.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector pop_back %f seconds\n", seconds);

	std::cout << "Delete 10000000\n";
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v1.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Vector pop_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v2.pop_back();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Vector pop_back %f seconds\n", seconds);
}

void	stack_test(){
	std::stack<int>	v1;
	ft::stack<int>		v2;

	std::cout << "Input 100\n";
	clock_t start = clock();
	for (int i = 0; i < 100; i++) {
		v1.push(i);
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack push_back %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 100; i++) {
		v2.push(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack push_back %f seconds\n", seconds);

	std::cout << "Input 1000\n";
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v1.push(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack push_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v2.push(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack push_back %f seconds\n", seconds);

	std::cout << "Input 10000\n";
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v1.push(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack push_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v2.push(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack push_back %f seconds\n", seconds);

	std::cout << "Input 10000000\n";
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v1.push(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack push_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v2.push(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack push_back %f seconds\n", seconds);

	std::cout << "\n\n";

	std::cout << "Delete 100\n";
	start = clock();
	for (int i = 0; i < 100; i++) {
		v1.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack pop_back %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 100; i++) {
		v2.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack pop_back %f seconds\n", seconds);

	std::cout << "Delete 1000\n";
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v1.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack pop_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v2.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack pop_back %f seconds\n", seconds);

	std::cout << "Delete 10000\n";
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v1.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack pop_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v2.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack pop_back %f seconds\n", seconds);

	std::cout << "Delete 10000000\n";
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v1.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Stack pop_back %f seconds\n", seconds);
	
	start = clock();
	for (int i = 0; i < 10000000; i++) {
		v2.pop();
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Stack pop_back %f seconds\n", seconds);
}

void	map_test(){
	std::map<int, int>	v1;
	ft::map<int, int>	v2;

	std::cout << "\nInput 100\n";
	clock_t start = clock();
	for (int i = 0; i < 100; i++) {
		v1.insert(std::pair<int, int>(i, 100));
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Map insert %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 100; i++) {
		v2.insert(ft::pair<int, int>(i, 100));
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Map insert %f seconds\n", seconds);

	std::cout << "Delete 100\n";
	start = clock();
	for (int i = 0; i < 100; i++) {
		v1.insert(std::pair<int, int>(i, 100));
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Map erase %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 100; i++) {
		v2.insert(ft::pair<int, int>(i, 100));
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Map erase %f seconds\n", seconds);

	std::cout << "\nInput 1000\n";
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v1.insert(std::pair<int, int>(i, 100));
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Map insert %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 1000; i++) {
		v2.insert(ft::pair<int, int>(i, 100));
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Map insert %f seconds\n", seconds);

	std::cout << "Delete 1000\n";
	start = clock();
	for (int i = 0; i < 1000; i++) {
		v1.erase(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Map erase %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 1000; i++) {
		v2.erase(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Map erase %f seconds\n", seconds);

	std::cout << "\nInput 10000\n";
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v1.insert(std::pair<int, int>(i, 100));
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Map insert %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 10000; i++) {
		v2.insert(ft::pair<int, int>(i, 100));
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Map insert %f seconds\n", seconds);

	std::cout << "Delete 10000\n";
	start = clock();
	for (int i = 0; i < 10000; i++) {
		v1.erase(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("STD Map erase %f seconds\n", seconds);

	start = clock();
	for (int i = 0; i < 10000; i++) {
		v2.erase(i);
	}
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("FT Map erase %f seconds\n", seconds);
}

int main() {
	vector_test();
	std::cout << "\n\n";
	stack_test();
	std::cout << "\n\n";
	map_test();
}
