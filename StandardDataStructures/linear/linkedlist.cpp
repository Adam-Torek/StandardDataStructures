#include "linear.hpp"

namespace ds::linear {
    template<typename T>
    struct node {
        node(const T& d): data(d) {}
        node(T&& d): data(std::move(d)) {}
        T data;
        node<T> *next = nullptr;
        node<T> *prev = nullptr;
    };

    template<typename list> 
    class list_iterator : public linear_iterator_ {
        private:
            node<T> *node_ptr = nullptr;
        public:
            using type_t = typename list::T;
            using type_pointer = type_t*;
            using type_ref = type_t&;

            list_iterator(node<T> *node_): node_ptr(node_) {}

            bool operator==(const list_iterator& other) {
                return other->node_ptr == node_ptr;
            }

            bool operator!=(const list_iterator& other) {
                return other->node_ptr != node_ptr;
            }

            type_ref operator*() {
                return node_ptr->data;
            }

            type_pointer operator->() {
                return &(node_ptr->data);
            }

            list_iterator& operator++() {
                node_ptr = node_ptr->next;
                return *this;
            }

            list_iterator operator++(int) {
                list_iterator temp = *this;
                ++(*this);
                return temp;
            }

            list_iterator& operator--() {
                node_ptr = node_ptr->prev;
                return *this;
            }

            list_iterator operator--(int) {
                list_iterator temp = *this;
                --(*this);
                return temp;
            }
    };

    template<typename T> 
    class list: public linear {
        private: 
            node<T> *head;
            node<T> *tail;
            int size;
        public:
            using type_t = T;
            using list_iterator_ = list_iterator<list<T>>;
            void insert(linear_iterator_ itr, T data) {

            }
    };
}