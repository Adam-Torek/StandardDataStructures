#include <iostream>
#include <stdexcept>

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
                        n->next = n->prev = NULL;
                        return n;
                }

                void insertMiddleNode(Node *n, Node *current) {
                        n->prev = current;
                        n->next = current->next;
                        current->next->prev = n;
                        current->next = n;
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
                        size++;
                }

                void add(int index, U *d) {
                        if(index < 0 || index > size) {
                                throw std::invalid_argument("Index out of bounds");
                        }

                        if(index == 0) {
                                addFirst(d);
                        }
                        else if(index == size) {
                                addLast(d);
                        }
                        else {
                                Node *n = newNode(d);
                                Node *current = head;
                                for(int i = 0; i < index-1; i++) {
                                        current = current->next;
                                }
                                insertMiddleNode(n, current);
                                size++;
                        }
                       
                }

                void add(U* target, U* d) {

                        if(size == 0) {
                                throw std::exception("Empty List");
                        }

                        if(target == tail->data) {
                                addLast(d);
                        }

                        else {
                                Node *current = head;

                                while(current != NULL && current->data != target) {
                                        current = current->next;
                                }

                                if(current == NULL) {
                                        return;
                                }
                                insertMiddleNode(newNode(d), current);
                                size++;
                        }
                }

                U* get(int index) {
                        if(index < 0 || index >= size) {
                                throw std::invalid_argument("Index out of Bounds");
                        }

                        Node *current = head;
                        for(int i = 0; i < size-1; i++) {
                                current = current->next;
                        }
                        return current->data;
                }

};

int main() {

        int i = 4;
        int *ptr = &i;
        int j = 3;
        int *ptr2 = &j;
        DoubleLinkedList<int> *list = new DoubleLinkedList<int>();
        list->addFirst(ptr);
        list->add(1, ptr2);
        std::cout << "Value stored in list at index 1 is " <<  *list->get(1);
        return 0;
}