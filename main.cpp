#include <iostream>
#include <sstream>
#include "expression.h"
#include "node.h"
#include "queue.h"
#include "stack.h"
#include <string>
int main() {
    stack obj;
    std::string s;
    while (true){
        std::cout << ">>";
        std::cin>>s;
        double num;
        if (std::istringstream(s) >> num){
            obj.push(num);
        }
        else if (expression(num)){
            calculate_postfix();
        }
        else if (s == "q"){
            return 0;
        }

        else {
            std::cout << "Not valid" << std::endl;
        }
        obj.

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}