
#include "food.h"
#include "snake.h"
#include <random>

using namespace std; 

std::random_device rd;
std::mt19937 gen(rd());

Food::Food(std::pair<int, int> a) : food(a) {}

pair<int,int> Food::get_food() const{
    return food;
}

pair<int,int> Food::generate_food(const Snake& snake){

    int width = 10; 
    int length =10; 
    const vector<pair<int,int>>& corps = snake.get_snake();
     
    uniform_int_distribution<int> distX(0,width -1); 
    uniform_int_distribution<int> distY(0,length -1); 

        // int x = distX(gen);
        // int y = distY(gen);
    pair<int,int> new_food; 
    bool collision = true; 

    //verifie que la nouriture n'est pas sur le snake/
    while (collision){

        new_food.first = distX(gen);
        new_food.second = distY(gen);

        collision = false; 

        for (const auto& segment : corps) {
            if (new_food == segment) {
                collision = true; 
                break; 
            }
        }
    }

    return new_food; 
}


pair<int,int> Food::new_food(const Snake& snake){
    food = generate_food(snake);
    return food;
}