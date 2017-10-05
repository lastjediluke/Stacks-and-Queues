//
// Created by Bryan on 9/29/2017.
//

#include "node.h"

node::node(const std::string &data) : data(data), next(nullptr) {}
node::node(){
    data = "";
    next = nullptr;
}
node::node(double info){
    inp = info;
    next = nullptr;
}
