#ifndef MAPPRINT_HPP
#define MAPPRINT_HPP

#include "../../../incs/Map/map.hpp"

struct Trunk
{
	Trunk *prev;
	std::string str;

	Trunk(Trunk *prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

#endif
