/**
 *@file snake.h
 *@brief classe snake
 *@author maelle et coline 
 *@version 0.1
 */




#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include <utility>
using namespace std;



/** 
 * @class Snake
 * 
 * @brief Création du snake
 * 
 * Crée, déplace et vérifie les collisions du snake sur lui-même
*/

class Snake {
    private:
    std::vector<std::pair<int,int>> corps; /*!< vecteur où chaque composante est un couple (x,y) */
    std::pair<int,int> direction; /*!< direction est un couple (dx,dy),directions possibles : (1,0):droite, (-1,0):gauche, (0,1):bas, (0,-1):haut */
    bool grandit_apres; /*!< booléen qui indique si le serpent grandit au prochain move */

    public:
    
    /**
     * @fn Snake(int x,int y)
     * @brief Constructeur 
     * 
     * @param x Première coordonnée du snake de base composé d'un seul élément
     * @param y Deuxième coordonnée du snake de base composé d'un seul élément
     * 
     * @return snake consitué d'un élément de cordonnées (x,y) et la direction vers la droite
     */
    Snake(int x,int y);



    /**
     * @fn const std::vector<std::pair<int,int>> get_snake() const
     * @brief Accéder au corps du snake
     * 
     * @return corps , le corps du snake consitué de ses corrdonnées
     */
    const std::vector<std::pair<int,int>> get_snake() const;


    /**
     * @fn void grandir()
     * @brief Met le booléen grandit_apres à true 
     */
    void grandir();


    /**
     * @fn void set_direction(int dx,int dy);
     * @brief Définit la direction 
     * 
     * @param dx Direction à suivre suivant la première coordonnée
     * @param dy Direction à suivre suivant la deuxième coordonnée
     */
    void set_direction(int dx,int dy);



    /**
     * @fn void deplace()
     * @brief Déplace le snake
     */
    void deplace();


    /**
     * @fn bool collision()
     * @brief collision du snake sur lui-même
     * 
     * @return true si le snake se cogne contre lui-même, false sinon
     */
    bool collision();
};




#endif