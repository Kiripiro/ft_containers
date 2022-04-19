#include "test.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <stack>

int main(int ac, char ** av)
{
	std::string a;
	if (ac == 1) {
		std::cout << "Run program: ./ft_containers <arg>\nUse one of the following <arg>: \n\t-a: All containers\n\t-v: Vector\n\t-m: Map\n\t-s: Stack" << std::endl;
		std::getline(std::cin, a);
		av[1] = const_cast<char *>(a.c_str());
	}
	if (!strcmp(av[1], "-v")) {
		vector_constructor();
		std::cout << std::endl << std::endl;
		vector_iterator();
		std::cout << std::endl << std::endl;
		vector_capacity();
		std::cout << std::endl << std::endl;
		vector_access();
		std::cout << std::endl << std::endl;
		vector_assign();
		std::cout << std::endl << std::endl;
		vector_modifier();
		std::cout << std::endl << std::endl;
		vector_operators();
		std::cout << std::endl << std::endl;
	}
	else if (!strcmp(av[1], "-s")) {
		stack_tester();
		std::cout << std::endl << std::endl;
	}
	else if (!strcmp(av[1], "-m")) {
		map_constructor();
		std::cout << std::endl << std::endl;
		map_capacity();
		std::cout << std::endl << std::endl;
		map_insert();
		std::cout << std::endl << std::endl;
		map_modifier();
		std::cout << std::endl << std::endl;
		map_observers();
		std::cout << std::endl << std::endl;
		map_operations();
		std::cout << std::endl << std::endl;
		map_iterator();
		std::cout << std::endl << std::endl;
		map_operator();
	}
	else if (!strcmp(av[1], "-a")) {
		vector_constructor();
		std::cout << std::endl << std::endl;
		vector_iterator();
		std::cout << std::endl << std::endl;
		vector_capacity();
		std::cout << std::endl << std::endl;
		vector_access();
		std::cout << std::endl << std::endl;
		vector_assign();
		std::cout << std::endl << std::endl;
		vector_modifier();
		std::cout << std::endl << std::endl;
		vector_operators();
		std::cout << std::endl << std::endl;
		stack_tester();
		std::cout << std::endl << std::endl;
		map_constructor();
		std::cout << std::endl << std::endl;
		map_capacity();
		std::cout << std::endl << std::endl;
		map_insert();
		std::cout << std::endl << std::endl;
		map_modifier();
		std::cout << std::endl << std::endl;
		map_observers();
		std::cout << std::endl << std::endl;
		map_operations();
		std::cout << std::endl << std::endl;
		map_iterator();
		std::cout << std::endl << std::endl;
		map_operator();
		std::cout << std::endl << std::endl;
	}
	return 0;
}
