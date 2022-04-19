#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
#include "pair.hpp"
#include "map_reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"

#define BLACK 0
#define RED 1

namespace ft
{
	template<class Pair>
	class BSTNode
	{
		public:
			BSTNode* 	parent;
			BSTNode* 	left;
			BSTNode* 	right;
			Pair		value;
			int			color;

			explicit BSTNode() : parent(NULL), left(NULL), right(NULL), value(), color(1) {}

			explicit BSTNode(const Pair &data): parent(NULL), left(NULL), right(NULL), value(data), color(1) {}

			~BSTNode(void) {}

			BSTNode(const BSTNode &x): parent(x.parent), left(x.left), right(x.right), value(x.value), color(x.color) {}

			BSTNode &operator=(const BSTNode &x) {
				if (this != &x)
				{
					parent = x.parent;
					left = x.left;
					right = x.right;
					value = x.value;
					color = x.color;
				}
				return *this;
			}

			BSTNode *findMin(BSTNode *node) {
				if (!node)
					return NULL;
				while (node->left)
					node = node->left;
				return node;
			}

			BSTNode *findMax(BSTNode *node) {
				if (!node)
					return NULL;
				while (node->right)
					node = node->right;
				return node;
			}

			BSTNode *next(void) {
				BSTNode* tmp = this;

				if (tmp->right)
					return findMin(tmp->right);

				BSTNode* tmp_parent = tmp->parent;

				while (tmp_parent && tmp == tmp_parent->right)
				{
					tmp = tmp_parent;
					tmp_parent = tmp_parent->parent;
				}
				return tmp_parent;
			}

			BSTNode *prev(void) {
				BSTNode *tmp = this;

				if (tmp->left)
					return findMax(tmp->left);

				BSTNode* tmp_parent = tmp->parent;
				while (tmp_parent && tmp == tmp_parent->left)
				{
					tmp = tmp_parent;
					tmp_parent = tmp_parent->parent;
				}
				return tmp_parent;
			}
	};
}

#endif
