#include "../../../incs/Vector/vector.hpp"
#include <iostream>
#include <vector>

static void my_vec()
{
	std::vector<std::string> first;
	std::vector<std::string> second;
	std::vector<int> third;
	int tab[] = {54, 89, 1};
	std::cout << "\x1B[92m------Vector assign------\033[0m" << std::endl;

	first.assign(7, "Bonjour");
	std::cout << "first.assign(7, \"Bonjour\"): ";
	for (std::vector<std::string>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it << ", ";
	std::cout << std::endl;
	second.assign(first.begin(), first.end() - 1);
	std::cout << "second.assign(first.begin(), first.end() - 1): ";
	for (std::vector<std::string>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << ", ";
	std::cout << std::endl;
	std::cout << "tab[] = {";
	for (size_t i = 0; i < 3; i++)
		std::cout << tab[i] << " ";
	std::cout << "}" << std::endl;
	third.assign(tab, tab + 3);
	std::cout << "third.assign(tab, tab + 3): ";
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void vector_assign()
{
	my_vec();
}
