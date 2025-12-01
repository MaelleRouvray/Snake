#ifndef FOOD_H
#define FOOD_H


#include <iostream>
#include <random>
using namespace std;


class Board {
    private:
    int length;
    int width;


    public:
    // constructeur
    Board(int a=0, int b=0); 
    
    // accesseur
    int get_length();
    int get_width();

    // affiche_plateau vide 
    void show_board();

    // ajoute snake sur le plateau 
    void add_snake();

    //ajoute food sur le plateau 
    void add_food();

};



#endif