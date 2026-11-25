#include "menu.h"
#include "stack.h"

#include <iostream>
#include<iomanip>

void display_stack(size_t i, const Stack& stack) {
    if (i == 0) {
        std::cout << "La pile est vide.\n";
        return;
    }
    if (i == 1) {
        std::cout << "Sommet / Fond -> " << stack[i - 1] << "\n";
        return;
    }


    std::cout << "Sommet -> " << stack[i - 1] << "\n";
    for (i -= 1;i > 1; --i) {
        std::cout << std::setw(11) << stack[i - 1] << "\n";
    }
    std::cout << "Fond   -> " << stack[0] << "\n";
}

void display_menu() {
    std::cout << "1 - Empiler\n";
    std::cout << "2 - Depiler\n";
    std::cout << "3 - Consulter le sommet\n";
    std::cout << "4 - Modifier l'element au sommet\n";
    std::cout << "5 - Verifier si la pile est vide\n";
    std::cout << "6 - Afficher le nombre de valeurs\n";
    std::cout << "7 - Vider la pile\n";
    std::cout << "8 - Afficher toute la pile\n";
    std::cout << "0 - Quitter\n";
}

int get_input(const char* text) {
    int input;
    std::cout << text;
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

        try {
            switch (menu_choice) {
                case program_stop_nbr: break;
                case stack_nbr: {
                    push(get_input("Valeur : "), stack, stack_counter);
                    std::cout << "Valeur empilee.\n";
                    break;
                }
                case unstack_nbr: {
                    int stack_top = 0;
                    if (!empty(stack_counter)) { //Force the error of type pop instead of top
                        stack_top = top(stack, stack_counter);
                    }
                    //Return a top error instead of a pop error
                    pop(stack_counter); // Can't return the integer given the instruction, so use a top instead
                    std::cout << "Valeur retiree : " << stack_top << "\n";

                    break;
                }
                case display_top_nbr: {
                    std::cout << "Sommet : " << top(stack, stack_counter) << "\n";
                    break;
                }
                case update_top_nbr: {
                    top(get_input("Valeur de remplacement : "), stack, stack_counter);
                    std::cout << "Valeur remplacée.\n";
                    break;
                }
                case check_empty_nbr: {
                    std::cout << (empty(stack_counter) ? "La pile est vide.\n" : "La pile n'est pas vide.\n");
                    break;
                }
                case display_value_nbr: {
                    std::cout << "Nombre de valeurs : " << size(stack_counter) << "\n";
                    break;
                }
                case empty_stack_nbr: {
                    clear(stack_counter);
                    std::cout << "Pile vidée\n";
                    break;
                }
                case display_stack_nbr: {
                    display_stack(stack_counter, stack);
                    break;
                }
                default:
                    std::cout << "Valeur invalide\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Erreur : " << e.what() << "\n";
        }
    } while (menu_choice != program_stop_nbr);
    std::cout << "Fin de programme.\n";
}
