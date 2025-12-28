////////////////////////
/// SANS SFML        ///
////////////////////////

// #include <thread>  
// #include <chrono>

// #include "snake.h"
// #include "food.h"
// #include "board.h"
// #include "game.h"
// using namespace std; 



// int main() {

//     Board board; 
//     // board.initialisation_plateau();

//     Snake snake (5,5);

//     Food food; 
//     food.new_food(snake);
//     snake.set_direction(0,1); 

//     run(snake, board, food); 

//     return 0;
// }



////////////////////////
/// AVEC SFML        ///
////////////////////////


#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"
#include "board.h"
#include "game.h"
using namespace std; 

int main(){
    sf::RenderWindow window (sf::VideoMode({800,600}), "Snake avec SFML");  /*grille 20x15*/
    window.setFramerateLimit(60);
    sf::Clock clock ;
    float delay = 0.2f ;  /*bouge toutes les 0.2s*/

    sf::Font font("Fonts/arial.ttf") ;
    sf::Text gameoverText(font) ;
    gameoverText.setString("Game Over");
    gameoverText.setCharacterSize(36);
    gameoverText.setPosition(sf::Vector2f(7*40,6*40));

    int score = 0 ;
    sf::Text scoreText(font);
    scoreText.setCharacterSize(24);
    

    Snake snake(10,7);
    Food food ;
    Board board ;

    food.new_food(snake, board); 


    bool debut = false ;
    bool collision = false ;
  
    
    while (window.isOpen()){
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            /*entrées clavier*/
            
            if (!collision){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                    snake.set_direction(-1,0);
                    debut = true ;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                    snake.set_direction(1,0);
                    debut = true ;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
                    snake.set_direction(0,-1);
                    debut = true ;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
                    snake.set_direction(0,1);
                    debut = true ;
                }
            }

        }

    
        if (!collision && debut && clock.getElapsedTime().asSeconds() > delay){
            if (snake.get_direction() != std::pair<int,int> (0,0)) {  //snake attend une commande clavier pour commencer a bouger
                snake.deplace();
            }
            clock.restart(); 

            if(collisions(snake,board)){
                collision = true ;
            }


            auto corps = snake.get_snake() ;
            auto tete = corps.front();
            auto coord_food = food.get_food();

            if(tete == coord_food){     /*si le serpent mange la nourriture alors il grandir puis new food*/
                snake.grandir();
                food.new_food(snake, board);
                score += 1;
            }
        }



        /*rendu graphique*/
        window.clear(sf::Color::Black);
        if (!collision){
            /*dessin du serpent*/
            auto corps = snake.get_snake() ;
            for (size_t i = 0;i < corps.size(); i++){
                sf::RectangleShape rect(sf::Vector2f(40, 40)); /*taille d'une case*/
                rect.setPosition(sf::Vector2f(corps[i].first * 40, corps[i].second * 40));
                if (i == 0){
                    rect.setFillColor(sf::Color::Yellow) ; /*tete du serpent*/
                }
                else {
                    rect.setFillColor(sf::Color::Green) ; /*reste du corps*/
                }
                window.draw(rect) ;
            }

            /*dessin de la nourriture*/
            auto coord_food = food.get_food();
            sf::CircleShape food_circle(20.f);
            food_circle.setPosition(sf::Vector2f(coord_food.first*40, coord_food.second*40));
            food_circle.setFillColor(sf::Color::Red);
            window.draw(food_circle);

            scoreText.setString("Score : " + to_string(score));
            window.draw(scoreText);
        
        }

        else {
            window.draw(gameoverText);
            scoreText.setPosition(sf::Vector2f(8*40,8*40)) ; 
            window.draw(scoreText);
        }

        window.display();
    }

    return 0 ;
}
