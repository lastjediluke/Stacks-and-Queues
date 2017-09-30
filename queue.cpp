//
// Created by Bryan on 9/30/2017.
//

#include "queue.h"

queue::queue() :head(nullptr),tail(nullptr),size(0){}

queue::queue(std::string &data) {
    head=tail=new node(data);
    size=1;
}

bool queue::isEmpty() const {
    return size==0;
}

unsigned &queue::queueSize() const {
    return size;
}

std::string &queue::top() const {
    //step 1 return top item of queue
}

void queue::enqueue(std::string &data) {
    //step 1 create a new node
    //step 2 update next of node pointed to by tail with address of new node
    //step 3 update tail with address of new node
    //step 4 update size of stack variable
}

void queue::dequeue() {
    //step 1 store address of current top node (pointed to by head) in a node*
    //step 2 update head with address of second node
    //step 3 delete node pointed to by address stored in step 1
    //step 4 update size of stack variable
}
