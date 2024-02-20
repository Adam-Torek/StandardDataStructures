namespace ds::linear
{
    template<typename array>
    class array_iterator {
        public:
            using value_type = typename array::value_type;
            using pointer_type = value_type*;
            using reference_type = value_type&;
            using difference_type = 
            array_iterator(pointer_type ptr): itr_ptr(ptr) {};

            array_iterator& operator++() {
                itr_ptr++;
                return *this;
            }

            array_iterator operator++(int) {
                array_iterator temp = *this;
                ++(*this);
                return temp;
            }

            array_iterator& operator--() {
                itr_ptr--;
                return *this;
            }

            array_iterator operator--(int) {
                array_iterator temp = *this;
                --(*this);
                return temp;
            }

            reference_type operator*() {
                return *itr_ptr;
            }

            pointer_type operator->() {
                return &itr_ptr;
            }

        private:
            pointer_type itr_ptr;
    };

    template<typename T, unsigned int SIZE>
    class array: public array<T, unsigned int SIZE> {
        using value_type = T;
        using pointer_type = value_type*;
        using reference_type = value_type&;
        using iterator = array_iterator<array<T>>;
        private: 
            T[SIZE] data;
        public:
            array() = default;
            constexpr size() const {
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
        };
} // namespace ds::linear
