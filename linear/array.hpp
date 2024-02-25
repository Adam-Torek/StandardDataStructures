#include <cstddef>
#include <cstring>
#include "../utils/utils.hpp"

namespace ds::linear
{
    template<typename array>
    class array_iterator {
        public:
            using value_type = typename array::value_type;
            using pointer_type = value_type*;
            using reference_type = value_type&;
            using difference_type = std::ptrdiff_t;

            array_iterator(pointer_type ptr): itr_ptr(ptr) {};
            array_iterator(const array_iterator& other) = default;
            ~array_iterator() = default;

            array_iterator& operator=(const array_iterator& other) = default;

            array_iterator& operator=(pointer_type ptr) 
            {
                itr_ptr = ptr; 
                return *this;
            }

            array_iterator& operator-=(const difference_type& n) {
                itr_ptr -= n;
                return *this;
            }

            array_iterator& operator+=(const difference_type& n) {
                itr_ptr += n;
                return *this;
            }

            array_iterator& operator++() {
                itr_ptr++;
                return *this;
            }           

            array_iterator& operator--() {
                itr_ptr--;
                return *this;
            }

            array_iterator operator++(int) {
                array_iterator temp = *this;
                ++(*this);
                return temp;
            }

            array_iterator operator--(int) {
                array_iterator temp = *this;
                --(*this);
                return temp;
            }

            reference_type operator*() const {
                return *itr_ptr;
            }

            pointer_type operator->() const {
                return &itr_ptr;
            }

            reference_type operator[](const difference_type& n) {
                return *(itr_ptr+n);
            }

            difference_type operator-(const array_iterator& other) const {
                return itr_ptr-other.get_ptr();
            }

            array_iterator operator-(const int& n) const {
                pointer_type old_ptr = itr_ptr;
                itr_ptr -= n;
                array_iterator temp = *this;
                itr_ptr = old_ptr;
                return temp;
            }

            array_iterator operator+(const int& n) const {
                pointer_type old_ptr = itr_ptr;
                itr_ptr += n;
                array_iterator temp = *this;
                itr_ptr = old_ptr;
                return temp;
            }

            bool operator==(const array_iterator& other) const {
                return itr_ptr == other.itr_ptr;
            }

            bool operator!=(const array_iterator& other) const {
                return  itr_ptr != other.itr_ptr;
            }

            bool operator>(const array_iterator& other) const {
                return itr_ptr > other.itr_ptr;
            }

            bool operator<(const array_iterator& other) const {
                return itr_ptr < other.itr_ptr;
            }

            bool operator<=(const array_iterator& other) const {
                return itr_ptr <= other.itr_ptr;
            }

            bool operator>=(const array_iterator& other) const {
                return itr_ptr >= other.itr_ptr;
            }

            pointer_type get_ptr() {
                return itr_ptr;
            }

            void set_ptr(pointer_type ptr) {
                itr_ptr = ptr;
            }

        protected:
            pointer_type itr_ptr;
    };

    template <typename array>
    class reverse_array_iterator: public array_iterator<array> 
    {
        public: 
            using value_type = typename array::value_type;
            using pointer_type = value_type*;
            using reference_type = value_type&;
            using difference_type = std::ptrdiff_t;

            reverse_array_iterator(pointer_type ptr): array_iterator<array>(ptr){}
            reverse_array_iterator(const reverse_array_iterator& other) = default;
            reverse_array_iterator(const array_iterator<array>& other) {
                this->itr_ptr = other->get_ptr();
            }

            ~reverse_array_iterator() = default;

            reverse_array_iterator& operator=(const reverse_array_iterator& other) = default;
            reverse_array_iterator& operator=(const array_iterator<array>& other) {
                this->itr_ptr = other->get_ptr();
                return *this;
            }

            reverse_array_iterator& operator=(const pointer_type ptr) {
                this->itr_ptr = ptr;
                return *this;
            }

            reverse_array_iterator& operator-=(const difference_type& n) {
                this->itr_ptr += n;
                return *this;
            }

             reverse_array_iterator& operator+=(const difference_type& n) {
                this->itr_ptr -= n;
                return *this;
            }


            reverse_array_iterator& operator++() {
                --this->itr_ptr; 
                return *this;
            }

            reverse_array_iterator operator++(int) {
                reverse_array_iterator temp = *this;
                ++(*this); 
                return temp;
            }

            reverse_array_iterator& operator--() {
                ++this->itr_ptr; 
                return *this;
            }

            reverse_array_iterator operator--(int) {
                reverse_array_iterator temp = *this;
                --(*this); 
                return temp;
            }

            reverse_array_iterator operator-(const int& n) const {
                pointer_type old_ptr = this->itr_ptr;
                this->itr_ptr += n;
                reverse_array_iterator temp = *this;
                this->itr_ptr = old_ptr;
                return temp;
            }

            reverse_array_iterator operator+(const int& n) const {
                pointer_type old_ptr = this->itr_ptr;
                this->itr_ptr -= n;
                reverse_array_iterator temp = *this;
                this->itr_ptr = old_ptr;
                return temp;
            }

            difference_type operator-(const reverse_array_iterator& other) {
                return this->get_ptr() - other->get_ptr();
            }

            array_iterator<array> base() {
                array_iterator<array> itr = array_iterator<array>(this->itr_ptr);
                ++itr;
                return itr;
            }

    };

    template<typename T, unsigned int SIZE>
    class array {
       
        private: 
            T arr[SIZE];
        public:
            using value_type = T;
            using pointer_type = value_type*;
            using reference_type = value_type&;
            using iterator = array_iterator<array<value_type, SIZE>>;
            using const_iterator = array_iterator<array<const value_type, SIZE>>;
            using reverse_iterator = reverse_array_iterator<array<value_type, SIZE>>;
            using const_reverse_iterator = reverse_array_iterator<array<const value_type, SIZE>>;

            array() {
                memset(arr, 0, sizeof(T)*SIZE);
            };

            const unsigned int size() const {
                return SIZE;
            }

            const unsigned int max_size() const {
                return SIZE;
            }

            bool empty() const {
                return SIZE == 0;
            }

            pointer_type data() {
                return &arr;
            }

            const pointer_type data() const {
                return &arr;
            }

            value_type front() {
                return arr[0];
            }

            reference_type back() {
                return arr[SIZE-1];
            }

            reference_type at(unsigned int index) {
                return arr[index];
            }

            const reference_type at(unsigned int index) const {
                return arr[index];
            }

            reference_type operator[](unsigned int index) {
                return at(index);
            }

            const reference_type operator[](unsigned int index) const {
                return at(index);
            }

            iterator begin() {
                return iterator(&arr[0]);
            }

            iterator end() {
                return iterator(&arr[SIZE]);
            }

            const_iterator cbegin() const {
                return const_iterator(&arr[0]);
            }

            const_iterator cend() const {
                return const_iterator(&arr[SIZE]);
            }

            reverse_iterator rbegin() {
                return reverse_iterator(&arr[SIZE-1]);
            }

            reverse_iterator rend() {
                return reverse_iterator(&arr[-1]);
            }

            const_reverse_iterator rcbegin() {
                return const_reverse_iterator(&arr[SIZE-1]);
            }

            const_reverse_iterator rcend() {
                return const_reverse_iterator(&arr[-1]);
            }

        };

        template<typename T, unsigned int SIZE>
        bool operator<(const array<T, SIZE>& left, const array<T, SIZE>& right) {
                return ds::utils::elementwise_compare(left.cbegin(), left.cend(), right.cbegin(), right.cend());
        }

        template<typename T, unsigned int SIZE>
        bool operator>(const array<T, SIZE>& left, const array<T, SIZE>& right) {
            return right < left;
        }

        template<typename T, unsigned int SIZE>
        bool operator<=(const array<T, SIZE>& left, const array<T, SIZE>& right) {
            return !(left < right);
        }

        template<typename T, unsigned int SIZE>
        bool operator>=(const array<T, SIZE>& left, const array<T, SIZE>& right) {
            return !(right < left);
        }

        template<typename T, unsigned int SIZE>
        bool operator==(const array<T, SIZE>& left, const array<T, SIZE>& right) {
            return ds::utils::equal(left.cbegin(), left.cend(), right.cbegin());
        }

        template<typename T, unsigned int SIZE>
        bool operator!=(const array<T, SIZE>& left, const array<T, SIZE>& right) {
            return !(left == right);
        }
} // namespace ds::linear
