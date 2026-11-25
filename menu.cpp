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
            case program_stop_nbr: break;
            case stack_nbr: {
                try {
                    push(get_input("Valeur : "), stack, stack_counter);
                    std::cout << "Valeur empilee.\n";
                } catch (const std::exception& e) {
                    std::cout << "Erreur : " << e.what() << "\n";
                }

                break;
            }
            case unstack_nbr: {
                try {
                    int stack_top = top(stack, stack_counter);
                    pop(stack_counter); // Can't return the integer given the instruction, so use a top instead
                    std::cout << "Valeur retiree : " << stack_top << "\n";
                } catch (const std::exception& e) {
                    std::cout << "Erreur : " << e.what() << "\n"; //Return a top error instead of a pop error TODO
                }

                break;
            }
            case display_top_nbr: {
                try {
                    std::cout << "Sommet : " << top(stack, stack_counter) << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Erreur : " << e.what() << "\n";
                }

                break;
            }
            case update_top_nbr: {
                try {
                    top(get_input("Valeur de remplacement : "), stack, stack_counter);
                    std::cout << "Valeur remplacée.\n";
                } catch (const std::exception& e) {
                    std::cout << "Erreur : " << e.what() << "\n";
                }

                break;
            }
            case check_empty_nbr: {
                std::cout << (empty(stack_counter) ? "La pile est vide." : "La pile n'est pas vice.") << std::endl;
                break;
            }
            case display_value_nbr: {
                std::cout << "Nombre de valeurs : " << size(stack_counter) << std::endl;
                break;
            }
            case empty_stack_nbr: {
                clear(stack_counter);
                std::cout << "Pile vidée" << std::endl;
                break;
            }
            case display_stack_nbr: {
                display_stack(stack_counter, stack);
                break;
            }
            default:
                std::cout << "Valeur invalide" << std::endl;
                break;
        }
    } while (menu_choice != program_stop_nbr);
    std::cout << "Fin de programme.\n";
}
