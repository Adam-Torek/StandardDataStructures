#include <iostream>


template<typename U> class DoubleLinkedList {
        private:
                struct Node {
                        Node* next;
                        Node* prev;
                        U* data;
                };
        private: 
                Node *head;
                Node *tail;
                int size;


                Node* newNode(U* d) {
                        Node* n = new Node();
                        n->data = d;
                        return n;
                }
        public: 
                DoubleLinkedList() {
                        head = tail = NULL;
                        size = 0;
                }

                void addFirst(U *d) {
                        Node *n = newNode(d);
                        if(size == 0) {
                                head = tail = n;
                        }
                        else {
                                head->prev = n;
                                n->next = head;
                                head = n;
                        }
                        size++;
                }

                void addLast(U *d) {
                        Node *n = newNode(d);
                        if(size == 0) {
                                head = tail = n;
                        }
                        else {
                                tail->next = n;
                                n->prev = tail;
                                tail = n;
                        }
                }

                void add(int index, U *d) {
                        if(index < 0 || index >= size) {
                                throw std::exception("Passed index " + std::to_string(index) + " is out of bounds. The index must be greater"
                                + "than 0 and less than " + std::to_string(size) + ".");
                        }
                }

};

int main() {

        int i = 4;
        int *ptr = &i;
        int j = 3;
        int *ptr2 = &j;
        DoubleLinkedList<int> *list = new DoubleLinkedList<int>();
        list->addFirst(ptr);
        return 0;
}