#include "../../../incs/Vector/vector.hpp"
#include <iostream>
#include <vector>

static void my_vec()
{
	std::vector<std::string> foo;
	foo.push_back("Hello");
	foo.push_back("World");
	foo.push_back("!");
	std::vector<std::string> bar;
	bar.push_back("Bonjour");
	bar.push_back("Monde");
	bar.push_back("!");
	bool ret;
	std::cout << "\x1B[92m------Vector operators------\033[0m" << std::endl;

	std::cout << "foo contains:";
	for (std::vector<std::string>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "bar contains:";
	for (std::vector<std::string>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ret = foo > bar;
	std::cout << "foo > bar: " << ret << std::endl;
	ret = foo < bar;
	std::cout << "foo < bar: " << ret << std::endl;
	ret = foo != bar;
	std::cout << "foo != bar: " << ret << std::endl;

	std::cout << "*swap*" << std::endl;
	std::swap(foo, bar);
	std::cout << "foo contains:";
	for (std::vector<std::string>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "bar contains:";
	for (std::vector<std::string>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void vector_operators()
{
	my_vec();
}
