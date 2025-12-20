#include "game.h"
#include "snake.h"
#include "board.h"
#include "food.h"

using namespace std; 


pair<int, int> get_command(Snake snake){
    /*On récupère les commandes clavier*/
    pair <int, int> direction = {0,0}; 
    char lettre;
    cout << "Choisir une direction avec une lettre parmi (k,o,l,m) ";
    cin >> lettre ;
    if (lettre == 'k'){
        //gauche
        direction = {-1,0} ;
    }  
    else if (lettre == 'm'){
        //droite
        direction = {1,0} ;
    }
    else if (lettre == 'o'){
        //haut
        direction = {0,-1} ;
    }
    else if (lettre == 'l'){
        //bas
        direction = {0,1} ;
    }
    else {
        cout << "Choisir une direction avec une lettre parmi () ";
        cin >> lettre ;
    }
    
    return direction; 
}

// collision du snake sur lui meme et avec le mur
bool collisions(Snake snake, Board board){
    bool col_snake_sur_snake = snake.collision();
    bool col_snake_sur_bord = false;

    auto corps = snake.get_snake(); 
    std::pair<int,int> tete = corps.front();
    int x = tete.first; 
    int y = tete.second;
    int largeur = board.get_width(); 
    int longueur = board.get_length();
    if (x < 0 || x >= largeur || y < 0 || y >= longueur){
        col_snake_sur_bord = true;
    }

    if (col_snake_sur_snake || col_snake_sur_bord){
        return true;
    }
    return false;
}


// void run(Snake snake,Board board){
//     bool collision = collisions(snake,board);
//     //new_food()
//     while (collision = false){
//         pair<int,int> direction = get_command(snake);

//         int x = direction.first ; 
//         int y = direction.second ;
//         snake.set_direction(x,y);

//         snake.deplace();
//         collision = collisions(snake,board);
//         //si mange food -> grandir 
//     }
// }


void run(Snake& snake,Board& board, Food& food){


    board.initialisation_plateau();
    board.dessine_food(food);
    board.dessine_snake(snake);
    board.affiche_plateau();

    bool collision = collisions(snake,board);
    //new_food()
    while (collision == false){
        pair<int,int> direction = get_command(snake);

        int x = direction.first ; 
        int y = direction.second ;
        snake.set_direction(x,y);

        snake.deplace();

        auto corps = snake.get_snake(); 
        std::pair<int,int> tete = corps.front();
        int u = tete.first; 
        int v = tete.second;
        std::pair<int,int> pom = food.get_food();
        int f = pom.first; 
        int g = pom.second; 
        if (u == f && v == g){
            snake.grandir(); 
            food.new_food(snake); 
        }

        collision = collisions(snake,board);

        if (collision == false) {
            board.initialisation_plateau(); 
            board.dessine_food(food);
            board.dessine_snake(snake);
            board.affiche_plateau();

        }
    }
    std::cout << "T'es trop nul ! "; 
}