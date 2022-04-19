#include "../../../incs/Map/map.hpp"
#include <map>
#include <iostream>

static void my_map()
{
	std::map<std::string, char> map;
	std::map<std::string, char> second;

	map["hello"] = 'h';
	map["world"] = 'w';
	map["!"] = '!';
	std::cout << "map:";
	for (std::map<std::string, char>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl;
	std::cout << "map capacity: " << map.size() << std::endl;
	second.insert(map.begin(), map.end());
	std::cout << "second capacity: " << map.size() << std::endl;
	std::cout << "map empty: " << map.empty() << std::endl;
	std::cout << "*second.clear()*" << std::endl;
	second.clear();
	std::cout << "second empty: " << second.empty() << std::endl;
}

void map_capacity()
{
	std::cout << "\x1B[92m------Map capacity------\033[0m" << std::endl;
	my_map();
}
