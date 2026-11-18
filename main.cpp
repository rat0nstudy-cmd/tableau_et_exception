#include<iostream>
#include<array>

using namespace std;

int add_stack();
int pop_stack();
int consult_summit();
int update_summit();
bool stack_is_empty();
int display_nb_val();
int empty_stack();
int diplay_stack();
string display();

void display_choices() {
    cout << "1 - Empiler" << endl;
    cout << "2 - Dépiler" << endl;
    cout << "3 - Consulter le sommet" << endl;
    cout << "4 - Modifier l'élément au sommet" << endl;
    cout << "5 - Vérifier si la pile est vide" << endl;
    cout << "6 - Afficher le nombre de valeurs" << endl;
    cout << "7 - Vider la pile" << endl;
    cout << "8 - Afficher toute la pile" << endl;
    cout << "0 - Quitter" << endl;
}

int main () {
    const int max_size = 10;
    int choice = 0;
    array<int,max_size> stack = {};

    cout << "Ce programme permet de manipuler une pile d'entiers." << endl;

    do {
        display_choices();

        cout << "Votre choix : ";
        cin >> choice;

        switch (choice) {
            case 1 : add_stack(); break;
            case 2 : pop_stack(); break;
            case 3 : consult_summit(); break;
            case 4 : update_summit(); break;
            case 5 : stack_is_empty(); break;
            case 6 : display_nb_val(); break;
            case 7 : empty_stack(); break;
            case 8 : diplay_stack(); break;
        }
    } while (choice != 0);

}