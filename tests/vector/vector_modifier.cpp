#include "../../incs/Vector/vector.hpp"
#include "../test.hpp"
#include <iostream>
#include <vector>

static void my_vec()
{
	ft::vector<int> myvector (3,100);
	ft::vector<std::string> foo(3, "Hello");
	ft::vector<std::string> bar(5, "World");
	ft::vector<int>::iterator it;
	std::cout << "\x1B[92m------Vector modifier------\033[0m" << std::endl;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	it = myvector.insert ( it , 300 );
	it = myvector.insert ( it , 400 );
	it = myvector.insert ( it , 1201 );

	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "push_back(42):";
	myvector.push_back(42);
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "pop_back():";
	myvector.pop_back();
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	it = myvector.begin();
	std::cout << "erase(it + 3):";
	myvector.erase(it + 3);
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	it = myvector.begin();
	std::cout << "erase(it + 3, it + 6):";
	myvector.erase(it + 3, it + 6);
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "foo contains:";
	for (ft::vector<std::string>::iterator itf = foo.begin(); itf != foo.end(); ++itf)
		std::cout << ' ' << *itf;
	std::cout << std::endl;

	std::cout << "bar contains:";
	for (ft::vector<std::string>::iterator itb = bar.begin(); itb != bar.end(); ++itb)
		std::cout << ' ' << *itb;
	std::cout << std::endl;

	std::cout << "*swap*" << std::endl;
	bar.swap(foo);
	std::cout << "foo contains:";
	for (ft::vector<std::string>::iterator itf = foo.begin(); itf != foo.end(); ++itf)
		std::cout << ' ' << *itf;
	std::cout << std::endl;

	std::cout << "bar contains:";
	for (ft::vector<std::string>::iterator itb = bar.begin(); itb != bar.end(); ++itb)
		std::cout << ' ' << *itb;
	std::cout << std::endl;

	std::cout << "clear myvector:";
	myvector.clear();
	for (ft::vector<int>::iterator itm = myvector.begin(); itm != myvector.end(); ++itm)
		std::cout << ' ' << *itm;
	std::cout << std::endl;
}

void vector_modifier()
{
	my_vec();
}
