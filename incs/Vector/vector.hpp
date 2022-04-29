#ifndef VECTOR_HPP
#define VECTOR_HPP


#include "../Utils/utils.hpp"
#include "../Utils/iterator_traits.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <memory>
#include <stdexcept>
#include <iostream>

namespace ft {
	template < class T, class Allocator = std::allocator<T> > class vector
	{
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef VectorIterator<pointer>						iterator;
		typedef VectorIterator<const_pointer>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		size_type _size;
		size_type _capacity;
		pointer _i;
		allocator_type _alloc;

	public:
		explicit vector( const Allocator & alloc = allocator_type()): _size(0), _capacity(0), _i(NULL), _alloc(alloc) {}

		explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()): _size(0), _capacity(n), _alloc(alloc) {
			_i = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _capacity; i++, _size++)
				_alloc.construct(_i + _size, val);
		}

		template <class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()): _size(0), _capacity(ft::distance(first, last)), _alloc(alloc) {
			_i = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _capacity; i++, _size++)
				_alloc.construct(_i + _size, *(first++));
		}

		explicit vector (const ft::vector<value_type> & x): _size(0), _capacity(x._capacity), _alloc(x._alloc) {
			_i = _alloc.allocate(_capacity);
			for (size_type i = 0; i < x._size; i++, _size++)
				_alloc.construct(_i + _size, *(x._i + _size));
		}

		virtual ~vector () {
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_i + i);
			_alloc.deallocate(_i, _capacity);
		}

		vector & operator=(const vector & x) {
			clear();
			if (x.size() > capacity())
				reserve(x.size());
			for (size_type i = 0; i < x.size(); i++)
				push_back(x[i]);
			return *this;
		}
//ITERATORS
		iterator begin() {
			return _i;
		}

		const_iterator begin() const {
			return _i;
		}

		iterator end() {
			return _i + size();
		}

		const_iterator end() const {
			return _i + size();
		}

		reverse_iterator rbegin() {
			return reverse_iterator(_i + _size);
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(_i + _size);
		}

		reverse_iterator	rend() {
			return reverse_iterator(_i);
		}

		const_reverse_iterator	rend() const {
			return reverse_iterator(_i);
		}

//CAPACITY
		size_t size() const {
			return _size;
		}

		size_type max_size() const {
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		}

		void resize( size_type n, T value = value_type() ) {
			if (n < _size)
			{
				for (size_type i = n; i < _size; ++i)
					_alloc.destroy(_i + i);
			}
			else if (n > size())
			{
				if (n > capacity())
				{
					if (capacity() * 2 < n)
						reserve(n);
					else
						reserve(capacity() * 2);
				}
				for (size_type i = _size; i < n; ++i)
					_alloc.construct(_i + i, value);
			}
			_size = n;
		}

		size_type capacity() const {
			return _capacity;
		}

		bool empty() const {
			return _size == 0 ? true : false ;
		}

		void reserve( size_type n ) {
			if (n > max_size())
				throw std::length_error::exception();
			if (n > _capacity) {
				pointer tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(tmp + i, *(_i + i));
					_alloc.destroy(_i + i);
				}
				_alloc.deallocate(_i, _capacity);
				_capacity = n;
				_i = tmp;
			}
		}

//ELEMENTS ACCESS
		reference operator[] (size_type n) {
			return _i[n];
		}

		const_reference operator[] (size_type n) const {
			return _i[n];
		}

		reference at( size_type pos ) {
			if (pos >= size())
				throw std::out_of_range("vector");
			return _i[pos];
		}

		const_reference at( size_type pos ) const {
			if (pos >= size())
				throw std::out_of_range("vector");
			return _i[pos];
		}

		reference front() {
			return *_i;
		}

		const_reference front() const {
			return *_i;
		}

		reference back() {
			return _i[size() - 1];
		}

		const_reference back() const {
			return _i[size() - 1];
		}

//MODIFIERS
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) {
			size_type size = ft::distance(first, last);
			if (size > capacity()) {
				pointer tmp = _alloc.allocate(size);
				for (size_type i = 0; i < size; i++, first++) {
					_alloc.construct(tmp + i, *first);
					if (capacity())
						_alloc.destroy(_i + i);
				}
				if (capacity())
					_alloc.deallocate(_i, _capacity);
				_i = tmp;
				_capacity = size;
				_size = size;
			}
			else {
				for (size_type i = 0; i < size; i++, first++) {
					_alloc.destroy(_i + i);
					_alloc.construct(_i + i, *first);
				}
				_size = size;
			}
		}

		void assign(size_type n, const T& val) {
			if (n > capacity()) {
				pointer tmp = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(tmp + i, val);
					if (capacity())
						_alloc.destroy(_i + i);
				}
				if (capacity())
					_alloc.deallocate(_i, _capacity);
				_i = tmp;
				_capacity = n;
				_size = n;
			}
			else {
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(_i + i, val);
					_alloc.destroy(_i + i);
				}
				_size = n;
			}
		}

		void push_back(const value_type& val) {
			if (_size + 1 > capacity()) {
				if (!capacity())
						reserve(1);
					else
						reserve(capacity() * 2);
        	}
        	_alloc.construct(_i + _size, val);
        	_size++;
		}

		void pop_back() {
			if (!size())
				return ;
			_alloc.destroy(_i + _size);
			_size--;
		}

		iterator insert(iterator position, const value_type& val) {
			 size_type ret_i = 0;
			 if (_size + 1 > capacity()) {
				pointer tmp;
				int tmp_i = 0;
				int array_i = 0;
				if (capacity())
					tmp = _alloc.allocate(capacity() * 2);
				else
					tmp = _alloc.allocate(1);
				for (iterator it = begin(); it != position; it++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *it);
					_alloc.destroy(_i + array_i);
				}
				_alloc.construct(tmp + tmp_i++, val);
				ret_i = tmp_i - 1;
				for (iterator its = end(); position != its; position++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *position);
					_alloc.destroy(_i + array_i);
				}
				if (capacity()) {
					_alloc.deallocate(_i, capacity());
					_capacity = capacity() * 2;
				}
				else
					_capacity = 1;
				_size++;
				_i = tmp;
			 }
			 else {
				pointer tmp = _alloc.allocate(capacity());
				int tmp_i = 0;
				int array_i = 0;
				for (iterator it = begin(); it != position; it++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *it);
					_alloc.destroy(_i + array_i);
				}
				_alloc.construct(tmp + tmp_i++, val);
				ret_i = tmp_i - 1;
				for (iterator its = end(); position != its; position++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *position);
					_alloc.destroy(_i + array_i);
				}
				_alloc.deallocate(_i, capacity());
				_size++;
				_i = tmp;
			 }
			 return iterator(_i + ret_i);
		}

		void insert(iterator pos, size_type n, const value_type& val) {
			if (size() + n > capacity()) {
				size_type tmp_size;
				if (size() + n < capacity() || size() + n > capacity() * 2)
					tmp_size = size() + n;
				else
					tmp_size = capacity() * 2;
				pointer tmp = _alloc.allocate(tmp_size);
				size_type tmp_i = 0;
				size_type array_i = 0;
				for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *it);
					_alloc.destroy(_i + array_i);
				}
				for (size_type i = 0; i < n; i++) _alloc.construct(tmp + tmp_i++, val);
				for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *pos);
					_alloc.destroy(_i + array_i);
				}
				_alloc.deallocate(_i, capacity());
				_capacity = tmp_size;
				_size += n;
				_i = tmp;
			}
			else {
				pointer tmp = _alloc.allocate(capacity());
				size_type tmp_i = 0;
				size_type array_i = 0;
				for (iterator it = begin(); it != pos; it++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *it);
					_alloc.destroy(_i + array_i);
				}
				for (size_type i = 0; i < n; i++) _alloc.construct(tmp + tmp_i++, val);
				for (iterator its = end(); pos != its; pos++, tmp_i++, array_i++) {
					_alloc.construct(tmp + tmp_i, *pos);
					_alloc.destroy(_i + array_i);
				}
				if (capacity())
					_alloc.deallocate(_i, capacity());
				_size += n;
				_i = tmp;
			}
		}

		template <typename InputIt>
		void insert(iterator position, InputIt first, InputIt last, typename enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = InputIt()) {
			size_type index = position - begin();
			if (index <= _capacity)
			{
				value_type *tmp = _i;
				size_type	size_tmp = _size;
				size_type	capacity_tmp = _capacity;
				_i = _alloc.allocate(_capacity);

				for (size_type i = 0; i < index; i++)
				{
					_alloc.construct(&_i[i], tmp[i]);
					_alloc.destroy(&tmp[i]);
				}

				_size = index;

				for ( ; first != last; first++)
					push_back(*first);

				for (size_type i = index; i < size_tmp; i++)
				{
					push_back(tmp[i]);
					_alloc.destroy(&tmp[i]);
				}
				_alloc.deallocate(tmp, capacity_tmp);
			}
		}

		iterator erase(iterator position) {
			size_type index = ft::distance(begin(), position);
			for (size_type i = index; i != _size; ++i) {
				_alloc.destroy(_i + i);
				if (i + 1 != _size)
					_alloc.construct(_i + i, *(_i + i + 1));
			}
			_size--;
			return begin() + index;
		}

		iterator erase(iterator first, iterator last) {
			size_type posFirst = ft::distance(begin(), first);
			size_type posLast = ft::distance(begin(), last);
			size_type n = posLast - posFirst;
			for (size_type i = posFirst; i < posLast; ++i)
				_alloc.destroy(_i + i);
			for (size_type i = posLast; i < _size; ++i)
				_alloc.construct(_i + (i - n), *(_i + i));
			_size -= n;
			return first;
		}

		void swap(vector& y) {
			value_type *tmp_val = y._i;
			y._i = _i;
			_i = tmp_val;

			size_type tmp_size = y._size;
			y._size = _size;
			_size = tmp_size;

			size_type tmp_cap = y._capacity;
			y._capacity = _capacity;
			_capacity = tmp_cap;

			allocator_type tmp_alloc = y._alloc;
			y._alloc = _alloc;
			_alloc = tmp_alloc;
		}

		void clear() {
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_i + i);
			_size = 0;
		}

		allocator_type get_allocator() const {
			return _alloc;
		}
	};

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }

}

#endif
