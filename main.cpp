#include <iostream>
#include <sstream>
#include "expression.h"
#include "node.h"
#include "queue.h"
#include "stack.h"
#include <string>
int precedence (std::string &a);
int right_assoc (std::string &a);
int compare_prec (std::string &a, std::string& b);
void infix_postfix(std::string &exp, std::string &res);
bool isop (const std::string & op);
void calculate (const std::string & str, stack &obj);
std::istream &operator >> (std::istream & is, stack & rhs);
void get_postfix(std::string &exp, std::string &result, stack &obj2 );

//I apologize for the dirty main
//I used stack instead of queue and my postfix stuff is working
//please do not clear the main as it is vital to the operation of the calculations
//cannot use ^ operation
//only works with single digit numbers
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
    std::string exp = "(1+2)*3-4";
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
    return is;
}

int precedence (std::string& a){        //find which operation needs to be done first

    if (a == "^" || a == "$"){
        return 3;
    }
    if (a == "*" || a == "/"){
        return 2;
    }
    if (a == "+" || a == "-"){
        return 1;

    }
}

int compare_prec (std::string& a, std::string &b){
    int weight1 = precedence(a);
    int weight2 = precedence(b);

    if (weight1 == weight2){
        if(right_assoc(a)) return false;
        else return true;
    }
    return weight1 > weight2 ? true: false;
 }

int right_assoc (std::string &a){
    if(a == "$") return true;
    return false;
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
        if (check == "+"|| check== "-" || check== "*" || check == "/" || check == "^"){
            std::string thing;
            thing = exp[i];

            while(!s.isEmpty() && s.top() != "(" && precedence(s.top()) >= precedence(thing))
            {      // && compare_prec(s.top(),thing
                res+= s.top();
                s.pop();
            }
            s.push(thing);

            /*while (!s.isEmpty() && precedence(s.top()) >= precedence(thing) ){
                res += s.top();
                s.pop();
            }
            std::string bud;
            bud = exp[i];
            s.push(bud);*/
        }
        else if (check != "+"&& check != "-" && check != "*" && check != "/" && check != "^" && check != "(" && check != ")"){
            res+=exp[i];
        }
        else if (check == "("){
            s.push(check);
        }
        else if(check == ")"){
            while (!s.isEmpty() && s.top() != "("){
                res+= s.top();
                s.pop();
            }
            //s.pop();
        }

    }
    while (!s.isEmpty() && s.top() != "("){
        res += s.top();
        s.pop();
    }

}



/*
string InfixToPostfix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
    stack<char> s;
    string postfix = ""; // Initialize postfix as empty string.
    for(int i = 0;i< expression.length();i++) {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(expression[i] == ' ' || expression[i] == ',') continue;

            // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(expression[i]))
        {
            while(!s.empty() && s.top() != "(" && (s.top(),check))
            {
                res+= s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
            // Else if character is an operand
        else if(IsOperand(expression[i]))
        {
            postfix +=expression[i];
        }

        else if (expression[i] == '(')
        {
            s.push(expression[i]);
        }

        else if(expression[i] == ')')
        {
            while(!s.empty() && s.top() !=  '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

*/
