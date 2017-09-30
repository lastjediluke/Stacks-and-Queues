//
// Created by Bryan on 9/29/2017.
//

#ifndef LAB5_STACKS_AND_QUEUES_POSTFIX_STACK_H
#define LAB5_STACKS_AND_QUEUES_POSTFIX_STACK_H


#include "node.h"

class stack {
    node * head;
    unsigned size;

public:
    stack();
    stack(std::string& data);
    stack(const stack& original);
    virtual ~stack();

    stack & operator=(const stack& RHS);
    bool isEmpty()const;
    unsigned& stackSize() const;
    std::string& top()const;
    void push(std::string& data);
    void pop();
};


#endif //LAB5_STACKS_AND_QUEUES_POSTFIX_STACK_H

