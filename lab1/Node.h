#ifndef NODE_H
#define NODE_H
#include <cstddef>
// template <class t>
class Node {
    public:
        int data;
        Node * prev;
        Node * next;
        Node(int data) {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
        ~Node() {}
    
    protected:

    private:
};

#endif 