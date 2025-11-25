#include "snake.h"

// constructeur (on initialise avec la tete)
Snake::Snake(int x, int y) {
    corps.push_back({x,y});
    direction = {1,0};
    grandit_apres = false;
}

// accéder au corps du snake
std::vector<std::pair<int,int>> Snake::get_snake(){
    return corps;
}


// nouvelle direction
void Snake::set_direction(int dx,int dy){
    direction ={dx,dy};
}

// déplacement du Snake
void Snake::deplace(){
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
    for (size_t i=0;i < corps.size();i++){
        if (corps[i]==tete){
            return true;
        }
        return false;
    }
}