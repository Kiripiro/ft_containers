#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <memory>
#include <iostream>
#include "RBT.hpp"

namespace ft
{
    template <class T, class U, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = U*, class Reference = U&>
	class MapIterator
	{
	public:
    	typedef T         		value_type;
    	typedef Distance  		difference_type;
    	typedef Pointer   		pointer;
    	typedef Reference 		reference;
    	typedef Category  		iterator_category;
	protected:
		T *_ptr;
	public:
		MapIterator(void): _ptr(NULL) {}

		MapIterator(const MapIterator &other)
		{
			*this = other;
		}

		MapIterator(T *ptr): _ptr(ptr) {}

		~MapIterator(void) {}

		T *get_internal_pointer(void) const
		{
			return _ptr;
		}

		MapIterator &operator= (const MapIterator &other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}

		MapIterator &operator++(void)
		{
			_ptr = _ptr->next();
			return *this;
		}

		MapIterator &operator--(void)
		{
			_ptr = _ptr->prev();
			return *this;
		}

		MapIterator operator++(int)
		{
			MapIterator tmp = *this;
			_ptr = _ptr->next();
			return tmp;
		}

		MapIterator operator--(int)
		{
			MapIterator tmp = *this;
			_ptr = _ptr->prev();
			return tmp;
		}

		bool operator==(const MapIterator &other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const MapIterator &other) const
		{
			return _ptr != other._ptr;
		}

		reference operator* (void) const
		{
			return _ptr->value;
		}

		pointer operator->(void) const
		{
			return &_ptr->value;
		}
	};

	template <class T, class U, class MapIterator, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = U*, class Reference = U&>
	class ConstMapIterator
	{
	public:
    	typedef T         		value_type;
    	typedef Distance  		difference_type;
    	typedef Pointer   		pointer;
    	typedef Reference 		reference;
    	typedef Category  		iterator_category;
	protected:
		T *_ptr;
	public:
		ConstMapIterator(void): _ptr(NULL) {}

		ConstMapIterator(const ConstMapIterator &other)
		{
			*this = other;
		}

		ConstMapIterator(T* ptr): _ptr(ptr) {}

		ConstMapIterator(const MapIterator &other)
		{
			_ptr = other.get_internal_pointer();
		}

		~ConstMapIterator(void) {}

		T *get_internal_pointer(void) const
		{
			return _ptr;
		}

		ConstMapIterator &operator= (const ConstMapIterator &other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}

		ConstMapIterator &operator++(void)
		{
			_ptr = _ptr->next();
			return *this;
		}

		ConstMapIterator &operator--(void)
		{
			_ptr = _ptr->prev();
			return *this;
		}

		ConstMapIterator operator++(int)
		{
			ConstMapIterator tmp = *this;
			_ptr = _ptr->next();
			return tmp;
		}

		ConstMapIterator operator--(int)
		{
			ConstMapIterator tmp = *this;
			_ptr = _ptr->prev();
			return tmp;
		}

		bool operator==(const ConstMapIterator &other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const ConstMapIterator &other) const
		{
			return _ptr != other._ptr;
		}

		const reference operator* (void) const
		{
			return _ptr->value;
		}

		const pointer operator->(void) const
		{
			return &_ptr->value;
		}
	};
}

#endif
