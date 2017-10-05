//
// Created by Bryan on 9/29/2017.
//

#include "stack.h"

stack::stack():head(nullptr), size(0) {}

stack::stack(std::string &data) {
    head = new node(data);
    size =1;
}

stack::stack(const stack &original) {
    if (original.head!= nullptr) {
        node *original_tmp = original.head;
        node *tmp = head = new node(original_tmp->data);

        original_tmp = original_tmp->next;
        while (original_tmp != nullptr) {
            tmp->next = new node(original_tmp->data);
            tmp = tmp->next;
            original_tmp = original_tmp->next;
        }
    }
}

stack::~stack() {

    node *temp = head;
    while (head != NULL){
        temp = temp->next;
        delete head;
        head=temp;
    }
    //step 1 create destructor similar to linked list
}

stack &stack::operator=(const stack &RHS) {

    if(this != &RHS)
    {
        if (head!= nullptr)
            delete this;
        if (RHS.head!= nullptr) {

            node *RHS_tmp = RHS.head;
            node *tmp = head = new node(RHS_tmp->data);

            RHS_tmp = RHS_tmp->next;
            while (RHS_tmp != nullptr) {
                tmp->next=new node(RHS_tmp->data);
                tmp=tmp->next;
                RHS_tmp = RHS_tmp->next;
            }
        }
    }
    return *this;
}

bool stack::isEmpty() const {
    return size==0;
}

unsigned stack::stackSize() const {
    return size;
}

std::string &stack::top() const {

    return head->data;
    //step 1 Write this function to return the data from the top node on the stack
}

void stack::push(double info){
    if (head->next != nullptr) {
        node *temp = head;
        head = new node(info);
        head->next = temp;
        size++;
    }
}

void stack::push(std::string &data) {
    if (head->next != nullptr) {
        node *temp = head;
        head = new node(data);
        head->next = temp;
        size++;
    }
    //step 1 store address of current top node (pointed to by head) in a node*
    //step 2 create a new node with the incoming data variable, storing the address of this node in head pointer
    //step 3 update new nodes next pointer with the address stored in step 1
    //step 4 update size of stack variable
    // make sure to check if head is pointing to something
}

void stack::pop() {
    if (head->next != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    //step 1 store address of current top node (pointed to by head) in a node*
    //step 2 update head with address of second node
    //step 3 delete node pointed to by address stored in step 1
    //step 4 update size of stack variable
    // make sure to check if head is pointing to something
}






