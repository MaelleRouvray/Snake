
#include "food.h"
#include "snake.h"
#include "board.h"
#include <random>

using namespace std; 


static std::random_device rd;
static std::mt19937 gen(rd());

Food::Food(std::pair<int, int> a) : food(a) {}

pair<int,int> Food::get_food() const{
    return food;
}

pair<int,int> Food::generate_food(const Snake& snake, const Board& board){

    int width = board.get_width()-1; 
    int length = board.get_length()-1; 
    const vector<pair<int,int>>& corps = snake.get_snake();
     
    uniform_int_distribution<int> distX(0,width); 
    uniform_int_distribution<int> distY(0,length); 

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


pair<int,int> Food::new_food(const Snake& snake, const Board& board){
    food = generate_food(snake, board);
    return food;
}