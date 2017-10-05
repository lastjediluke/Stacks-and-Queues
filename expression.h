//
// Created by Bryan on 9/30/2017.
//

#ifndef LAB5_STACKS_AND_QUEUES_POSTFIX_EXPRESSION_H
#define LAB5_STACKS_AND_QUEUES_POSTFIX_EXPRESSION_H


#include "queue.h"
#include "stack.h"

class expression {
    queue infix;
   queue postfix;




    stack conversion_buffer;

    void infix_to_postfix();
public:
    expression();
    expression(std::string& input_expression);
    expression (double input);



    double calculate_postfix();
    friend std::ostream& operator>>(std::ostream& steam, expression& RHS);

};


#endif //LAB5_STACKS_AND_QUEUES_POSTFIX_EXPRESSION_H
