#ifndef MAP_HPP
# define MAP_HPP

#include <map>

#include <iostream>
#include "../Utils/utils.hpp"
#include "RBT.hpp"
#include "map_reverse_iterator.hpp"

#define AFF(thing) (std::cout << thing << std::endl)

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		typedef Key 														key_type;
		typedef T 															mapped_type;
		typedef ft::pair<const key_type, mapped_type>						value_type;
		typedef Compare 													key_compare;
		typedef Alloc 														allocator_type;
		typedef typename allocator_type::reference 							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer 							pointer;
		typedef typename allocator_type::const_pointer 						const_pointer;
		typedef BSTNode<value_type>											map_node;
		typedef ft::MapIterator<map_node, value_type>						iterator;
		typedef ft::ConstMapIterator<map_node, const value_type, iterator>	const_iterator;
		typedef ft::map_reverse_iterator<iterator> 							reverse_iterator;
		typedef ft::map_reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef std::ptrdiff_t 												difference_type;
		typedef size_t 														size_type;
		typedef typename Alloc::template rebind<map_node>::other			node_allocator_type;

	private:
		key_compare			_compare;
		allocator_type		_alloc;
		node_allocator_type	_node_alloc;
		map_node			*_root;
		map_node			*_end;
		map_node			*_rend;
		size_type			_size;

	public:
		class value_compare
		{
			friend class map;

		protected:
			Compare _comp;

			value_compare(Compare c) : _comp(c) {}

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return _comp(x.first, y.first);
			}
		};

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _compare(comp), _alloc(alloc), _node_alloc(std::allocator<map_node>()), _root(NULL), _end(NULL), _rend(NULL), _size(0)
		{
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, map_node());

				_rend = _node_alloc.allocate(1);
				_node_alloc.construct(_rend, map_node());
				_rend->parent = _end;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			_compare = comp;
			_size = 0;
			_alloc = alloc;
			_node_alloc = std::allocator<map_node>();
			_root = NULL;

			_end = _node_alloc.allocate(1);
			_node_alloc.construct(_end, map_node());

			_rend = _node_alloc.allocate(1);
			_node_alloc.construct(_rend, map_node());
			_rend->parent = _end;
			this->insert(first, last);
		}

		map(const map &x): _root(NULL), _end(NULL), _rend(NULL), _size(0)
		{
			*this = x;
		}

		~map(void)
		{
			clear();
			_node_alloc.destroy(_end);
			_node_alloc.deallocate(_end, 1);
			_node_alloc.destroy(_rend);
			_node_alloc.deallocate(_rend, 1);
			_rend = NULL;
			_end = NULL;
		}

		map &operator= (const map &x)
		{
			if (this == &x)
				return *this;
			if (!empty())
				_destroy_from_root(_root);
			_init();
			_alloc = x._alloc;
			_node_alloc = x._node_alloc;
			_compare = x._compare;
			_size = x._size;
			insert(x.begin(), x.end());
			return *this;
		}

/*
 * Iterators
 */

		iterator begin(void)
		{
			return iterator(_rend->parent);
		}

		const_iterator begin(void) const
		{
			return const_iterator(_rend->parent);
		}

		iterator end(void)
		{
			return iterator(_end);
		}

		const_iterator end(void) const
		{
			return const_iterator(_end);
		}

		reverse_iterator rbegin(void)
		{
			return reverse_iterator(_end);
		}

		const_reverse_iterator rbegin(void) const
		{
			return const_reverse_iterator(_end);
		}

		reverse_iterator rend(void)
		{
			return reverse_iterator(_rend->parent);
		}

		const_reverse_iterator rend(void) const
		{
			return const_reverse_iterator(_rend->parent);
		}

/*
 * Capacity
 */

		bool empty(void) const
		{
			return (_size == 0);
		}

		size_type size(void) const
		{
			return _size;
		}

		size_type max_size(void) const
		{
			return std::numeric_limits<size_type>::max() / sizeof(map_node);
		}

/*
 * Element access
 */
		mapped_type &operator[](const key_type &k)
		{
			return (*(this->insert(value_type(k, mapped_type())).first)).second;
		}

		mapped_type &at(const key_type &key)
		{
				iterator it = this->find(key);
				if (it == this->end())
					throw std::out_of_range("out_of_range");
				return (*it).second;
		}

		const mapped_type &at(const key_type &key) const
		{
			const_iterator it = this->find(key);
			if (it == this->end())
				throw std::out_of_range("out_of_range");
			return (*it).second;
		}
/*
 * Modifiers
 */

		pair<iterator, bool>insert(const value_type &val)
		{
			iterator	it;
			map_node	*node;
			map_node	*new_node;

			if (!_root)
			{
				_root = _node_alloc.allocate(1);
				_node_alloc.construct(_root, map_node(val));

				_end->color = BLACK;
				_rend->color = BLACK;
				_root->color = BLACK;
				_root->left = _rend;
				_root->right = _end;
				_end->parent = _root;
				_rend->parent = _root;

				_size = 1;
				return ft::make_pair(iterator(_root), true);
			}
			it = this->find(val.first);
			if (it != this->end())
				return ft::make_pair(it, false);
			node = _root;
			while (node->right || node->left)
			{
				if (_compare(node->value.first, val.first))
				{
					if (node->right && node->right != _end)
						node = node->right;
					else
						break ;
				}
				else
				{
					if (node->left && node->left != _rend)
						node = node->left;
					else
						break ;
				}
			}
			new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, map_node(val));
			new_node->parent = node;
			if (_compare(node->value.first, val.first))
			{
				new_node->right = node->right;
				if (new_node->right)
					new_node->right->parent = new_node;
				new_node->left = NULL;
				node->right = new_node;
			}
			else
			{
				new_node->left = node->left;
				if (new_node->left)
					new_node->left->parent = new_node;
				new_node->right = NULL;
				node->left = new_node;
			}
			_size++;
			if (new_node->parent != _root)
				_insert_fix(new_node);
			return ft::make_pair(new_node, true);
		}

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return (this->insert(val)).first;
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				this->insert(*first);
				first++;
			}
		}

		void erase(iterator position)
		{
				map_node *z;
				z = position.get_internal_pointer();
				map_node *y = z;
				map_node *x;

				if (z == NULL)
					return ;
				int y_original_color = y->color;
				if (z->left == NULL)
				{
					x = z->right;
					_swap_nodes(z, z->right);
				}
				else if (z->right == NULL)
				{
					x = z->left;
					_swap_nodes(z, z->left);
				}
				else
				{
					y = _find_min(z->right);
					y_original_color = y->color;
					x = y->right;
					if (x != NULL && y->parent == z)
					{
						x->parent = y;
					}
					else if (z->right != NULL)
					{
						_swap_nodes(y, y->right);
						y->right = z->right;
						if (z->right != NULL)
							z->right->parent = y;
					}
					_swap_nodes(z, y);
					y->left = z->left;
					if (y->left != NULL)
						y->left->parent = y;
					y->color = z->color;
				}
				delete z;
				z = NULL;
				_size--;
				if (y == NULL && y->parent != _root)
				{
					y->parent->right = y->left;
					y->left->parent = y->parent;
					y->left = NULL;
					y->right = NULL;
				}
				if (y_original_color == BLACK && x != NULL)
					_erase_fix(x);
				return ;
		}

		size_type erase(const key_type &k)
		{
			iterator it;
			if ((it = this->find(k)) == this->end())
				return 0;
			erase(it);
			return 1;
		}

		void erase(iterator first, iterator last)
		{
			iterator	to_delete;

			if (first == last)
				return ;
			to_delete = first;
			erase(++first, last);
 	 		erase(to_delete);
		}

		void swap(map &x)
		{
			map_node	*tmp;
			size_type	size_tmp;

			if (x == *this)
				return ;

			tmp = x._root;
			x._root = _root;
			_root = tmp;

			tmp = x._end;
			x._end = _end;
			_end = tmp;

			tmp = x._rend;
			x._rend = _rend;
			_rend = tmp;

			size_tmp = x._size;
			x._size = _size;
			_size = size_tmp;
		}

		void clear(void)
		{
			this->erase(this->begin(), this->end());
		}

/*
 * Observers
 */

		key_compare key_comp(void) const
		{
			return key_compare();
		}

		value_compare value_comp(void) const
		{
			return value_compare(key_compare());
		}

/*
 * Operations
 */

		iterator find(const key_type &k)
		{
			map_node *node;

			node = _root;
			while (node && node != _end && node != _rend && (_compare(node->value.first, k) || _compare(k, node->value.first)))
			{
				if (_compare(node->value.first, k))
					node = node->right;
				else
					node = node->left;
			}
			if (node && node != _end && node != _rend && !_compare(node->value.first, k) && !_compare(k, node->value.first))
				return iterator(node);
			else
				return iterator(_end);
		}

		const_iterator find(const key_type &k) const
		{
			map_node *node;

			node = _root;
			while (node && node != _end && node != _rend && (_compare(node->value.first, k) || _compare(k, node->value.first)))
			{
				if (_compare(node->value.first, k))
					node = node->right;
				else
					node = node->left;
			}
			if (node && node != _end && node != _rend && !_compare(node->value.first, k) && !_compare(k, node->value.first))
				return const_iterator(node);
			else
				return const_iterator(_end);
		}

		size_type count(const key_type &k) const
		{
			if (this->find(k) == this->end())
				return 0;
			return 1;
		}

		iterator lower_bound(const key_type &k)
		{
			for (iterator i = begin(); i != end(); i++)
			{
				if (!_compare(i->first, k))
					return (i);
			}
			return (end());
		}

		const_iterator lower_bound(const key_type &k) const
		{
			for (const_iterator i = begin(); i != end(); i++)
			{
				if (!_compare(i->first, k))
					return (i);
			}
			return (end());
		}

		iterator upper_bound(const key_type &k)
		{
			for (iterator i = begin(); i != end(); i++)
			{
				if (_compare(k, i->first))
					return (i);
			}
			return (end());
		}

		const_iterator upper_bound(const key_type &k) const
		{
			for (const_iterator i = begin(); i != end(); i++)
			{
				if (_compare(k, i->first))
					return (i);
			}
			return (end());
		}

		pair<const_iterator,const_iterator>equal_range(const key_type &k) const
		{
			const_iterator lower = this->lower_bound(k);
			const_iterator upper = this->upper_bound(k);
			return ft::make_pair(lower, upper);
		}

		pair<iterator,iterator>equal_range(const key_type &k)
		{
			iterator lower = this->lower_bound(k);
			iterator upper = this->upper_bound(k);
			return ft::make_pair(lower, upper);
		}

/*
 * Allocator
 */

		allocator_type get_allocator(void) const
		{
			return _alloc;
		}

		map_node*	get_root(void)
		{
			return _root;
		}

		private:
			void _print_tree_structure(map_node *node, int spaces)
			{
				if (node != NULL)
				{
					_print_tree_structure(node->right, spaces + 5);
					for (int i = 0; i < spaces; i++)
						std::cout << ' ';
						if (node->color == RED)
							std::cout << "  \033[31m" << node->value.first << "\033[0m" << std::endl;
						else
							std::cout << "   " << node->value.first << std::endl;
					_print_tree_structure(node->left, spaces + 5);
				}
			}

			void	_init()
			{
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, map_node());

				_rend = _node_alloc.allocate(1);
				_node_alloc.construct(_rend, map_node());
				_rend->parent = _end;
				_root = NULL;
			}

			void	_delete_node(map_node* node)
			{
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				_size--;
				node = NULL;
			}

			void	_destroy_from_root(map_node* node)
			{
				if (empty())
				{
						_delete_node(_rend);
						_delete_node(_end);
				}
				else if (node == _end)
				{
					_delete_node(_end);
					return ;
				}
				else if (node != NULL)
				{
					if (node->left)
						_destroy_from_root(node->left);
					if (node->right)
						_destroy_from_root(node->right);
					_delete_node(node);
				}
			}

			map_node*	_create_node(const value_type &val)
			{
				map_node	*tmp = _node_alloc.allocate(1);

				_node_alloc.construct(tmp, map_node(val));
				return (tmp);
			}

			map_node *_find_min(map_node *n)
			{
				assert(n != NULL);
				map_node *tmp = n;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			}

			void _swap_nodes(map_node *u, map_node *v)
			{
				if (u->parent == NULL)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;

				if (u->parent == NULL)
					v->parent = NULL;
				else if (v != NULL)
					v->parent = u->parent;
			}

			void _rotate_left(map_node* x) {
				map_node* y = x->right;
				x->right = y->left;
				if (y->left != nullptr) {
					y->left->parent = x;
				}
				if (y != nullptr) {
					y->parent = x->parent;
				}
				if (x->parent != nullptr) {
					if (x == x->parent->left) {
						x->parent->left = y;
					} else {
						x->parent->right = y;
					}
				} else {
					_root = y;
				}
				y->left = x;
				if (x != nullptr) {
					x->parent = y;
				}
			}

			void _rotate_right(map_node* x) {
				map_node* y = x->left;
				x->left = y->right;
				if (y->right != nullptr) {
					y->right->parent = x;
				}
				if (y != nullptr) {
					y->parent = x->parent;
				}
				if (x->parent != nullptr) {
					if (x == x->parent->right) {
						x->parent->right = y;
					} else {
						x->parent->left = y;
					}
				} else {
					_root = y;
				}
				y->right = x;
				if (x != nullptr) {
					x->parent = y;
				}
			}

			void _insert_fix(map_node* node) {
				map_node* uncle;
				while (node->parent->color == RED) {
					if (node->parent == node->parent->parent->right)
					{
						uncle = node->parent->parent->left;
						if (uncle && uncle->color == RED)
						{
							uncle->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								_rotate_right(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							_rotate_left(node->parent->parent);
						}
					}
					else
					{
						uncle = node->parent->parent->right;
						if (uncle && uncle->color == 1)
						{
							uncle->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								_rotate_left(node);
							}
							node->parent->color = 0;
							node->parent->parent->color = RED;
							_rotate_right(node->parent->parent);
						}
					}
					if (node == _root)
						break;
				}
				_root->color = BLACK;
			}

			void _erase_fix(map_node *n)
			{
				map_node *tmp = n;
				map_node *w = n;
				map_node *p = tmp->parent;
				while (tmp != _root && tmp->color == BLACK && w != NULL)
				{
					if (tmp == p->left)
					{
						w = p->right;
						if (w != NULL && w->color == RED)
						{
							w->color = BLACK;
							p->color = RED;
							_rotate_left(p);
							w = p->right;
						}
						if (w != NULL)
						{
							if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK))
							{
								w->color = RED;
								tmp = p;
							}
							else
							{
								if (w->right->color == BLACK)
								{
									w->left->color = BLACK;
									w->color = RED;
									_rotate_right(w);
									w = p->right;
								}
								w->color = p->color;
								p->color = BLACK;
								w->right->color = BLACK;
								_rotate_left(p);
								tmp = _root;
							}
						}
					}
					else
					{
						w = p->left;
						if (w != NULL && w->color == RED)
						{
							w->color = BLACK;
							p->color = RED;
							_rotate_right(p);
							w = p->left;
						}
						if (w != NULL)
						{
							if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK))
							{
								w->color = RED;
								tmp = p;
							}
							else
							{
								if (w->left != NULL && w->left->color == BLACK)
								{
									if (w->right != NULL)
										w->right->color = BLACK;
									w->color = RED;
									_rotate_left(w);
									w = p->left;
								}

								w->color = p->color;
								p->color = BLACK;
								if (w->left != NULL)
									w->left->color = BLACK;
								_rotate_right(p);
								tmp = _root;
							}
						}
					}
				}
				tmp->color = BLACK;
			}
	};

/*
 * Non-member functions
 */

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		typename ft::map<Key, T>::const_iterator rit = rhs.begin();
		typename ft::map<Key, T>::const_iterator lit = lhs.begin();
		if (lhs.size() != rhs.size())
			return false;
		while (rit != rhs.end() && lit != lhs.end())
		{
			if (*rit != *lit)
				return false;
			rit++;
			lit++;
		}
		return true;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return !(rhs == lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator< (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return !(lhs > rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator> (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key,T,Compare,Alloc> &lhs, ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return lhs.swap(rhs);
	}
}

#endif
