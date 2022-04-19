#ifndef STACK_HPP
#define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> > class stack {
		public:
			typedef Container									container_type;
    		typedef typename container_type::value_type			value_type;
    		typedef typename container_type::reference			reference;
    		typedef typename container_type::const_reference	const_reference;
    		typedef typename container_type::size_type			size_type;

		protected:
			container_type	c;

		public:
			explicit stack (const container_type& __q = container_type()): c(__q) {}
			stack(const stack& __q) : c(__q.c) {}
			~stack() { c.clear(); }

			stack& operator=(const stack& __q) {
				c = __q.c;
				return *this;
			}

			bool	empty() const {
				return c.empty();
			}

			size_type	size() const {
				return c.size();
			}

			reference	top() {
				return c.back();
			}

			const_reference	top() const {
				return c.back();
			}

			void	push(const value_type& _v) {
				c.push_back(_v);
			}

			void	pop() {
				c.pop_back();
			}

			friend
			bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
				return (lhs.c == rhs.c);
			}

			friend
			bool operator< (const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
				return (lhs.c < rhs.c);
			}
	};
		template <class T, class Container>
		bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return !(lhs == rhs);
		}

		template <class T, class Container>
		bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return !(rhs < lhs);
		}

		template <class T, class Container>
		bool operator> (const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return (rhs < lhs);
		}

		template <class T, class Container>
		bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return !(lhs < rhs);
		}
}
#endif
