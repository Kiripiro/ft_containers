#ifndef MAP_REVERSE_ITERATOR_HPP
# define MAP_REVERSE_ITERATOR_HPP

# include <memory>
# include "RBT.hpp"

namespace ft
{
template <class Iterator>
class map_reverse_iterator
    {
        public:

            typedef Iterator    												iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
            typedef typename ft::iterator_traits<Iterator>::reference			reference;

			map_reverse_iterator(): _elem() {}
			explicit map_reverse_iterator (iterator_type it): _elem(it) {}
            template <class Iter>
            map_reverse_iterator (const map_reverse_iterator<Iter>& rev_it): _elem(rev_it.base()) {}
            virtual ~map_reverse_iterator() {}

            iterator_type base() const{
				return (_elem);
			}

            reference operator*() const {
                iterator_type tmp = _elem;
                return (*(--tmp));
            }

            map_reverse_iterator operator+ (difference_type n) const {
				return (map_reverse_iterator(_elem - n));
			}

            map_reverse_iterator& operator++() {
                --_elem;
                return (*this);
            }

            map_reverse_iterator operator++(int) {
                map_reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

            map_reverse_iterator& operator+= (difference_type n) {
                _elem -= n;
                return (*this);
            }

            map_reverse_iterator operator- (difference_type n) const {
				return (map_reverse_iterator(_elem + n));
			}

            map_reverse_iterator& operator--() {
                ++_elem;
                return (*this);
            }

            map_reverse_iterator operator--(int) {
                map_reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }

            map_reverse_iterator& operator-= (difference_type n) {
                _elem += n;
                return (*this);
			}

            pointer operator->() const {
				return &(operator*());
			}

            reference operator[] (difference_type n) const {
				return (this->base()[-n - 1]);
			}

        private:
            iterator_type     _elem;
    };
    template <class Iterator>
        bool operator==(const map_reverse_iterator<Iterator>& lhs, const map_reverse_iterator<Iterator>& rhs) {
			return (lhs.base() == rhs.base());
		}

    template <class Iterator_L, class Iterator_R>
        bool operator==(const map_reverse_iterator<Iterator_L>& lhs, const map_reverse_iterator<Iterator_R>& rhs) {
			return (lhs.base() == rhs.base());
		}

    template <class Iterator>
        bool operator!=(const map_reverse_iterator<Iterator>& lhs, const map_reverse_iterator<Iterator>& rhs) {
			return (lhs.base() != rhs.base());
		}

    template <class Iterator_L, class Iterator_R>
        bool operator!=(const map_reverse_iterator<Iterator_L>& lhs, const map_reverse_iterator<Iterator_R>& rhs) {
			return (lhs.base() != rhs.base());
		}

    template <class Iterator>
        bool operator< (const map_reverse_iterator<Iterator>& lhs, const map_reverse_iterator<Iterator>& rhs) {
			return (lhs.base() > rhs.base());
		}

    template <class Iterator_L, class Iterator_R>
        bool operator< (const map_reverse_iterator<Iterator_L>& lhs, const map_reverse_iterator<Iterator_R>& rhs) {
			return (lhs.base() > rhs.base());
		}

    template <class Iterator>
        bool operator<=(const map_reverse_iterator<Iterator>& lhs, const map_reverse_iterator<Iterator>& rhs) {
			return (lhs.base() >= rhs.base());
		}

    template <class Iterator_L, class Iterator_R>
		bool operator<=(const map_reverse_iterator<Iterator_L>& lhs, const map_reverse_iterator<Iterator_R>& rhs) {
			return (lhs.base() >= rhs.base());
		}

    template <class Iterator>
        bool operator> (const map_reverse_iterator<Iterator>& lhs, const map_reverse_iterator<Iterator>& rhs) {
			return (lhs.base() < rhs.bash());
		}

    template <class Iterator_L, class Iterator_R>
        bool operator> (const map_reverse_iterator<Iterator_L>& lhs, const map_reverse_iterator<Iterator_R>& rhs) {
			return (lhs.base() < rhs.base());
		}

    template <class Iterator>
        bool operator>=(const map_reverse_iterator<Iterator>& lhs, const map_reverse_iterator<Iterator>& rhs) {
			return (lhs.base() <= rhs.base());
		}

    template <class Iterator_L, class Iterator_R>
        bool operator>=(const map_reverse_iterator<Iterator_L>& lhs, const map_reverse_iterator<Iterator_R>& rhs) {
			return (lhs.base() <= rhs.base());
		}

    template <class Iterator>
        map_reverse_iterator<Iterator> operator+ (typename map_reverse_iterator<Iterator>::difference_type n, const map_reverse_iterator<Iterator>& rev_it) {
			return (rev_it + n);
		}

    template <class Iterator>
        typename map_reverse_iterator<Iterator>::difference_type operator- (const map_reverse_iterator<Iterator>& lhs, const map_reverse_iterator<Iterator>& rhs) {
			return (lhs.base() - rhs.base());
		}

    template <class Iterator_L, class Iterator_R>
        bool operator- (const map_reverse_iterator<Iterator_L>& lhs, const map_reverse_iterator<Iterator_R>& rhs) {
			return (lhs.base() - rhs.base());
		}
}

#endif
