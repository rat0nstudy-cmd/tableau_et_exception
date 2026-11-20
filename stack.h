#ifndef TABLEAU_ET_EXCEPTION_STACK_H
#define TABLEAU_ET_EXCEPTION_STACK_H
#include <cstddef>
#include <array>

constexpr int stack_size = 10;
inline std::array<int, stack_size> stack {};
inline std::size_t stack_counter = 0;

void add_stack(int value);
int unstack();
int get_stack_top();
void update_stack_top(int value);
bool is_stack_empty();
std::size_t get_stack_size();
void empty_stack();
//TODO get_stack();

#endif //TABLEAU_ET_EXCEPTION_STACK_H
