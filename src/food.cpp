
#include "food.h"
#include "snake.h"

Food::Food(std::pair<int, int> a = {0,0}) : food(a) {}



std::pair<int , int> Food::generate_food(Snake snake){
    std :: mt19937 gen(42); 
    int a =; 
    int b =; /* taille du plateau */
    int x = std::uniform_int_distribution<int>(0,a); 
    int y = std::uniform_int_distribution<int>(0,b); 
    std::pair<int,int> food = {x,y}; 

    /*verifié que la nouriture n'est pas sur le snake*/

    int i = 0;
    std::vector<std::pair<int,int>> corps = get_snake(); 
    while (i<corps.size()){
        
        if (food==Snake::corps[i]){
            int x = std::uniform_int_distribution<int>(0,a); 
            int y = std::uniform_int_distribution<int>(0,b);  
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
    corps = get_snake(); 
    if (food == corps.front()){
        food = generate_food(Snake snake); /*faire grandir ke snake*/
    }
}