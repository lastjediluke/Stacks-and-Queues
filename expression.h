//
// Created by Bryan on 9/30/2017.
//

#ifndef LAB5_STACKS_AND_QUEUES_POSTFIX_EXPRESSION_H
#define LAB5_STACKS_AND_QUEUES_POSTFIX_EXPRESSION_H


#include "queue.h"
#include "stack.h"
#include <iostream>
#include <sstream>
class expression {      //I did not actually use expression functions
    queue infix;
   queue postfix;




    stack conversion_buffer;

    void infix_to_postfix();
public:
   // expression();
    expression(std::string& input_expression);
    expression (double input);



    double calculate_postfix();
    friend std::istream& operator>>(std::istream& stream, expression& RHS);

};


/* while (true){

        std::cout << ">>";
        std::cin>>s;
        int nums = 0;
        if (std::istringstream(s) >> nums){
            obj.push(s);
            //std::cout << obj.top() << std::endl;
        }
        else if (isop(s)){
            calculate(s, obj);
            //std::cout << obj.top() << std::endl;
        }
        else if (s == "q"){
            return 0;
        }
    }
*/

#endif //LAB5_STACKS_AND_QUEUES_POSTFIX_EXPRESSION_H
