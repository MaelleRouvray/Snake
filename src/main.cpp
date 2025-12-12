// #include <SFML/Graphics.hpp>
// #include <C:/Users/maell/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2/include/SFML/Graphics.hpp>

#include <iostream>

#include <thread>  
#include <chrono>

#include "snake.h"
#include "food.h"
#include "board.h"
#include "game.h"
using namespace std; 



int main() {

    Board board; 
    // board.initialisation_plateau();

    Snake snake (5,5);

    Food food; 
    food.new_food(snake);
    snake.set_direction(0,1); 

    run(snake, board, food); 

    return 0;
}
    
    // board.dessine_food(food); 
    // board.dessine_snake(snake);
    // snake.set_direction(0,1); 

    // while (true){
    //     snake.deplace(); 

    //     board.initialisation_plateau(); 
    //     board.dessine_food(food);       
    //     board.dessine_snake(snake);

    //     board.affiche_plateau();

    //     std::this_thread::sleep_for(std::chrono::milliseconds(500));
        /*!< pour faire avancer le snake sur le même plateau, plus on mets un chiffre petit plus le serpent va vite*/

    // }
    
    // snake.deplace();

    // board.initialisation_plateau();
    // board.dessine_food(food);
    // board.dessine_snake(snake);
    // board.affiche_plateau();

    // snake.set_direction(1,0); // vers la droite
    // snake.deplace();

    // board.initialisation_plateau();
    // board.dessine_food(food);
    // board.dessine_snake(snake);
    // board.affiche_plateau();


