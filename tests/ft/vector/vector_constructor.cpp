#include "../../../incs/Vector/vector.hpp"
#include <iostream>
#include <vector>

void vector_constructor()
{
	std::cout << "\x1B[92m------Vector constructor and copy------\033[0m" << std::endl;
    ft::vector<int> first;
	for (size_t i = 0; i < 8; i++)
		first.push_back(i);
    ft::vector<int> second(first.begin(), first.end() - 2);
    ft::vector<int> three(first);

    first.reserve(10); //Change capacity at 10
    first.pop_back(); // erase last value
    std::cout << "first: ";
    for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "second: ";
    for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "three: ";
    for (ft::vector<int>::iterator it = three.begin(); it != three.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "first.capacity: " << first.capacity() << std::endl;
    std::cout << "first.size: " << first.size() << std::endl;
    std::cout << "second.capacity: " << second.capacity() << std::endl;
    std::cout << "second.size: " << second.size() << std::endl;
    std::cout << "three.capacity: " << three.capacity() << std::endl;
    std::cout << "three.size: " << three.size() << std::endl;
}
