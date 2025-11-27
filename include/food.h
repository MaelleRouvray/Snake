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
    Food(std::pair<int,int> a = {0,0}); 

    /* accesseur */
    std::pair<int,int> get_food() const;

    /*génère les coordonnées de la nouriture*/
    std::pair<int,int> generate_food(const Snake snake); 

    /*nouvelle nouriture*/
    std::pair<int,int> new_food(const Snake snake); 

};


#endif