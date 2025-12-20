// #include <SFML/Graphics.hpp>
// #include <C:/Users/maell/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2/include/SFML/Graphics.hpp>


///////////////////////
///INUTILE ?         //
///////////////////////

// #include <iostream>

// #include "snake.h"
// #include "food.h"
// #include "board.h"
// using namespace std; 


// int main() {

//     Board board; 
//     board.initialisation_plateau();

//     Snake snake (5,5);

//     Food food; 
//     food.new_food(snake);


    
//     board.dessine_food(food); 
//     board.dessine_snake(snake);
//     board.affiche_plateau();

//     snake.set_direction(1,0); // vers la droite
//     snake.deplace();

//     board.initialisation_plateau();
//     board.dessine_food(food);
//     board.dessine_snake(snake);
//     board.affiche_plateau();

//     snake.set_direction(1,0); // vers la droite
//     snake.deplace();

//     board.initialisation_plateau();
//     board.dessine_food(food);
//     board.dessine_snake(snake);
//     board.affiche_plateau();


//     return 0;
// }




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


#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"
#include "board.h"
#include "game.h"
using namespace std; 

int main(){
    //sf::RenderWindow window (sf::VideoMode({800,600}), "Snake avec SFML");  // grille 40x30
    sf::RenderWindow window (sf::VideoMode({400,300}), "Snake avec SFML"); // grille 20x15
    window.setFramerateLimit(60);
    sf::Clock clock ;
    float delay = 0.2f ;  // bouge toutes les 0.2s

    sf::Font font("Fonts/arial.ttf") ;
    sf::Text gameoverText(font) ;
    gameoverText.setString("Game Over");
    gameoverText.setCharacterSize(24);
    

    Snake snake(10,7);
    Food food ;
    Board board ;


    bool debut = false ;
    bool collision = false ;
    
    while (window.isOpen()){
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            //entrées clavier
            
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

            if(tete == coord_food){     // si serpent mange nourriture alors grandir puis new food
                snake.grandir();
                food.new_food(snake);
            }
            cout << collision ;
        }



        // rendu graphique
        window.clear(sf::Color::Black);
        if (!collision){
            // dessin serpent
            auto corps = snake.get_snake() ;
            for (size_t i = 0;i < corps.size(); i++){
                sf::RectangleShape rect(sf::Vector2f(20, 20)); //taille d'uen case
                rect.setPosition(sf::Vector2f(static_cast<float>(corps[i].first * 20), static_cast<float>(corps[i].second * 20)));
                if (i == 0){
                    rect.setFillColor(sf::Color::Yellow) ; // tete du serpent
                }
                else {
                    rect.setFillColor(sf::Color::Green) ; // reste du corps
                }
                window.draw(rect) ;
            }

            // dessin food
            auto coord_food = food.get_food();
            sf::CircleShape food_circle(10.f);
            food_circle.setPosition(sf::Vector2f(static_cast<float>(coord_food.first*20), static_cast<float>(coord_food.second*20)));
            food_circle.setFillColor(sf::Color::Red);
            window.draw(food_circle);
        
        }

        else {
            window.draw(gameoverText);
        }

        window.display();
    }

    return 0 ;
}