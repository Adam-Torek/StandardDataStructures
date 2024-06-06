#include <initializer_list>
#include <memory>
#include "array_iterator"
namespace ds::linear
{
    template<typename T, typename _alloc = std::allocator<T>>
    class dynamic_array {
        public:
            using value_type = T;
            using reference_type = T&;
            using const_reference = const reference_type;
            using allocator_type = _alloc;
            using pointer_type = typename allocator_type::pointer;
            using const_pointer_type = typename allocator_type::const_pointer;
            using difference_type = std::ptrdiff_t;

        private:
            size_t size;
            size_t capacity;
            pointer_type begin;
            pointer_type end;
            pointer_type end_of_storage;
            allocator_type alloca;

            bool realloc(size_t n) {
                if(capacity >= n) {
                    return true;
                }
                size_t old_capacity = capacity;
                this->capacity = size + n;
                pointer_type new_space = alloca.allocate(n);
                if(new_space == nullptr) {
                    return false;
                }
                for(int i = 0; i < size; i++) {
                    new_space[i] = begin[i]; 
                }
                alloca.deallocate(begin, size);
                begin = new_space[0];
                end = new_space[old_capacity];
                end_of_storage = new_space[capacity];
                return true;
            }

            template <class InputIterator>
            array_iterator<value_type> insert_range(array_iterator<value_type> position, InputIterator beg_it, InputIterator end_it) {
                size_t n_to_insert = 0;
                for(InputIterator temp = beg_it; temp != end_it; temp++ ) {
                    n_to_insert++;
                }
                while(capacity < size + n_to_insert) {
                    realloc(size*2);
                }

                for(size_t i = 0; i < n_to_insert; i++) {
                    begin[end-i+n_to_insert] = begin[end-i]; 
                }


                array_iterator<value_type> ret_pos = beg_it;
                for(; beg_it != end_it; beg_it++, (void)position++) {
                    *position = *beg_it;
                }

                size += n_to_insert;
                end = begin[size];
                return ret_pos;
            }

            template <class InputIterator>
            array_iterator<value_type> insert_one(InputIterator pos, const value_type& val) {
                InputIterator end = pos;
                end++;
                return insert_range(pos, end, val);
            }
        
        public:
            dynamic_array(const allocator_type& alloc = allocator_type()) {
                size = capacity = 0;
                begin = end = end_of_storage = nullptr;
                alloca = alloc;
            }

            dynamic_array(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
                dynamic_array(alloc);
            }

            
            array_iterator<value_type> insert(array_iterator<value_type> pos, const value_type& val) {
                return insert_one(pos, val);
            }
    };
}
