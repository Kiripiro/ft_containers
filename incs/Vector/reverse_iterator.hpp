#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include "../Utils/iterator_traits.hpp"

namespace ft {
	template <class Iterator> class reverse_iterator
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type			difference_type;
			typedef typename iterator_traits<Iterator>::pointer					pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;

		private:
			Iterator	_t;
		protected:
			Iterator	current;

		public:
			reverse_iterator(): _t(), current() {}
			explicit reverse_iterator (iterator_type it): _t(it), current(it) {}
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it): _t(rev_it.base()), current(rev_it.base()) {}
			~reverse_iterator() {}

			template <class Iter>
			reverse_iterator&	operator=(const reverse_iterator<Iter>& rev_it) {
				_t = current = rev_it.base();
				return *this;
			}

			Iterator	base() const {
				return current;
			}

			reference	operator*() const {
				Iterator	_tmp = current;
				return *--_tmp;
			}

			pointer		operator->() const {
				return &operator*();
			}

			reverse_iterator&	operator++() {
				--current;
				return *this;
			}

			reverse_iterator	operator++(int) {
				reverse_iterator	_tmp(*this);
				--current;
				return _tmp;
			}

			reverse_iterator&	operator--() {
				++current;
				return *this;
			}

			reverse_iterator	operator--(int) {
				reverse_iterator	_tmp(*this);
				++current;
				return _tmp;
			}

			reverse_iterator	operator+(difference_type _n) const {
				return reverse_iterator(current - _n);
			}

			reverse_iterator&	operator+=(difference_type _n) {
				current -= _n;
				return *this;
			}

			reverse_iterator	operator-(difference_type _n) const {
				return reverse_iterator(current + _n);
			}

			reverse_iterator&	operator-=(difference_type _n) {
				current += _n;
				return *this;
			}

			reference	operator[](difference_type _n) const {
				return *(*this + _n);
			}

			template <class Iter>
			friend reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it);
	};

	template <class Iter1, class Iter2>
	bool	operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <class Iter1, class Iter2>
	bool	operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return lhs.base() != rhs.base();
	}

	template <class Iter1, class Iter2>
	bool	operator< (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return lhs.base() > rhs.base();
	}

	template <class Iter1, class Iter2>
	bool	operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return lhs.base() >= rhs.base();
	}

	template <class Iter1, class Iter2>
	bool	operator> (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <class Iter1, class Iter2>
	bool	operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return lhs.base() <= rhs.base();
	}

	template <class Iter>
	reverse_iterator<Iter> operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it) {
		return reverse_iterator<Iter>(rev_it.base() - n);
	}

	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type operator- (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return rhs.base() - lhs.base();
	}
}

#endif
