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
                int len;

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

                void checkIndex(int index) {
                         if(index < 0 || index >= len) {
                                throw std::invalid_argument("Index out of Bounds");
                        }
                }

                Node *loopToIndex(int index) {
                        Node *current = head;
                        for(int i = 0; i < index-1; i++) {
                                current = current->next;
                        }
                        return current;
                }

                U* removeMiddleNode(Node* n) {
                        n->prev->next = n->next;
                        n->next->prev = n->prev;
                        n->next = n->prev = NULL;
                        U *retVal = n->data;
                        delete n;
                        return retVal;
                }
        public: 
                DoubleLinkedList() {
                        head = tail = NULL;
                        len = 0;
                }

                bool isEmpty() {
                        return len == 0;
                }

                int size() {
                        return len;
                }

                void addFirst(U *d) {
                        Node *n = newNode(d);
                        if(len == 0) {
                                head = tail = n;
                        }
                        else {
                                head->prev = n;
                                n->next = head;
                                head = n;
                        }
                        len++;
                }

                void addLast(U *d) {
                        Node *n = newNode(d);
                        if(len == 0) {
                                head = tail = n;
                        }
                        else {
                                tail->next = n;
                                n->prev = tail;
                                tail = n;
                        }
                        len++;
                }

                void add(int index, U *d) {
                        if(index < 0 || index > len) {
                                throw std::invalid_argument("Index out of bounds");
                        }

                        if(index == 0) {
                                addFirst(d);
                        }
                        else if(index == len) {
                                addLast(d);
                        }
                        else {
                                
                                insertMiddleNode(newNode(d), loopToIndex(index));
                                len++;
                        }
                       
                }

                void add(U* target, U* d) {

                        if(len == 0) {
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
                                len++;
                        }
                }

                U* removeFirst() {
                        if(isEmpty()) {
                                throw std::exception("Empty list");
                        }
                        Node* temp = head;
                        if(len == 1) {
                                head = tail = NULL;
                        }
                        else {
                                head->next->prev = NULL;
                                head = head->next;                                
                        }
                        len--;
                        U *retVal = temp->data;
                        delete temp;
                        return retVal;
                }
                 
                U* removeLast() {
                        if(isEmpty()) {
                                throw std::exception("Empty list");
                        }
                        Node* temp = tail;
                        if(len == 1) {
                                head = tail = NULL;
                        }
                        else {
                                tail->prev->next = NULL;
                                tail = tail->prev;                                
                        }
                        len--;
                        U *retVal = temp->data;
                        delete temp;
                        return retVal;
                }

                U* remove(int index) {
                        checkIndex(index);
                        if(index == 0) {
                                return removeFirst();
                        }
                        else if(index == len-1) {
                                return removeLast();
                        }
                        else {
                                return removeMiddleNode(loopToIndex(index));
                        }
                }

                U* get(int index) {
                        checkIndex(index);
                        if(index == 0) {
                                return head->data;
                        }
                        else if(index == len-1) {
                                return tail->data;
                        }
                        return loopToIndex(index)->data;
                }

                void set(U* d, int index) {
                       checkIndex(index);
                       if(index == 0) {
                                head->data = d;
                       }
                       else if(index == len-1) {
                                tail->data = d;
                       }
                       else {
                                Node *setNode = loopToIndex(index);
                                setNode->data = d; 
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
        list->add(1, ptr2);
        std::cout << "Value stored in list at index 1 is " <<  *list->get(1);
        return 0;
}