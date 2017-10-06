//
// Created by Bryan on 9/30/2017.
//

#include "expression.h"

//expression::expression(){}

expression::expression(double input){

}
double expression::calculate_postfix(){

}

std::istream& operator>>(std::istream& stream, expression& RHS){

}

expression::expression(std::string& input_expression){
    std::string operators[] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; i++){
        if (input_expression == operators[i]){

        }
    }
}
