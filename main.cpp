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

int main () {
    const int max_size = 10;
    int choice = 0;
    array<int,max_size> stack = {};
    do {
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
        display();
    } while (choice != 0);

}