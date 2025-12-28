/**
 * @file test_snake.cpp
 * @brief Tests de la classe Snake
 * @author Maelle et Coline 
 */


#include <catch2/catch_test_macros.hpp>
#include "snake.h"


/**
 * @test Snake::Snake(int x, int y) 
 * @brief Test le constructeur de la classe Snake
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


/**
 * @test void Snake::grandir()
 * @brief Test la methode de croissance du serpent 
 * * Verifie que le booléen grandit_après est true après l'appel 
 */
 TEST_CASE( "Test de la croissance du serpent", "[grandir]"){
    Snake snake(5,10); 
    snake.grandir();

    REQUIRE(snake.get_grandit_apres() == true); 
 }

/**
 *@test void Snake::set_direction(int dx,int dy)
 * @brief Test de la direction du serpent 
 * *Vérifie que la direction est bien implémenter après: 
 * un changement de direction simple 
 * et plusieurs changements de directions
 */
 TEST_CASE( "Test de la direction du serpent", "[direction]"){
    Snake snake(5,10); 

    SECTION( "Changement de direction simple"){
        int x = -1; 
        int y = 0; 
        snake.set_direction(x,y); 

        std::pair <int,int> gauche = {x,y}; 

        REQUIRE(snake.get_direction() == gauche); 
    }

    SECTION( "Plusieurs changements de direction"){
        snake.set_direction(1,0); 
        std::pair<int,int> droite = {1,0}; 

        REQUIRE(snake.get_direction() == droite); 
        
        snake.set_direction(0,1); 
        std::pair<int,int> haut = {0,1}; 

        REQUIRE(snake.get_direction() == haut); 

        snake.set_direction(0,-1); 
        std::pair<int,int> bas = {0,-1}; 

        REQUIRE(snake.get_direction() == bas); 
    }
 }

/**
 * @test void Snake::deplace()
 * @brief Test du bon déplacement du serpent 
 * *Vérifie que le déplacement du serpent se fait correctement avec et sans croissance de ce dernier 
 */
 TEST_CASE( "Test du deplacement du serpent", "[deplacement]"){
    Snake snake(5,10); 

    SECTION( "Pas de déplacement"){
        snake.deplace(); 
        auto corps = snake.get_snake(); 

        REQUIRE(corps.size() == 1); 
        REQUIRE(corps[0].first == 5); 
        REQUIRE(corps[0].second == 10);
    }
    SECTION( "Déplacement sans croissance"){
        snake.set_direction(1,0); 
        snake.deplace(); 
        auto corps = snake.get_snake(); 
        
        REQUIRE(corps.size() == 1); 
        REQUIRE(corps[0].first == 6); 
        REQUIRE(corps[0].second == 10); 
    }

    SECTION( "Déplacement avec croissance"){
        snake.set_direction(0,1); 
        snake.grandir(); 

        REQUIRE(snake.get_grandit_apres() == true); 

        snake.deplace(); 

        auto corps = snake.get_snake(); 

        REQUIRE(corps.size() == 2); 
        REQUIRE(snake.get_grandit_apres() == false); 
        REQUIRE(corps[0].first == 5); 
        REQUIRE(corps[0].second == 11); 
        REQUIRE(corps[1].first == 5); 
        REQUIRE(corps[1].second == 10); 

        snake.deplace(); 

        auto new_corps = snake.get_snake(); 
        
        REQUIRE(new_corps.size() == 2); 
        REQUIRE(snake.get_grandit_apres() == false); 
        REQUIRE(new_corps[0].first == 5); 
        REQUIRE(new_corps[0].second == 12); 
        REQUIRE(new_corps[1].first == 5); 
        REQUIRE(new_corps[1].second == 11); 

    }
 }


 /**
  * @test bool Snake::collision()
  * @brief Test des collisions du seprent sur lui-même 
  * *Vérifie pour une collision simple et aussi en demi-tour 
  */
 TEST_CASE( "Test de collision sur lui_même", "[collision]"){
    Snake snake(5,10); 

    SECTION( "Pas de collision"){
        REQUIRE(snake.collision() == false); 
    }

    SECTION( "Collision sur son propre corps"){
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

        REQUIRE(snake.collision() == true); 
    }

    SECTION( "collision sur son propre corps en demi-tour"){
        snake.set_direction(1,0); // vers la droite 
        snake.grandir(); 
        snake.deplace(); 

        snake.grandir(); 
        snake.deplace(); 
        
        snake.set_direction(-1,0); 
        snake.deplace(); 

        REQUIRE(snake.collision()==true);
    }
 }
