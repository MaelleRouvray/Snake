#include <catch2/catch_test_macros.hpp>
#include "food.h"
#include "snake.h"
#include "board.h"

/**
 * @test Board::Board()
 * @brief Test du constructeur de la classe Board 
 * * Vérifie que la largeur et la longueur du plateau soient bien initialisé 
 * et que ce dernier soit vide 
 */
 TEST_CASE( "Constructeur de la classe Board", "[board]"){
    Board board; 
    SECTION( "Dimensiosn du plateau"){
        REQUIRE(board.get_width() == 20); 
        REQUIRE(board.get_length() == 15); 
    }

    SECTION( "Initialisation du plateau vide"){
        bool plateau_vide = true; 
        for (int i = 0; i<15; i++){
            for (int j = 0; j<20; j++){
                if (board.case_vide(i,j)==false){
                    bool plateau_vide = false; 
                }
            }
        }
        REQUIRE(plateau_vide == true); 
    }
 }

 /**
  * @test void Board::dessine_snake(const Snake& snake) et void Board::dessine_food(const Food& food)
  * @brief Test la mise à jour du plateau 
  * * Vérifie que le serpent et la nourriture se dessinent bien sur le plateau
  */
  TEST_CASE( "Mise à jour du plateau", "[board_maj]"){
    Board board; 
    SECTION( "Dessin du serpent"){
        Snake snake(5,5); 

        board.dessine_snake(snake); 

        REQUIRE(board.case_tete(5,5) == true); 

        snake.set_direction(0,-1);
        snake.grandir(); 
        snake.deplace(); 
        
        snake.grandir(); 
        snake.deplace(); 

        auto corps = snake.get_snake(); 

        board.dessine_snake(snake); 

        for (size_t i = 0; i < corps.size(); ++i) {
            int x = corps[i].first;
            int y = corps[i].second;

            if (i == 0) {
                REQUIRE(board.case_tete(y, x) == true); 
            } else {
                REQUIRE(board.case_snake(y, x) == true);
            }
        }
    }
    SECTION( "Dessin de la nourriture"){
        std::pair<int,int> pos = {4,7}; 
        Food food(pos);
        board.dessine_food(food); 
        REQUIRE(board.case_food(7,4) == true); 
    }
  }

  