#include "../../../incs/Vector/vector.hpp"
#include <iostream>
#include <vector>

static void my_vec()
{
	std::vector<std::string> vec;
	vec.push_back("Hello ");
	vec.push_back("beautiful ");
	vec.push_back("World ");
	vec.push_back("so ");
	vec.push_back("amazing ");
	vec.push_back("!");
	std::cout << "\x1B[92m------Vector access------\033[0m" << std::endl;
	std::cout << "All vector: ";
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;

	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::cout << "front: " << vec.front() << std::endl;
	std::cout << "back: " << vec.back() << std::endl;
	std::cout << "vec[4]: " << vec[4] << std::endl;
	std::cout << "vec[8](Out Of Range): " << vec[8] << std::endl;
	std::cout << "vec.at(3): " << vec.at(3) << std::endl;
	try
	{
		std::cout << "vec.at(7)(Out Of Range): " << vec.at(7) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void vector_access()
{
	my_vec();
}
