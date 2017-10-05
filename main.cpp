#include <iostream>
#include <sstream>
#include "expression.h"
#include "node.h"
#include "queue.h"
#include "stack.h"
#include <string>

bool isop (const std::string & op);
void calculate (const std::string & str, stack &obj);
int main() {
    stack obj(2.2);

    std::string s;
    while (true){
        std::cout << ">>";
        std::cin>>s;
        double num = 0;
        if (std::istringstream(s) >> num){
            obj.push(num);
        }
        else if (isop(s)){
            calculate(s, obj);
        }
        else if (s == "q"){
            return 0;
        }

        else {
            std::cout << "Not valid" << std::endl;
        }


    }

    return 0;
}

bool isop (const std::string & op){
    std::string operators[] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; i++){
        if (op == operators[i]){
            return true;

        }
    }
    return false;
}

void calculate (const std::string & str, stack & obj){
    double left = 0;
    double right = 0;
    double result = 0;
right = obj.doubletop();
    obj.pop();

    left = obj.doubletop();
    obj.pop();

    if (str == "-"){
        result = left - right;
    }

    else if (str == "+"){
        result = left + right;
    }

    else if (str == "*"){
        result = left*right;
    }

    if (str == "/"){
        result = left/right;
    }

    std::cout<< result << std::endl;

    obj.push(result);
}