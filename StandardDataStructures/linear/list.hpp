namespace ds::linear {
    struct bidirectional_iterator_ {};
    struct reverse_iterator_ {};
    struct random_access_iterator_ {};

    template<typename T>
    class list {
        public:
            virtual bool is_empty() = 0;

            virtual T front() = 0;

            virtual T back() = 0;

            virtual void push_back(T&& data) = 0;

            virtual void push_front(T&& data) = 0;

            virtual void push_back(const T& data) = 0;

            virtual void push_front(const T& data) = 0;

            virtual bidirectional_iterator_ insert(bidirectional_iterator_ pos, T&& data) = 0;

            virtual bidirectional_iterator_ insert(bidirectional_iterator_ pos, const T& data) = 0;

            virtual bidirectional_iterator_ insert(bidirectional_iterator_ pos, const T& data, unsigned int count) = 0;

            virtual bidirectional_iterator_ insert(list_iterator itr, bidirectional_iterator_ begin, bidirectional_iterator_ end) = 0;

            virtual bidirectional_iterator_ begin() = 0;

            virtual bidirectional_iterator_ end() = 0;
    };

    template<typename T>
    class linked_list: public list<T> {};

    template<typename T>
    class array_list: public list<T> {};

}
