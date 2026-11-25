#include "menu.h"
#include "stack.h"

#include <iostream>
#include<iomanip>

void display_stack(size_t i, Stack& stack) {
    if (i == 0) {
        std::cout << "Stack vide" << std::endl;
    } else if (i == 1) {
        std::cout << "Sommet / Fond -> " << stack[i - 1] << std::endl;
    } else {
        std::cout << "Sommet -> " << stack[i - 1] << std::endl;
        for (i -= 1;i > 1; --i) {
            std::cout << std::setw(11) << stack[i - 1] << std::endl;
        }
        std::cout << "Fond   -> " << stack[0] << std::endl;
    }
}

void display_menu() {
    std::cout << "1 - Empiler" << std::endl;
    std::cout << "2 - Depiler" << std::endl;
    std::cout << "3 - Consulter le sommet" << std::endl;
    std::cout << "4 - Modifier l'element au sommet" << std::endl;
    std::cout << "5 - Verifier si la pile est vide" << std::endl;
    std::cout << "6 - Afficher le nombre de valeurs" << std::endl;
    std::cout << "7 - Vider la pile" << std::endl;
    std::cout << "8 - Afficher toute la pile" << std::endl;
    std::cout << "0 - Quitter" << std::endl;
}

int get_input(const char* const str) {
    int input;
    std::cout << str;
    std::cin >> input;
    return input;
}

void menu() {
    constexpr int program_stop_nbr = 0;
    constexpr int stack_nbr = 1;
    constexpr int unstack_nbr = 2;
    constexpr int display_top_nbr = 3;
    constexpr int update_top_nbr = 4;
    constexpr int check_empty_nbr = 5;
    constexpr int display_value_nbr = 6;
    constexpr int empty_stack_nbr = 7;
    constexpr int display_stack_nbr = 8;

    Stack stack {};
    std::size_t stack_counter = 0;

    int menu_choice = 0;
    do {
        display_menu();
        menu_choice = get_input("Votre choix : ");

        switch (menu_choice) {
            case stack_nbr: {
                add_stack(get_input("Valeur : "), stack, stack_counter);
                std::cout << "Valeur empilee." << std::endl;
                break;
            }
            case unstack_nbr: {
                unstack(stack_counter);
                std::cout << "Valeur retiree : " << stack[stack_counter] << std::endl;
                break;
            }
            case display_top_nbr: {
                std::cout << "Sommet : " << get_stack_top(stack, stack_counter) << std::endl;
                break;
            }
            case update_top_nbr: {
                update_stack_top(get_input("Valeur de remplacement : "), stack, stack_counter);
                std::cout << "Valeur remplacée." << std::endl;
                break;
            }
            case check_empty_nbr: {
                std::cout << (is_stack_empty(stack_counter) ? "La pile est vide." : "La pile n'est pas vice.") << std::endl;
                break;
            }
            case display_value_nbr: {
                std::cout << "Nombre de valeurs : " << get_stack_size(stack_counter) << std::endl;
                break;
            }
            case empty_stack_nbr: {
                empty_stack(stack_counter);
                std::cout << "Pile vidée" << std::endl;
                break;
            }
            case display_stack_nbr: {
                display_stack(stack_counter, stack);
                break;
            }
            default:
                //TODO
                break;
        }
    } while (menu_choice != program_stop_nbr);
}
