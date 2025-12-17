#include "snake.h"

// constructeur (on initialise avec la tete)
Snake::Snake(int x, int y) {
    corps.push_back({x,y});
    direction = {0,0};
    grandit_apres = false;
}

// accéder au corps du snake
const std::vector<std::pair<int,int>> Snake::get_snake() const{
    return corps;
}

// accéder à la direction
const std::pair<int,int> Snake::get_direction() const{
    return direction;
}

void Snake::grandir(){
    grandit_apres = true ;
}

bool Snake::get_grandit_apres() const{
    return grandit_apres; 
}

// nouvelle direction
void Snake::set_direction(int dx,int dy){
    direction ={dx,dy};
}

// déplacement du Snake
void Snake::deplace(){
    if (direction.first == 0 && direction.second == 0) {
        return; // ne bouge pas tant qu'aucune direction n'est donnée
    }
    std::pair<int,int> new_tete = {corps.front().first + direction.first,corps.front().second + direction.second};
    corps.insert(corps.begin(),new_tete);
    if (grandit_apres){
        grandit_apres=false; // on garde la queue 
    }
    else{
        corps.pop_back(); // on enlève la queue pour que corps ai la bonne taille après le déplacement
    }
}

//vérifie collision du snake sur lui meme
bool Snake::collision(){
    std::pair<int,int> tete = corps.front();
    for (size_t i=1;i < corps.size();i++){  // i=0 avant
        if (corps[i]==tete){
            return true;
        }
    }
    return false;
}