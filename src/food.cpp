
#include "food.h"
#include "snake.h"


std :: mt19937 gen(42);

Food::Food(std::pair<int, int> a) : food(a) {}

std::pair<int,int> Food::get_food() const{
    return food;
}

std::pair<int,int> Food::generate_food(const Snake& snake){

    int width = 10; 
    int length =10; 
     
    std::uniform_int_distribution<int> distX(0,width -1); 
    std::uniform_int_distribution<int> distY(0,length -1); 

    int x = distX(gen);
    int y = distY(gen);
    std::pair<int,int> food = {x,y}; 

    //verifie que la nouriture n'est pas sur le snake//
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


std::pair<int,int> Food::new_food(const Snake& snake){
    food = generate_food(snake);
    // std::vector<std::pair<int,int>> corps = snake.get_snake(); 
    // if (food == corps.front()){
    //     food = generate_food(snake); /*faire grandir le snake*/
    // }
    return food;
}