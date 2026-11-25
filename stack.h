#ifndef TABLEAU_ET_EXCEPTION_STACK_H
#define TABLEAU_ET_EXCEPTION_STACK_H
#include <cstddef>
#include <array>

constexpr std::size_t stack_size = 10;
using Stack = std::array<int, stack_size>;

void push(int value, Stack& stack, std::size_t& stack_counter);
void pop(std::size_t& stack_counter);
int top(const Stack& stack, const std::size_t& stack_counter);
void top(int value, Stack& stack, const std::size_t& stack_counter);
bool empty(const std::size_t& stack_counter);
std::size_t size(const std::size_t& stack_counter);
void clear(std::size_t& stack_counter);
#endif //TABLEAU_ET_EXCEPTION_STACK_H
