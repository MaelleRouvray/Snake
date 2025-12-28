/**
 * @file test_collision.cpp
 * @brief Tests des collisions du serpent durant la partie de jeu 
 * @author Maelle et Coline 
 */



#include <catch2/catch_test_macros.hpp>
#include "game.h"
#include "snake.h"
#include "board.h"


TEST_CASE( "Collision sur un des boards", "[col_board]"){
    Board board; 

    SECTION( "Pas de collision"){
        Snake snake(13,7); 
        bool col = collisions(snake, board); 
        REQUIRE(col == false);
    }

    SECTION( "collision à gauche"){
        Snake snake(-1,9); 
        REQUIRE(collisions(snake,board) == true); 
    }

    SECTION( "collision à droite"){
        Snake snake(20,8); 
        REQUIRE(collisions(snake, board) == true); 
    }

    SECTION( "Collision en haut"){
        Snake snake(5,-1); 
        REQUIRE(collisions(snake,board) == true); 
    }

    SECTION( "Collision en bas"){
        Snake snake(12, 15); 
        REQUIRE(collisions(snake, board) == true); 
    }
}

TEST_CASE( "Collision sur le serpent lui-même", "[col_snake]"){
    Board board; 

    Snake snake(5,10); 

    snake.set_direction(1,0); // vers la droite 
    snake.grandir(); 
    snake.deplace(); 

    snake.grandir(); 
    snake.deplace(); 

    snake.grandir();
    snake.deplace(); 

    snake.grandir();
    snake.deplace(); 
    
    snake.set_direction(0,-1); // vers le haut
    snake.deplace(); 

    snake.set_direction(-1,0); //vers la gauche
    snake.deplace(); 

    snake.set_direction(0,1); //vers le bas 
    snake.deplace(); 

    REQUIRE(collisions(snake, board) == true); 
}