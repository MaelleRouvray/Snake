#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Snake {
    private:
    std::vector<std::pair<int,int>> corps; /* vecteur où chaque composante est un couple (x,y) */
    std::pair<int,int> direction; /*direction est un couple (dx,dy), 
    directions possibles : (1,0):droite, (-1,0):gauche, (0,1):bas, (0,-1):haut */
    bool grandit_apres; /* booléen qui indique si le serpent grandit au prochain move */

    public:
    /*constructeur :*/
    Snake(int x,int y);

    /*accéder au corps du snake*/
    const std::vector<std::pair<int,int>> get_snake() const;

    /* croisssance*/
    void grandir();

    /* déplacement */
    void set_direction(int dx,int dy);
    void deplace();

    /*collision du snake sur lui même */
    bool collision();
};




#endif