#ifndef FOOD_H
#define FOOD_H


#include <iostream>
#include <random>
using namespace std;

<<<<<<< HEAD
/** 
 * @class Food 
 * 
 * @brief Distribution aléatoire d'une pomme sur la grille
 * 
 * faire apparaitre de façon aléatoire sur la grille une pomme et des qu'elle est mangé, faire apparaitre une nouvelle
*/
=======
class Snake; 
>>>>>>> develop-coline


class Food {

    private : 
    std::pair<int,int> food; /*!< coordonées de la nouriture */
    
    public: 

    /**
     * @fn 
     * 
     * @param 
     */
    Food(std::pair<int,int> a = {0,0}); 

    /* accesseur */
    std::pair<int,int> get_food() const;

    /*génère les coordonnées de la nouriture*/
    std::pair<int,int> generate_food(const Snake& snake); 

    /*nouvelle nouriture*/
    std::pair<int,int> new_food(const Snake& snake); 

};


#endif