/**
 * @file game.h
 * 
 * @author Maelle et Coline 
 * @version 0.1 
 */



#ifndef GAME_H
#define GAME_H


#include "snake.h"
#include "food.h"
#include "board.h"

#include <array>
#include <utility>
#include <iostream>
#include <random>
using namespace std;


/**
 * @fn pair<int, int> get_command(Snake snake)
 * @brief attribut aux touches claviers des commandes 
 *
 * * attribution d'une direction pour les lettre "k","l","m","o".
 * Ne sert que pour le jeu dans la cosole sans l'interface graphique  
 *
 * @param snake corps du serpent 
 * @return direction: un couple désignant la direction du serpent. 
 */
pair<int, int> get_command(Snake snake);

/**
 * @fn bool collisions(Snake snake,Board board)
 * @brief collision du snake sur lui-même ou sur les bords du plateau
 * 
 * @param snake corps du serpent 
 * @param board plateau 
 * @return true s'il y a collision, false sinon
 */
bool collisions(Snake snake,Board board);

/**
 * @fn void run(Snake snake,Board board);
 * @brief partie de jeu 
 * 
 * * Ne sert que pour le jeu dans la console sans l'interface graphique 
 *
 * @param snake corps du serpent 
 * @param board plateau
 * @param food nourriture 
 */
void run(Snake& snake,Board& board, Food& food);


#endif