#include <iostream>
#include <stdexcept>

template<typename U> class DoubleLinkedList {
        private:
                struct Node {
                        Node(U* d) : data(d), prev(nullptr), next(nullptr){};
                        Node(U* d, Node* p, Node* n) : data(d), prev(p), next(n){};
                        U* data;
                        Node* prev;
                        Node* next;
                };
        private: 
                Node *head;
                Node *tail;
                int len;

                void insertMiddleNode(U* d, Node *current) {
                        Node *n = new Node(d, current, current->next);
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
                        n->next = n->prev = nullptr;
                        U *retVal = n->data;
                        delete n;
                        return retVal;
                }
        public: 
                DoubleLinkedList() {
                        head = tail = nullptr;
                        len = 0;
                }

                ~DoubleLinkedList() {
                        Node* current = head;
                        while(current != nullptr) {
                                Node* temp = current;
                                current = current->next;
                                delete temp;
                        }
                        delete current;
                }

                bool isEmpty() {
                        return len == 0;
                }

                int size() {
                        return len;
                }

                void addFirst(U *d) {
                        Node *n = new Node(d);
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
                        Node *n = new Node(d);
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
                                
                                insertMiddleNode(d, loopToIndex(index));
                                len++;
                        }
                       
                }

                void add(U* target, U* d) {

                        if(len == 0) {
                                throw std::exception("Empty List");
                        }
                        
                        if(target == head->data) {
                                addFirst(d);
                        }
                        else if(target == tail->data) {
                                addLast(d);
                        }

                        else {
                                Node *current = head;

                                while(current != nullptr && current->data != target) {
                                        current = current->next;
                                }

                                if(current == nullptr) {
                                        return;
                                }
                                insertMiddleNode(d, current);
                                len++;
                        }
                }

                U* removeFirst() {
                        if(isEmpty()) {
                                throw std::exception("Empty list");
                        }
                        Node* temp = head;
                        if(len == 1) {
                                head = tail = nullptr;
                        }
                        else {
                                head->next->prev = nullptr;
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
                                head = tail = nullptr;
                        }
                        else {
                                tail->prev->next = nullptr;
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
                                len--;
                                return removeMiddleNode(loopToIndex(index));

                        }
                }

                U* remove(U* target) {
                        if(head->data == target) {
                                return removeFirst();
                        }
                        else if(tail->data == target) {
                                return removeLast();
                        }
                        else {
                                Node *current = head;
                                while(current != nullptr && current->data != target) {
                                        current = current->next;
                                }
                                if(current == nullptr) {
                                        return nullptr;
                                }
                                len--;
                                return removeMiddleNode(current);
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

                class DLLIterator {
                        friend class DoubleLinkedList;
                        private:
                                Node *itrPtr;
                                DoubleLinkedList *itrList;
                                int itrIndex;

                                bool checkListPointer(const DLLIterator& otherItr) const {
                                       return itrList == otherItr.itrList;
                                }

                        
                        public:
                                DLLIterator(): itrPtr{nullptr}, itrList{nullptr}, itrIndex{-1} {};

                                DLLIterator(DoubleLinkedList *list) {
                                        DLLIterator(list, 0);
                                }

                                DLLIterator(DoubleLinkedList *list, int index) {
                                        if(index < 0 || index > size) {
                                                throw std::invalid_argument("index out of bounds");
                                        }
                                        itrList = list;
                                        itrIndex = index;
                                        if(index == list->len) {
                                                itrPtr == nullptr;
                                        }
                                        else {
                                                Node *current = list->head;
                                                bool forward = true;
                                                if(index > list->len/2) {
                                                        current = list->tail;
                                                        forward = false;
                                                }

                                                for(int i = 0; i > index; i++) {
                                                        current = forward ? current->next : current->prev;
                                                }
                                                itrPtr = current;
                                        }
                                }

                                void forward() {
                                        itrPtr = itrPtr->next;
                                        itrIndex++;
                                }

                                void backward() {
                                        itrPtr = itrPtr->prev;
                                        itrIndex--;
                                }

                                bool operator!=(const DLLIterator& otherItr) const {
                                        return checkListPointer(otherItr) && otherItr.itrIndex != itrIndex;
                                }

                                bool operator==(const DLLIterator& otherItr) const {
                                        return checkListPointer(otherItr) && otherItr.itrIndex == itrIndex;
                                }

                                bool operator>(const DLLIterator& otherItr) const {
                                        return checkListPointer(otherItr) && otherItr.itrIndex > itrIndex;
                                }

                                bool operator>=(const DLLIterator& otherItr) const {
                                        return (*this)>otherItr || (*this)==otherItr;
                                }

                                bool operator<(const DLLIterator& otherItr) const {
                                        return checkListPointer(otherItr) && otherItr.itrIndex < itrIndex;
                                }

                                bool operator<=(const DLLIterator& otherItr) const {
                                        return (*this)<otherItr || (*this)==otherItr;
                                }

                                DLLIterator& operator++() {
                                        forward();
                                        return *this;
                                }

                                DLLIterator operator++(int) {
                                        DLLIterator temp = *this;
                                        forward();
                                        return temp;
                                }

                                DLLIterator& operator--() {
                                        backward();
                                        return *this;
                                }

                                DLLIterator operator--(int) {
                                        DLLIterator temp = *this;
                                        backward();
                                        return temp;
                                }

                                U& operator*() {
                                        return itrPtr->data;
                                }
                };

                DLLIterator begin() {
                        return DLLIterator(this);
                }

                DLLIterator end() {
                        return DLLIterator(this, len);
                }

                DLLIterator iterator(int index) {
                        return DLLIterator(this, index);
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
        std::cout << "Value stored in list at index 1 is " <<  *list->get(1) << "\n";
        return 0;
}