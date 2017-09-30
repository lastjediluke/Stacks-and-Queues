//
// Created by Bryan on 9/29/2017.
//

#include "stack.h"

stack::stack():head(nullptr), size(0) {}

stack::stack(std::string &data) {
    head = new node(data);
    size =1;
}

bool stack::isEmpty() const {
    return size==0;
}

unsigned &stack::stackSize() const {
    return size;
}

std::string &stack::top() const {
    //step 1 Write this function to return the data from the top node on the stack
}

void stack::push(std::string &data) {
    //step 1 store address of current top node (pointed to by head) in a node*
    //step 2 create a new node with the incoming data variable, storing the address of this node in head pointer
    //step 3 update new nodes next pointer with the address stored in step 1
    //step 4 update size of stack variable
}

void stack::pop() {
    //step 1 store address of current top node (pointed to by head) in a node*
    //step 2 update head with address of second node
    //step 3 delete node pointed to by address stored in step 1
    //step 4 update size of stack variable
}
