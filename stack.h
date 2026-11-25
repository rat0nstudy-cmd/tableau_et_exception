#ifndef TABLEAU_ET_EXCEPTION_STACK_H
#define TABLEAU_ET_EXCEPTION_STACK_H
#include <cstddef>
#include <array>
#include <string>

constexpr int stack_size = 10;
using Stack = std::array<int, stack_size>;

void add_stack(int value, Stack& stack, size_t& stack_counter);
void unstack(size_t& stack_counter);
int get_stack_top(const Stack& stack, const size_t& stack_counter);
void update_stack_top(int value, Stack& stack, const size_t& stack_counter);
bool is_stack_empty(const size_t& stack_counter);
std::size_t get_stack_size(const size_t& stack_counter);
void empty_stack(size_t& stack_counter);
#endif //TABLEAU_ET_EXCEPTION_STACK_H
