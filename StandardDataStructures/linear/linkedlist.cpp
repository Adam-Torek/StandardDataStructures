#include "linear.hpp"

namespace ds::linear {
    template<typename T>
    struct node {
        node(const T& d) : data(d) {}
        node(T&& d) noexcept: data(std::move(d)) {}
        T data;
        node<T> *next = nullptr;
        node<T> *prev = nullptr;
    };

    template<typename linked_list_> 
    class list_iterator : public bidirectional_iterator_ {
        private:
            node<T> *node_ptr = nullptr;
        public:
            using type_t = typename linked_list_::T;
            using type_pointer = type_t*;
            using type_ref = type_t&;

            list_iterator(node<T> *node_): node_ptr(node_) {}

            node<T>* get_ptr() {
                return node_ptr;
            }

            bool operator==(const list_iterator& other) {
                return other->node_ptr == node_ptr;
            }

            bool operator!=(const list_iterator& other) {
                return other->node_ptr != node_ptr;
            }

            type_ref operator*() {
                return *(node_ptr->data);
            }

            type_pointer operator->() {
                return node_ptr->data;
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
    class linked_list_: public linked_list<T> {
        private: 
            node<T> *head = nullptr;
            node<T> *tail = nullptr;
            int size = 0;

            linked_list() = default;

            void insert_at(node<T> *itr_node, T&& data) {
                node<T> *n = new node<T>(d);
                if(size == 0) {
                    head = tail = n;
                }
                else if(itr_node == head) {
                    itr_node->prev = n;
                    n->next = itr_node;
                    head = n;
                }
                else if (itr_node == nullptr) {
                    tail->next = n;
                    n->prev = tail;
                    tail = n;
                }
                else {
                    itr_node->prev->next = n;
                    n->prev = itr_node->prev;
                    itr_node->prev = n;
                    n->next = itr_node;
                }
                size++;
                return n;
            }

            void insert_at_const(node<T> *itr_node, const T& data) {
                node<T> *n = new node<T>(d);
                if(size == 0) {
                    head = tail = n;
                }
                else if(itr_node == head) {
                    itr_node->prev = n;
                    n->next = itr_node;
                    head = n;
                }
                else if (itr_node == nullptr){
                    tail->next = n;
                    n->prev = tail;
                    tail = n;
                }
                else {
                    itr_node->prev->next = n;
                    n->prev = itr_node->prev;
                    itr_node->prev = n;
                    n->next = itr_node;
                }
                size++;
                return n;
            }
        public:
            using type_t = T;
            using list_iterator_ = list_iterator<linked_list_<T>>;

            bool is_empty() {
                return size == 0;
            }

            T front() {
                return is_empty() ? nullptr : head->data;
            }

            T back() {
               return is_empty() ? nullptr : tail->data;
            }

            void push_back(T&& data) {
                node<T> *n = new node<T>(n);
                insert_at(head, n);
            }

            void push_front(T&& data) {
                node<T> *n = new node<T>(n);
                insert_at(nullptr, n);
            }

            void push_back(const T& data) {
                node<T> *n = new node<T>(n);
                insert_at(head, n);
            }

            void push_front(const T& data) {
                node<T> *n = new node<T>(n);
                insert_at(nullptr, n);
            }

            bidirectional_iterator_ insert(list_iterator itr, T&& data) {
                node<T> *new_itr_node = insert_at(itr->get_ptr(), data);
                return list_iterator(new_itr_node);
            }

            bidirectional_iterator_ insert(list_iterator itr, const T& data) {

                node<T> *new_itr_node = insert_at_const(itr->get_ptr(), data);
                return list_iterator(new_itr_node);
            }

            bidirectional_iterator_ insert(list_iterator itr, T&& data, unsigned int count) {
                node<T> *new_itr_node;
                for(int i = 0; i < count; i++) {
                    new_itr_node = insert_at(itr->get_ptr(), data);
                }
                return list_iterator(new_itr_node);
            }

            bidirectional_iterator_ insert(list_iterator itr, bidirectional_iterator_ begin, bidirectional_iterator_ end) {
                node<T> *new_itr_node;
                for(bidirectional_iterator_ pos = begin; pos != end; pos++) {
                    new_itr_node = insert_at(itr->get_ptr(), *pos);
                }
                return list_iterator(new_itr_node);
            }

            bidirectional_iterator_ begin() {
                return list_iterator(head);
            }

            bidirectional_iterator_ end() {
                return list_iterator(nullptr);
            }
    };
}