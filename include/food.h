#ifndef FOOD_H
#define FOOD_H


#include <iostream>
#include <random>
using namespace std;


class Food {
    /*
    * faire apparaitre de façon aléatoire sur la grille une pomme et des qu'elle est mangé, faire apparaitre une nouvelle
    */

    private : 
    std::pair<int,int> food; /* coordonées de la nouriture */
    
    public: 

    /*constructeur */
    Food(std::pair<int, int>); 

    /*génère les coordonnées de la nouriture*/
    std::pair<int,int> generate_food(); 

    /*nouvelle nouriture*/
    std::pair<int,int> new_food(); 

}


#endif