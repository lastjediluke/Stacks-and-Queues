//
// Created by Bryan on 9/30/2017.
//

#ifndef LAB5_STACKS_AND_QUEUES_POSTFIX_QUEUE_H
#define LAB5_STACKS_AND_QUEUES_POSTFIX_QUEUE_H


#include "node.h"

class queue {
    node *head, *tail;
    unsigned size;

public:
    queue();
    queue(std::string& data);
    queue(const queue& original);
    virtual ~queue();

    queue&operator=(const queue& RHS);
    bool isEmpty()const;
    unsigned queueSize() const;
    std::string& top()const;
    void enqueue(std::string& data);
    void dequeue();
};


#endif //LAB5_STACKS_AND_QUEUES_POSTFIX_QUEUE_H
