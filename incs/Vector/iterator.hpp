#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../Utils/iterator_traits.hpp"
#include "../Utils/utils.hpp"
#include "vector.hpp"

namespace ft {
	template<typename Iterator>
	class VectorIterator
	{
		public:
			typedef	Iterator													iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
			typedef typename iterator_traits<iterator_type>::value_type         value_type;
			typedef typename iterator_traits<iterator_type>::pointer            pointer;
			typedef typename iterator_traits<iterator_type>::reference          reference;
			typedef	typename iterator_traits<iterator_type>::iterator_category	iterator_category;

			VectorIterator(): _i(NULL) {}
			VectorIterator(iterator_type _x): _i(_x) {}
			template <class Iter>
			VectorIterator(VectorIterator<Iter> const & src): _i(src.base()) {}
			~VectorIterator() {}

			VectorIterator	&operator=(const VectorIterator& rhs) {
				_i = rhs.base();
				return *this;
			}

			reference		operator*() const {
				return *_i;
			}

			pointer			operator->() const {
				return _i;
			}

			VectorIterator&	operator++() {
				_i++;
				return *this;
			}

			VectorIterator	operator++(int) {
				VectorIterator	_tmp(*this);
				++(*this);
				return _tmp;
			}

			VectorIterator&	operator--() {
				_i--;
				return *this;
			}

			VectorIterator	operator--(int) {
				VectorIterator	_tmp(*this);
				--(*this);
				return _tmp;
			}

			template <class T>
			friend VectorIterator<T> operator+(const int & lhs, const VectorIterator<T>& rhs);

			VectorIterator	operator+(difference_type _n) const {
				VectorIterator	_w(*this);
				_w += _n;
				return (_w);
			}

			VectorIterator	operator+=(difference_type _n) {
				_i += _n;
				return *this;
			}

			VectorIterator	operator-(difference_type _n) const {
				return *this + (-_n);
			}

			VectorIterator&	operator-=(difference_type _n) {
				*this += -_n;
				return *this;
			}

			reference	operator[](difference_type _n) const {
				return _i[_n];
			}

			iterator_type	base() const {
				return _i;
			}

		private:
			iterator_type	_i;
	};
			template <class _Iter1, class _Iter2>
			bool	operator==(const VectorIterator<_Iter1>& _x, const VectorIterator<_Iter2>& _y)
			{
				return _x.base() == _y.base();
			}

			template <class _Iter1, class _Iter2>
			bool	operator<(const VectorIterator<_Iter1>& _x, const VectorIterator<_Iter2>& _y)
			{
				return _x.base() < _y.base();
			}

			template <class _Iter1, class _Iter2>
			bool	operator!=(const VectorIterator<_Iter1>& _x, const VectorIterator<_Iter2>& _y)
			{
				return _x.base() != _y.base();
			}

			template <class _Iter1, class _Iter2>
			bool	operator>(const VectorIterator<_Iter1>& _x, const VectorIterator<_Iter2>& _y)
			{
				return _y.base() < _x.base();
			}

			template <class _Iter1, class _Iter2>
			bool	operator>=(const VectorIterator<_Iter1>& _x, const VectorIterator<_Iter2>& _y)
			{
				return !(_x.base() < _y.base());
			}

			template <class _Iter1, class _Iter2>
			bool	operator<=(const VectorIterator<_Iter1>& _x, const VectorIterator<_Iter2>& _y)
			{
				return !(_y.base() < _x.base());
			}

			template <class T>
			VectorIterator<T> operator+(const int & lhs, const VectorIterator<T> & rhs) {
				VectorIterator<T> ret(rhs);
				ret += lhs;
				return ret;
			}

			template <class _Iter1, class _Iter2>
			typename VectorIterator<_Iter1>::difference_type operator-(const VectorIterator<_Iter1>& _x, const VectorIterator<_Iter2>& _y)
			{
				return _x.base() - _y.base();
			}

}

#endif
