#include "../../incs/Vector/vector.hpp"
#include "../test.hpp"
#include <iostream>
#include <vector>

static void my_vec()
{
	ft::vector<int> i_vec;
	ft::vector<std::string> s_vec;
	ft::vector<int>::const_iterator cit;
	for (size_t i = 0; i < 8; i++)
		i_vec.push_back(i);
	s_vec.push_back("bonjour ");
	s_vec.push_back("tout ");
	s_vec.push_back("le ");
	s_vec.push_back("monde !");
	std::cout << "\x1B[92m------Vector iterator------\033[0m" << std::endl;

	std::cout << "iterator: ";
	for (ft::vector<int>::iterator it = i_vec.begin(); it != i_vec.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	std::cout << "const_iterator: ";
	for (ft::vector<std::string>::const_iterator it = s_vec.begin(); it != s_vec.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	std::cout << "reverse_iterator: ";
	for (ft::vector<int>::reverse_iterator it = i_vec.rbegin(); it != i_vec.rend(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	std::cout << "const_reverse_iterator: ";
	for (ft::vector<std::string>::const_reverse_iterator it = s_vec.rbegin(); it != s_vec.rend(); ++it)
		std::cout << *it;

	std::cout << std::endl;
}

void vector_iterator()
{
	my_vec();
}
