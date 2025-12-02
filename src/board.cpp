#include "board.h"
#include "snake.h"
#include "food.h"

//constructeur
Board::Board()  {
    initialisation_plateau(); 
}


char Board::get_char_from_element(Element element) const{
    switch (element) {
        case Element::VIDE: return cb; 
        case Element::SERPENT: return cn; 
        case Element::ETOILE: return x; 
        case Element::TETE: return triangle; 
    }
}

void Board::initialisation_plateau(){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            plateau[i][j] = Element::VIDE;
        }
    }
}


void Board::affiche_plateau() const {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << get_char_from_element(plateau[i][j]); 
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void Board::dessine_snake(const Snake& snake){
    const auto& corps = snake.get_snake();
    if (!corps.empty()) {
        plateau[corps.front().second][corps.front().first] = Element::TETE; // tête
        for (size_t i = 1; i < corps.size(); ++i) {
            plateau[corps[i].second][corps[i].first] = Element::SERPENT; // corps
        }
    }
}


void Board::dessine_food(const Food& food){
    auto pos = food.get_food(); 
    plateau[pos.second][pos.first] = Element::ETOILE; 
}
