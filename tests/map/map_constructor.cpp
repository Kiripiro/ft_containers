#include "../../incs/Map/map.hpp"
#include "../test.hpp"
#include <map>
#include <iostream>
#include <list>

static void my_map()
{
	TESTED_NAMESPACE::map<char,int> first;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	TESTED_NAMESPACE::map<char,int> second(first.begin(),first.end());
	TESTED_NAMESPACE::map<char,int> third(first);
	TESTED_NAMESPACE::map<char,int> fourth = third;

	std::cout << "first:";
	for (TESTED_NAMESPACE::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	first.clear();
	std::cout << "*first.clear()*" << std::endl;
	std::cout << "second:";
	for (TESTED_NAMESPACE::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "third:";
	for (TESTED_NAMESPACE::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "fourth:";
	for (TESTED_NAMESPACE::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl;
}

void map_constructor()
{
	std::cout << "\x1B[92m------Map constructor and copy------\033[0m" << std::endl;
	my_map();
}
