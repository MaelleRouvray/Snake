#include "../include/board.h"
#include "../include/snake.h"
#include "../include/food.h"

Board::Board(int a, int b) : length(a) , width(b) {}

int Board::get_length(){
    return length;
}

int Board::get_width(){
    return width;
}

void Board::show_board(){
    for (int i=0;i<width;i++){
        cout << " ___" ;
    };
    cout << endl ;
    for (int i=0 ; i<length ; i++){
        for (int j=0 ; j<width ; j++){
            cout << "|" ;
            cout << "___" ;
        }
        cout << "|" ;
        cout << endl;
    }
}

void Board::add_snake(Snake snake){

}
void Board::add_food(Food food, Snake snake){

}

