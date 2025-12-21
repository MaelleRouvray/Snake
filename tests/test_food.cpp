#include <catch2/catch_test_macros.hpp>
#include "food.h"
#include "snake.h"
#include "board.h"

/**
 * @test Food::Food(std::pair<int, int> a)
 * @brief Test du constructeur de la classe Food
 * * Vérifie l'initalisation par default de la position de la nourriture 
 * et le bon enregistrement des nouvelles coordonnées 
 */
 TEST_CASE( "Constructeur de la classe Food", "[food]"){

    SECTION( "Initialisation par défault"){
        Food food; 

        REQUIRE(food.get_food().first == 0); 
        REQUIRE(food.get_food().second == 0); 
    }

    SECTION( "stockage des nouvelles coordonnées"){

        std::pair<int,int> pos = {10,7}; 
        Food new_food(pos); 

        REQUIRE(new_food.get_food().first == 10); 
        REQUIRE(new_food.get_food().second == 7); 
    }
 }

/**
 * @test pair<int,int> Food::generate_food(const Snake& snake, const Board& board)
 * @brief Test de méthode de génération de nourriture 
 * * Vérifie que la nourriture est générée dans les dimmensions du plateau 
 * et qu'elle ne se situe pas sur le corps du serpent 
 */
 TEST_CASE( "Test de la génération de la nourriture", "[genere_food]"){
    Board board; 
    Snake snake(12,3); 
    Food food; 

    SECTION( "La nourriture est à l'intérieur du plateau"){
        for (int i = 0; i>50; i++){
            std::pair<int,int> pos = food.generate_food(snake, board); 
            REQUIRE(pos.first > 0); 
            REQUIRE(pos.first < board.get_width()); 
            REQUIRE(pos.second > 0); 
            REQUIRE(pos.second < board.get_length()); 
        }
    }
    SECTION( "Le nourrite n'est pas sur le serpent"){
        /*initialisation d'un serpent assez grand*/
        snake.set_direction(1,0); 
        snake.grandir(); 
        snake.deplace(); 
        snake.grandir(); 
        snake.deplace(); 

        auto corps = snake.get_snake(); 

        for (int i = 0; i<50; i++){
            std::pair<int,int> new_pos = food.generate_food(snake, board); 
            for (const auto& segment : corps){
                REQUIRE(!(segment == new_pos)); 
            }
        }
    }
 }
 