#include "../../../incs/Map/map.hpp"
#include "../../../incs/Map/RBT.hpp"
#include "../../../incs/Map/pair.hpp"
#include <map>
#include <iostream>

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

void showTrunks(Trunk *p)
{
	if (p == nullptr) {
		return;
	}

	showTrunks(p->prev);
	std::cout << p->str;
}

void printTree(ft::map<int, int>::map_node* root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }
    std::string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
    printTree(root->right, trunk, true);
    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }
    showTrunks(trunk);
	if (root->color == RED)
    	std::cout << "\e[31m" << root->value.first << "\e[0m" << std::endl;
	else
    	std::cout << root->value.first << std::endl;
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
    printTree(root->left, trunk, false);
	delete trunk;
}

static void my_map_print()
{
	ft::map<int, int> mymap;

	/*std::srand(std::time(nullptr));
	for (size_t i = 0; i < 11; i++)
	{
		int v1 = rand() % 100;
		int v2 = rand() % 100;

		mymap.insert(ft::pair<int,int>(v1,v2));
		ft::map<int,int>::map_node	*begin = mymap.get_root();
			printTree(begin, nullptr, false);
		std::cout << std::endl;
	}*/
	mymap[8] = 8;
	ft::map<int,int>::map_node	*begin = mymap.get_root();
	printTree(begin, nullptr, false);
	std::cout << std::endl;

	mymap[50] = 50;
	ft::map<int,int>::map_node	*begin1 = mymap.get_root();
	printTree(begin1, nullptr, false);
	std::cout << std::endl;

	mymap[90] = 90;
	ft::map<int,int>::map_node	*begin2 = mymap.get_root();
	printTree(begin2, nullptr, false);
	std::cout << std::endl;

	mymap[71] = 71;
	ft::map<int,int>::map_node	*begin3 = mymap.get_root();
	printTree(begin3, nullptr, false);
	std::cout << std::endl;

	mymap[38] = 38;
	ft::map<int,int>::map_node	*begin4 = mymap.get_root();
	printTree(begin4, nullptr, false);
	std::cout << std::endl;

	mymap[88] = 88;
	ft::map<int,int>::map_node	*begin5 = mymap.get_root();
	printTree(begin5, nullptr, false);
	std::cout << std::endl;

	mymap[54] = 54;
	ft::map<int,int>::map_node	*begin6 = mymap.get_root();
	printTree(begin6, nullptr, false);
	std::cout << std::endl;

	mymap[17] = 17;
	ft::map<int,int>::map_node	*begin7 = mymap.get_root();
	printTree(begin7, nullptr, false);
	std::cout << std::endl;

	mymap[0] = 0;
	ft::map<int,int>::map_node	*begin8 = mymap.get_root();
	printTree(begin8, nullptr, false);
	std::cout << std::endl;

	mymap[12] = 12;
	ft::map<int,int>::map_node	*begin9 = mymap.get_root();
	printTree(begin9, nullptr, false);
	std::cout << std::endl;

	mymap.erase(88);
	ft::map<int,int>::map_node	*begin10 = mymap.get_root();
	printTree(begin10, nullptr, false);
	std::cout << std::endl;

}

void map_test()
{
	std::cout << "\x1B[92m------Map test------\033[0m" << std::endl;
	my_map_print();
}
