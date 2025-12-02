// #include <SFML/Graphics.hpp>
//#include < C:/Users/maell/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2/include/SFML/Graphics.hpp>

#include <iostream>
#include "snake.h"
#include "food.h"
#include "board.h"


int main() {
    Plateau plateau;
    Snake snake (5,5);

    Food food; 
    food.generate_food(snake); 
 

    initialisation_plateau(plateau);

    dessine_snake(snake, plateau);
    dessine_food(snake, food, plateau); 
    affiche_plateau(plateau);

    snake.set_direction(1,0); // vers la droite
    snake.deplace();

    dessine_snake(snake, plateau);
    affiche_plateau(plateau);

    snake.set_direction(1,0); // vers la droite
    snake.deplace();

    dessine_snake(snake, plateau);
    affiche_plateau(plateau);


    return 0;
}