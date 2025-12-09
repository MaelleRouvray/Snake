#ifndef GAME_H
#define GAME_H


#include "snake.h"
#include "food.h"
#include "board.h"

#include <array>
#include <utility>
#include <iostream>
#include <random>
using namespace std;



pair<int, int> get_command(Snake snake);
bool collisions(Snake snake,Board board);
void run(Snake snake,Board board);


#endif