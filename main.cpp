#include <iostream>
#include <sstream>
#include "expression.h"
#include "node.h"
#include "queue.h"
#include "stack.h"
#include <string>
int precedence (std::string &a);
//int precedence (char a);
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

    std::cout << res << std::endl;
}


void i2p(std::string & s);

bool isop (const std::string & op);
//std::istream &operator >>(std::istream & is, stack & rhs);
void calculate (const std::string & str, stack &obj);

int main() {
    std:: cout << "You are now about to be Reverse Polished" << std::endl;
    stack obj;
    stack obj2;
    std::string result;
    std::string exp = "1+2*3-4";
    infix_postfix(exp, result);
    std::string s = "";
    //std::cout << result << std::endl;
    int nums = 0;






       for (int i = 0; i < 7; i++) {
           std::string z;
           z = result[i];

           if (std::istringstream(z) >> nums) {
               obj2.push(z);

               //std::cout << obj.top() << std::endl;
           } else if (isop(z)) {
               calculate(z, obj2);
               //std::cout << obj.top() << std::endl;
           }
       }


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
    return 0;
}



/*std::istream &operator >> (std::istream & is, stack & rhs){

    is >>
}*/

void i2p (std::string& s){
    stack obj;
    std::string a = "N";
obj.push(a);
    int length = s.length();
    std::string b;
    int num = 0;
    for (int i = 0; i < length; i++){
        if (s[i] != ('+' || '-' || '*' || '/' || '^')){
            b+=s[i];
        }
        else if (s[i] == '('){
            std::string lparen = "(";
            obj.push(lparen);
        }
        else if (s[i] == ')'){
            while (obj.top() != "N" && obj.top() != "(") {
                std::string d;
                d = obj.top();
                obj.pop();
                b += d;
            }
                if (obj.top() == "("){
                    std::string e;
                    e = obj.top();
                    obj.pop();
                }


            }

        else {
            while (obj.top() != "N" && precedence(obj.top()) <= precedence(obj.top())){
                std::string f;
                f = obj.top();
                obj.pop();
                b+= f;

            }
            std::string g;
            g = s[i];
            obj.push(g);
        }
    }

    while (obj.top() != "N"){
        std::string h;
        h = obj.top();
        obj.pop();
        b+= h;
    }
    std::cout << b << std::endl;
}
/*int precedence (char a){
    if (a == '^'){
        return 3;
    }
    else if (a == '*' || a == '/'){
        return 2;
    }
    else if (a == '+' || a == '-'){
        return 1;
    }
    else {
        return -1;
    }
}*/
int precedence (std::string& a){

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
//std::cout << l << std::endl;
      // std::cout << r << std::endl;


        ans = l - r;
        result = std::to_string(ans);
        //std::cout << "Real answer is " << ans << std::endl;

    }

    else if (str == "+"){
        ans = l + r;
        result = std::to_string(ans);
    }

    else if (str == "*"){

        ans = l * r;
        result = std::to_string(ans);
        //result = left*right;
    }

    if (str == "/"){

        ans = l/r;
        result = std::to_string(ans);
        //result = left/right;
    }

   std::cout<< result << std::endl;

    obj.push(result);
}