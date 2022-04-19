#include "../../../incs/Vector/vector.hpp"
#include <iostream>
#include <vector>

static void my_vec()
{
	ft::vector<std::string> vec;
	vec.push_back("Hello ");
	vec.push_back("World ");
	vec.push_back("!");
	std::cout << "\x1B[92m------Vector capacity------\033[0m" << std::endl;

	std::cout << "max size: " << vec.max_size() << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::cout << "*vec.resize(10)*" << std::endl;
	vec.resize(10);
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::cout << "*vec.reserve(15)*" << std::endl;
	vec.reserve(15);
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

void vector_capacity()
{
	my_vec();
}
