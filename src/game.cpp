#include "game.h"
#include "snake.h"
#include "board.h"


void get_command(Snake snake){
    /*On récupère les commandes clavier*/
    char lettre;
    cout << "Choisir une direction avec une lettre parmi (k,o,l,m) ";
    cin >> lettre ;
    if (lettre == k){
        //gauche
        snake.set_direction(-1,0) ;
    }
    else if (lettre == m){
        //droite
        snake.set_direction(1,0) ;
    }
    else if (lettre == o){
        //haut
        snake.set_direction(0,1) ;
    }
    else if (lettre == l){
        //bas
        snake.set_direction(0,-1) ;
    }
    else {
        cout << "Choisir une direction avec une lettre parmi () ";
        cin >> lettre ;
    }
}

// collision du snake sur lui meme et avec le mur
bool collisions(Snake snake, Board board){
    bool col_snake_sur_snake = snake.collision();
    bool col_snake_sur_bord = false;

    std::pair<int,int> tete = snake.corps.front();
    if (0 <= tete.first <= board.length && 0 <= tete.second <= board.width){
        col_snake_sur_bord = true;
    }

    if (col_snake_sur_snake || col_snake_sur_bord){
        return true;
    }
    return false;
}


void run(Snake snake,Board board){
    bool collision = collisions(snake,board);
    //new_food()
    while (collision = false){
        get_command(snake);
        snake.set_direction();
        snake.deplace();
        collision = collisions(snake,board);
        //si mange food -> grandir 
    }
}
