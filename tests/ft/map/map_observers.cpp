#include "../../../incs/Map/map.hpp"
#include <map>
#include <iostream>

static void my_map()
{
	ft::map<char,int> mymap;
	ft::map<char,int> foo;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "key_comp: mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	foo['x']=1001;
	foo['y']=2002;
	foo['z']=3003;

	std::cout << "value_comp: foo contains:\n";

	ft::pair<char,int> highest2 = *foo.rbegin();          // last element

	ft::map<char,int>::iterator yt = foo.begin();
	do {
		std::cout << yt->first << " => " << yt->second << '\n';
	} while (foo.value_comp()(*yt++, highest2) );
}

void map_observers()
{
	std::cout << "\x1B[92m------Map observers------\033[0m" << std::endl;
	my_map();
}
