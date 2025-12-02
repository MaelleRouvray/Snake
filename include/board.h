#ifndef BOARD_H
#define BOARD_H


#include "snake.h"
#include "food.h"

#include <array>
#include <utility>
#include <iostream>
#include <random>
using namespace std;


constexpr int N = 10; 
constexpr int M = 10; 

class Board {
    private:
    int length;
    int width;

    // Enum pour les éléments
    enum class Element { ETOILE, SERPENT, TETE, VIDE };

    // Caractères associés aux éléments
    const char cb = '.';       // case vide
    const char cn = 'o';       // corps du serpent
    const char x = '*';        // étoile
    const char triangle = '^'; // tête du serpent

    using Plateau = std::array<std::array<Element, M>, N>;
    Plateau plateau; 

    char get_char_from_element(Element element) const; 


    public:
    // constructeur
    Board(); 


    //methodes: 
    void initialisation_plateau(); 

    void affiche_plateau() const; 


    void dessine_snake(const Snake& snake);
    
    
    void dessine_food(const Food& food); 
    

};



#endif