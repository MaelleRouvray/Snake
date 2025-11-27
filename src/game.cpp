#include "game.h"
#include "snake.h"

.... game(Snake snake){
    /*On récupère les commandes clavier*/
    char lettre;
    cout >> "Choisir une direction avec une lettre parmi (k,o,l,m) ";
    cin << lettre ;
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
        cout >> "Choisir une direction avec une lettre parmi () ";
        cin << lettre ;
    }

}

