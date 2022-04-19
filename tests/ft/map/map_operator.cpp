#include "../../../incs/Map/map.hpp"
#include <map>
#include <iostream>

static void my_map()
{
	ft::map<int, char> alice;
	ft::map<int, char> bob;
	ft::map<int, char> eve;

	alice[1] = 'a';
	alice[2] = 'b';
	alice[3] = 'c';

	bob[7] = 'Z';
	bob[8] = 'Y';
	bob[9] = 'X';
	bob[10] = 'W';

	eve[1] = 'a';
	eve[2] = 'b';
	eve[3] = 'c';

	std::cout << std::boolalpha;

	// Compare non equal containers
	std::cout << "alice == bob returns " << (alice == bob) << '\n';
	std::cout << "alice != bob returns " << (alice != bob) << '\n';
	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

	std::cout << '\n';

	// Compare equal containers
	std::cout << "alice == eve returns " << (alice == eve) << '\n';
	std::cout << "alice != eve returns " << (alice != eve) << '\n';
	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	std::cout << std::endl;
	ft::swap(alice, bob);
	std::cout << "*swap(alice, bob)*" << std::endl;
	std::cout << "alice contains: ";
	for (ft::map<int, char>::iterator it = alice.begin(); it != alice.end(); ++it)
		std::cout << "alice[" << it->first << "] = " << it->second << ", ";
	std::cout << std::endl;
	std::cout << "bob contains: ";
	for (ft::map<int, char>::iterator it = bob.begin(); it != bob.end(); ++it)
		std::cout << "bob[" << it->first << "] = " << it->second << ", ";
	std::cout << std::endl;
}

void map_operator()
{
	std::cout << "\x1B[92m------Map operator------\033[0m" << std::endl;
	my_map();
}
