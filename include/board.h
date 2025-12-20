#ifndef BOARD_H
#define BOARD_H


#include "snake.h"
#include "food.h"

#include <array>
#include <utility>
#include <iostream>
#include <random>
using namespace std;


/** 
 * @brief hauteur du plateau 
 */
constexpr int N = 20; 
/** 
 * @brief largeur du plateau 
 */
constexpr int M = 15; 

/** 
 * @class Board 
 * 
 * @brief représentation du plateau de jeu
 * 
 * faire apparaitre un plateau avec un serpent et une nourriture 
 */
class Board {
    private:
    int length;
    int width;



    /** 
     * @brief énumère les différents éléments qui peuvent être trouvé sur le plateau 
     */
    enum class Element { 
        FOOD,     /*!< représente la nourriture */
        SERPENT,    /*!< représente le corps du serpent */
        TETE,       /*!< représente la tête du serpent */
        VIDE        /*!< représente une case vide */
    };



    /** 
     * @brief associe des charactères aux éléments du plateau 
     */
    const char cb = '.';       /*!< caractère pour la case vide */
    const char cn = 'o';       /*!< caractère pour lle corps du serpent */
    const char x = '*';        /*!< caractère pour la nourriture */
    const char triangle = '^'; /*!< caractère pour la tête du serpent */

    /** @brief plateau de jeu */
    using Plateau = std::array<std::array<Element, M>, N>;
    Plateau plateau; 


    /** 
     * @fn char get_char_from_element(Element element) const;
     * @brief lien entre énumération et les charactères 
     * 
     * associe à une valeur d'énumération le charactère d'affichage correspondant 
     * 
     * @param element l'élément du plateau 
     * @return char le charactère associé à l'élément  
     */
    char get_char_from_element(Element element) const; 


    public:
    /**
     * @fn Board()
     * @brief constructeur de la classe Board
     *
     * @return plateau vide de la bonne taille
     */
    Board(); 


    /** 
     *@fn int get_length()
     *@brief accesseur de la longueur du plateau
     */
     int get_length(); 

     /** 
     *@fn int get_width()
     *@brief accesseur de la largeur du plateau
     */
     int get_width(); 


    /**
     * @fn void initialisation_plateau()
     * @brief initialise le plateau avec des cases vides
     */
    void initialisation_plateau(); 


    /**
     * @fn void affiche_plateau() const
     * @brief affiche le plateau de jeu 
     */
    void affiche_plateau() const; 

    /**
     * @fn void dessine_snake(const Snake& snake)
     * @brief ajoute le serpent sur le plateau
     *
     * place la tête (^) et le corps (o) du serpent 
     *
     * @param snake corps du snake (constante)
     */
    void dessine_snake(const Snake& snake);
    
    
    /**
     * @fn void dessine_food(const Food& food)
     * @brief ajoute la nourriture sur le plateau 
     *
     * @param food coordonnées de la nourriture (constante)
     */
    void dessine_food(const Food& food); 
    

};



#endif