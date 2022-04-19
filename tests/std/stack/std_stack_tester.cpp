#include "../../../incs/Stack/stack.hpp"
#include <iostream>
#include <stack>

static void my_stack()
{
	std::stack<int> stack;

	std::cout << "\x1B[92m------Stack Tester------\033[0m" << std::endl;

	std::cout << "stack empty: " << stack.empty() << std::endl;
	std::cout << "*push*" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ' ' << i;
		stack.push(i);
	}
	std::cout << std::endl;
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "*pop*" << std::endl;
	stack.pop();
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << "empty: " << stack.empty() << std::endl;
}

void stack_tester()
{
	my_stack();
}
