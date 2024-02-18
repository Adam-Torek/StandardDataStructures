
struct linear_iterator_ {};

struct element_iterator_ {};
namespace ds::linear {
    template<typename T>
    class linear {
        public:
            virtual void insert(linear_iterator_ pos, T data) = 0;
    };
}
