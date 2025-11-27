
#include "food.h"
#include "snake.h"


Food::Food(std::pair<int, int> a) : food(a) {}

std::pair<int,int> Food::get_food() const{
    return food;
}

std::pair<int,int> Food::generate_food(Snake snake){
    std :: mt19937 gen(42); 
    // valeurs à modifier
    int a = 30; 
    int b = 20; /* taille du plateau */
    std::uniform_int_distribution<int> distX(0,a); 
    std::uniform_int_distribution<int> distY(0,b); 

    int x = distX(gen);
    int y = distY(gen);
    std::pair<int,int> food = {x,y}; 

    /*verifie que la nouriture n'est pas sur le snake*/
    int i = 0;
    std::vector<std::pair<int,int>> corps = snake.get_snake(); 

    while (i < corps.size()){
        
        if (food == corps[i]){
            int x = distX(gen); 
            int y = distY(gen);  
            i=0; 
            std::pair<int,int> food = {x,y}; 
        }
        else{
            i++; 
        }
    }

    return food; 
}


std::pair<int,int> Food::new_food(Snake snake){
    food = generate_food(snake);
    // std::vector<std::pair<int,int>> corps = snake.get_snake(); 
    // if (food == corps.front()){
    //     food = generate_food(snake); /*faire grandir le snake*/
    // }
    return food;
}