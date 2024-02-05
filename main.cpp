#include <iostream>

template<typename T> class Node {
        private:
                Node *next;
                Node *prev;
                T *data;
        public:
                Node(T *d) {
                        next = NULL;
                        prev = NULL;
                        data = d;
                }
                Node(T *d, Node *p, Node *n) {
                        next = n;
                        prev = p;
                        data = d;
                }

                T* getData() {
                        return data;
                }

                void setData(T* d) {
                        data = d;
                }

                void setNext(Node *n) {
                        next = n;
                }

                void setPrev(Node *p) {
                        prev = p;
                }

                Node* getPrev() {
                        return prev;
                }

                Node* getNext() {
                        return next;
                }
};

template<typename U> class DoubledLinkedList {
        private: 
                Node<U> *head;
                Node<U> *tail;
                int size;
        public: 
                DoubleLinkedList() {
                        head = tail = NULL;
                        size = 0;
                }

                DoubleLinkedList() {
                        
                }
};

int main() {

        int i = 4;
        int *ptr = &i;
        int j = 3;
        int *ptr2 = &j;
        Node<int> *n = new Node<int>(ptr);
        Node<int> *nxt = new Node<int>(ptr2, n, NULL);
        std::cout<<"Node Pointer Data: "<< *((int*)nxt->getPrev()->getData()) << std::endl;
        return 0;
}