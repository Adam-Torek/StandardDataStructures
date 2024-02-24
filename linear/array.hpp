#include <cstddef>
#include <cstring>

namespace ds::linear
{
    template<typename T>
    class array_iterator {
        public:
            using value_type = T;
            using pointer_type = value_type*;
            using reference_type = value_type&;
            using difference_type = std::ptrdiff_t;

            array_iterator(pointer_type ptr): itr_ptr(ptr) {};

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

            reference_type operator[](difference_type n) {
                return *(itr_ptr+n);
            }

            difference_type operator-(const array_iterator& other) const {
                return this.itr_ptr-other.itr_ptr;
            }

            array_iterator operator-(difference_type n) const {
                return array_iterator(itr_ptr-n);
            }

            array_iterator operator+(difference_type n) const {
                return array_iterator(itr_ptr+n);
            }

            friend array_iterator operator+(difference_type n, const array_iterator& other) {
                return array_iterator(other.itr_ptr+n);
            }

            friend array_iterator operator-(difference_type n, const array_iterator& other) {
                return array_iterator(other.itr_ptr-n);
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

        private:
            pointer_type itr_ptr;
    };

    template<typename T, unsigned int SIZE>
    class array {
       
        private: 
            T data[SIZE];
        public:
            using value_type = T;
            using pointer_type = value_type*;
            using reference_type = value_type&;
            using iterator = array_iterator<value_type>;
            using const_iterator = array_iterator<const value_type>;

            array() {
                memset(data, 0, sizeof(T)*SIZE);
            };
            constexpr unsigned int size() const {
                return SIZE;
            }

            value_type front() {
                return data[0];
            }

            reference_type back() {
                return data[SIZE-1];
            }

            reference_type at(unsigned int index) {
                return data[index];
            }

            const reference_type at(unsigned int index) const {
                return data[index];
            }

            reference_type operator[](unsigned int index) {
                return at(index);
            }

            const reference_type operator[](unsigned int index) const {
                return at(index);
            }

            iterator begin() {
                return iterator(&data[0]);
            }

            iterator end() {
                return iterator(&data[SIZE]);
            }

            const_iterator cbegin() const {
                return const_iterator(&data[0]);
            }

            const_iterator cend() const {
                return const_iterator(&data[SIZE]);
            }
        };
} // namespace ds::linear
