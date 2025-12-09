#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <random>
using namespace std;


void get_command(Snake snake);
bool collisions(Snake snake,Board board);
void run(Snake snake);


#endif