

#include <catch2/catch_test_macros.hpp>
#include "snake.h"


/**
 * @brief test de Snake::Snake(int x, int y) 
 * Test le constructeur de la classe Snake
 * Vérifie l'initialisation du serpent, 
 * que la direction par default soit bien (0,0)
 * et que le booléen grandit_après soit faux 
 */

 TEST_CASE( "Constructeur du snake", "[snake]"){
    int x = 5; 
    int y = 10; 
    
    Snake snake(x,y); 

    SECTION( "Initialisation du serpent"){
        auto corps = snake.get_snake(); 

        /*Le corps est de taille 1*/
        REQUIRE(corps.size() == 1); 

        /*les coordonnées initiales sont les bonnes*/
        REQUIRE(corps[0].first == x); 
        REQUIRE(corps[0].second == y); 

    }

    SECTION( "Initialisation de la direction"){
        auto dir = snake.get_direction(); 
        
        /*La direction est bien à {0,0}*/
        REQUIRE(dir.first == 0); 
        REQUIRE(dir.second == 0); 
    }

    SECTION( "Croissance du serpent"){
        bool grandit = snake.get_grandit_apres(); 

        REQUIRE(grandit == false); 
    }
 }

 TEST_CASE( "test de la méthode grandir()", "[grandir]"){
    Snake snake(5,10); 
    snake.grandir();

    REQUIRE(snake.get_grandit_apres() == true); 
 }
