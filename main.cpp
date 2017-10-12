#include <iostream>
#include <sstream>
#include "expression.h"
#include "node.h"
#include "queue.h"
#include "stack.h"
#include <string>
int precedence (std::string &a);
void infix_postfix(std::string &exp, std::string &res);
bool isop (const std::string & op);
void calculate (const std::string & str, stack &obj);
std::istream &operator >> (std::istream & is, stack & rhs);
void get_postfix(std::string &exp, std::string &result, stack &obj2 );

//I apologize for the dirty main
//I used stack instead of queue and my postfix stuff is working
//please do not clear the main as it is vital to the operation of the calculations
//cannot use ^ operation
int main() {

    std:: cout << "You are now about to be Reverse Polished" << std::endl;
    stack obj;
    stack obj2;
    stack obj3;
    std::string result;
    std::string result2;
    std::cout << "Enter an infix string: ";
    std::cin >> obj3;
    std::cout << "String inputted: " << obj3.top() << std::endl;
    std::string exp = "1+2*3-4";
    std::cout<< "Infix1: " << exp << std::endl;
    infix_postfix(exp, result);
    std::cout << "Postfix1: " << result << std::endl;
    get_postfix(exp, result, obj2);
    std::cout << "Result1: " << obj2.top() << std::endl;

    std::cout<< "Infix2: " << obj3.top() << std::endl;
    infix_postfix(obj3.top(), result2);
    std::cout << "Postfix2: " << result2 << std::endl;
    get_postfix(obj3.top(), result2, obj3);
    std::cout << "Result2: " << obj3.top() << std::endl;

    return 0;
}

void get_postfix(std::string &exp,std::string &result, stack &obj2){
    int nums = 0;

    for (int i = 0; i < exp.length(); i++) {     //goes through string to check if there are operators or numbers
        std::string z;
        z = result[i];

        if (std::istringstream(z) >> nums) {     //check if number
            obj2.push(z);
        } else if (isop(z)) {        //check if operator
            calculate(z, obj2);
        }
    }
}



std::istream &operator >> (std::istream & is, stack & rhs){

    std::string k;
    is >> k;
    rhs.push(k);
}

int precedence (std::string& a){        //find which operation needs to be done first

    if (a == "^"){
        return 3;
    }
    if (a == "*" || a == "/"){
        return 2;
    }
    if (a == "+" || a == "-"){
        return 1;

    }
}

void calculate (const std::string & str, stack & obj){      //calculates the operation
    // std::cout << "calc running" << std::endl;
    std::string left;
    std::string right;
    std::string result;
    int l = 0;
    int r = 0;
    int ans = 0;
    //std::istringstream(right) >> r;
    //std::istringstream(left) >> l;

    right = obj.top();
    std::istringstream(right) >> r;
    obj.pop();

    left = obj.top();
    std::istringstream(left) >> l;
    obj.pop();

    if (str == "-"){
        ans = l - r;
        result = std::to_string(ans);
    }

    else if (str == "+"){
        ans = l + r;
        result = std::to_string(ans);
    }
    else if (str == "*"){

        ans = l * r;
        result = std::to_string(ans);
    }
    else if (str == "^"){

        ans = l^r;
        result = std::to_string(ans);

    }
    if (str == "/"){

        ans = l/r;
        result = std::to_string(ans);

    }

    //std::cout<< result << std::endl;

    obj.push(result);
}

bool isop (const std::string & op){
    std::string operators[] = {"+", "-", "*", "/", "^"};
    for (int i = 0; i < 5; i++){
        if (op == operators[i]){
            return true;

        }
    }
    return false;
}

void infix_postfix(std::string &exp, std::string &res){
    stack s;
    //std::string result;
    for (int i = 0; i < exp.length(); i++){
        std::string check;
        check = exp[i];
        if (check != "+"&& check!= "-" && check!= "*" && check != "/" && check != "^"){
            res+=exp[i];
        }
        else if (check == "+"|| check== "-" || check== "*" || check == "/" || check == "^"){
            std::string thing;
            thing = exp[i];

            while (!s.isEmpty() && precedence(s.top()) >= precedence(thing) ){
                res += s.top();
                s.pop();
            }
            std::string bud;
            bud = exp[i];
            s.push(bud);
        }
    }
    while (!s.isEmpty()){
        res += s.top();
        s.pop();
    }

    //std::cout << res << std::endl;
}





