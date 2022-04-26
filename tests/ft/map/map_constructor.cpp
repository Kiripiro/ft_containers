#include "../../../incs/Map/map.hpp"
#include <map>
#include <iostream>
#include <list>

void		test()
{
	std::list<ft::pair<int, int> > lst;
	int lst_size = 7;
	for (int i = 0; i < lst_size; ++i)
		lst.push_back(ft::pair<int, int>(lst_size - i, i));

	ft::map<int, int> mp(lst.begin(), lst.end());

	ft::map<int, int>::iterator begin = mp.begin(), end = mp.end();
	for (; begin != end; begin++)
	{
		std::cout << begin->first << std::endl;
	}

	ft::map<int, int>::iterator it = mp.begin(), ite = mp.end();
	ft::map<int, int> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	ft::map<int, int> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;
}

static void my_map()
{
	ft::map<char,int> first;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	ft::map<char,int> second(first.begin(),first.end());
	ft::map<char,int> third(first);
	ft::map<char,int> fourth = third;

	std::cout << "first:";
	for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	first.clear();
	std::cout << "*first.clear()*" << std::endl;
	std::cout << "second:";
	for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "third:";
	for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl << std::endl;
	std::cout << "fourth:";
	for (ft::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << " " << it->first;
	std::cout << std::endl;
	//test();
}

void map_constructor()
{
	std::cout << "\x1B[92m------Map constructor and copy------\033[0m" << std::endl;
	my_map();
}
