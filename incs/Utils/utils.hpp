#ifndef UTILS_HPP
#define	UTILS_HPP

#include "iterator_traits.hpp"

namespace ft {

	template <bool Cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { typedef T type; };

	template <bool B>
	struct bool_wrapper {
		static const bool value = B;
	};

	template < class T >
	struct is_integral : bool_wrapper<false> {};

	template <>
	struct is_integral<bool> : bool_wrapper<true> {};
	template <>
	struct is_integral<char> : bool_wrapper<true> {};
	template <>
	struct is_integral<wchar_t> : bool_wrapper<true> {};
	template <>
	struct is_integral<short> : bool_wrapper<true> {};
	template <>
	struct is_integral<int> : bool_wrapper<true> {};
	template <>
	struct is_integral<long> : bool_wrapper<true> {};
	template <>
	struct is_integral<long long> : bool_wrapper<true> {};

	template <class Iter>
	typename ft::iterator_traits<Iter>::difference_type	distance(Iter first, Iter last) {
		typename ft::iterator_traits<Iter>::difference_type ret = 0;
		while (first != last) {
			ret++;
			first++;
		}
		return ret;
	}

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1 )
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template < class InputIterator1, class InputIterator2, class Compare >
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) { // custom
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	template<class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

		template <class Arg1, class Arg2, class Result>
        struct binary_function
        {
            typedef Arg1 first_argument_type;

            typedef Arg2 second_argument_type;

            typedef Result result_type;
        };

	    template <class T>
        struct less : binary_function<T, T, bool>
        {
            bool operator() (const T& x, const T& y) const { return (x < y); }
        };
}


#endif
