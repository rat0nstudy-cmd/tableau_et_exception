#include "stack.h"
#include<iostream>
#include<iomanip>

void add_stack(const int value, Stack& stack, std::size_t& stack_counter) {
    stack.at(stack_counter) = value;
    stack_counter++;
}

void unstack(std::size_t& stack_counter) {
    stack_counter--;
}

int get_stack_top(const Stack& stack, const std::size_t& stack_counter) {
    return stack[stack_counter - 1];
}

void update_stack_top(const int value, Stack& stack, const std::size_t& stack_counter) {
    stack[stack_counter - 1] = value;
}

bool is_stack_empty(const std::size_t& stack_counter) {
    return !stack_counter;
}

std::size_t get_stack_size(const std::size_t& stack_counter) {
    return stack_counter;
}

void empty_stack(size_t& stack_counter) {
    stack_counter = 0;
}
