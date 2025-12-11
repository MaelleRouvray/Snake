// #include <SFML/Graphics.hpp>
// #include <C:/Users/maell/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2/include/SFML/Graphics.hpp>

#include <iostream>

#include "snake.h"
#include "food.h"
#include "board.h"
using namespace std; 


int main() {

    Board board; 
    board.initialisation_plateau();

    Snake snake (5,5);

    Food food; 
    food.new_food(snake);


    
    board.dessine_food(food); 
    board.dessine_snake(snake);
    board.affiche_plateau();

    snake.set_direction(1,0); // vers la droite
    snake.deplace();

    board.initialisation_plateau();
    board.dessine_food(food);
    board.dessine_snake(snake);
    board.affiche_plateau();

    snake.set_direction(1,0); // vers la droite
    snake.deplace();

    board.initialisation_plateau();
    board.dessine_food(food);
    board.dessine_snake(snake);
    board.affiche_plateau();


    return 0;
}