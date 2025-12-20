#ifndef FOOD_H
#define FOOD_H


#include <iostream>
#include <random>
// #include "snake.h"
// #include "board.h"

class Board; 
class Snake; 

using namespace std;

/**
 * @class Food 
 * 
 * @brief Distribution aléatoire d'une pomme sur la grille
 * 
 * faire apparaitre de façon aléatoire sur la grille une pomme et des qu'elle est mangé, faire apparaitre une nouvelle
*/

class Food {

    private : 
    pair<int,int> food; /*!< coordonées de la nouriture */
    
    public: 

    /**
     * @fn Food(std::pair<int,int> a = {0,0})
     * @brief Constructeur pas defaut de la classe Food
     * 
     * Initialise les coordonées de la nourriture (par défaut a {0,0})
     * 
     * @param a une paire d'entier représentant les coordonnées de la nouriture 
     * @return coordonnée de la nourriture 
     */
    Food(pair<int,int> a = {0,0}); 



    /**
     * @fn pair<int,int> get_food() const
     * @brief Accéder à la nourriture 
     * 
     * @return pair<int,int> les coordonnées de la nourriture 
     */
    pair<int,int> get_food() const;



    /**
     * @fn pair<int,int> generate_food(const Snake& snake)
     * @brief génère une nourriture 
     * 
     * @param snake corps du serpent 
     * @return pair<int,int> coordonées de la nourriture 
     */
    pair<int,int> generate_food(const Snake& snake, const Board& board); 

    /**
     * @fn pair<int,int> new_food(const Snake& snake)
     * @brief génère une nouvelle nouriture lorsque l'autre a été mangé 
     * 
     * @param snake corps du serpent 
     * @return pair<int,int> coordonnées de la nouvelle nourriture 
     */
    pair<int,int> new_food(const Snake& snake, const Board& board); 

};


#endif