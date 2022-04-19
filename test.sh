#!/bin/sh

if [ "$1" = "clear" ]; then
	rm -f includes.mk
	rm -f sources.mk
	rm -f tests_sources.mk
	rm -f ft_logs.txt
	rm -f std_logs.txt
	rm -f diff.txt
	make fclean_diff
	exit 1;
fi

if [ -n "$(find .objs -type f 2>/dev/null)" ]; then
	make fclean
fi
echo 'Run program using "leaks --atExit" ? Yes: "y", No: "n".'
read -n 1 -p "Input election: " leaks
echo '\n'
echo 'Use one of the following <arg>: \n\t-a: All containers\n\t-v: Vector\n\t-m: Map\n\t-s: Stack'
read -n 2 -p "Input selection: " arg
echo '\n'
echo 'Compare FT_containers VS STD_containers ? Yes: "y", No: "n".'
read -n 1 -p "Input selection: " diff
echo '\n'
if [ "$leaks" = "y" ] && [ "$diff" = "n" ]; then
	make gmk
	make
	leaks --atExit -- ./ft_containers $arg
elif [ "$leaks" = "y" ] && [ "$diff" = "y" ]; then
	make gmk_diff
	make diff
	leaks --atExit -- ./ft_containers $arg &> ft_logs.txt
	./std_containers $arg &> std_logs.txt
	diff -a ft_logs.txt std_logs.txt &> diff.txt
	echo 'File "diff.txt" has been created.'
elif [ "$leaks" = "n" ] && [ "$diff" = "n" ]; then
	make gmk
	make
	./ft_containers $arg
elif [ "$leaks" = "n" ] && [ "$diff" = "y" ]; then
	make gmk_diff
	make diff
	./ft_containers $arg &> ft_logs.txt
	./std_containers $arg &> std_logs.txt
	diff -a ft_logs.txt std_logs.txt &> diff.txt
	echo 'File "diff.txt" has been created.'
fi
