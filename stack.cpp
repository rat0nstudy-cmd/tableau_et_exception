#include "stack.h"
#include<iostream>

#include <stdexcept>

void push(const int value, Stack& stack, std::size_t& stack_counter) {
    if (stack_counter == stack.size()) {
        throw std::overflow_error("impossible d'empiler dans une pile pleine.");
    }
    stack.at(stack_counter) = value;
    stack_counter++;
}

void pop(std::size_t& stack_counter) {
    if (stack_counter == 0) {
        throw std::underflow_error("impossible de depiler une pile vide.");
    }
    stack_counter--;
}

int top(const Stack& stack, const std::size_t& stack_counter) {
    if (stack_counter == 0) {
        throw std::underflow_error("impossible de consulter le sommet d'une pile vide.");
    }
    return stack.at(stack_counter - 1);
}

void top(const int value, Stack& stack, const std::size_t& stack_counter) {
    if (stack_counter == 0) {
        throw std::underflow_error("impossible de remplacer le sommet d'une pile vide.");
    }
    stack.at(stack_counter - 1) = value;
}

bool empty(const std::size_t& stack_counter) {
    return stack_counter == 0;
}

std::size_t size(const std::size_t& stack_counter) {
    return stack_counter;
}

void clear(std::size_t& stack_counter) {
    stack_counter = 0;
}
