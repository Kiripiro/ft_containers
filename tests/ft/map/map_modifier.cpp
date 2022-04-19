#include "../../../incs/Map/map.hpp"
#include <map>
#include <iostream>

static void my_map()
{
	ft::map<char,int> mymap;
	ft::map<char, int> foo;
	ft::map<char,int>::iterator it;

	// insert some values:
	foo['g'] = 70;
	foo['h'] = 80;
	foo['i'] = 90;
	foo['j'] = 100;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	std::cout << "mymap.erase(it): ";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << ", ";
	std::cout << std::endl;

	mymap.erase ('c');                  // erasing by key
	std::cout << "mymap.erase('c'): ";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << ", ";
	std::cout << std::endl;

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	std::cout << "mymap.erase(it, mymap.end()): ";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << ", ";
	std::cout << std::endl;
	std::cout << "*foo.swap(mymap)*" << std::endl;
	foo.swap(mymap);
	std::cout << "foo contains: " << std::endl;
	for (it=foo.begin(); it!=foo.end(); ++it)
	std::cout << it->first << " => " << it->second << ", ";
	std::cout << std::endl;
	std::cout << "mymap contains: ";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << ", ";
	std::cout << std::endl;
	std::cout << "*mymap.clear*" << std::endl;
	mymap.clear();
	std::cout << "mymap contains: ";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << ", ";
	std::cout << std::endl;
}

void map_modifier()
{
	std::cout << "\x1B[92m------Map modifier------\033[0m" << std::endl;
	my_map();
}
