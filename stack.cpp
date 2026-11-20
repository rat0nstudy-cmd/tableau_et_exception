#include "stack.h"

#include <array>

void add_stack(const int value) {
    stack[stack_counter] = value;
    stack_counter++;
}

int unstack() {
    stack_counter--;
    return stack[stack_counter - 1];
}

int get_stack_top() {
    return stack[stack_counter - 1];
}

void update_stack_top(const int value) {
    stack[stack_counter - 1] = value;
}

bool is_stack_empty() {
    return !stack_counter;
}

std::size_t get_stack_size() {
    return stack_counter;
}

void empty_stack() {
    stack_counter = 0;
    //stack = {};
}