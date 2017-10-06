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
    explicit stack(std::string& data);
    explicit stack (double inp);

    stack(const stack& original);
    virtual ~stack();

    stack & operator=(const stack& RHS);
    bool isEmpty()const;
    unsigned stackSize() const;
    std::string& top()const;
    double doubletop ();
    void push(std::string& data);
    //void push(double info);
    void pop();
};


#endif //LAB5_STACKS_AND_QUEUES_POSTFIX_STACK_H

