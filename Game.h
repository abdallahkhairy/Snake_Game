#pragma once
#include <raylib.h>
#include <deque>
#include "Snake.h"
#include "Apple.h"
#include <iostream>

class Game
{
public:
    const unsigned int no_cells = 30;
    Snake snake;
    Apple apple = Apple(snake.body);
    unsigned int score = 0;
    bool is_game_running = true;
    Sound eat_sound;
    Sound crash_sound;
    Sound passing_sound;

    Game();
    ~Game();


    void draw();
    void update();
    void isAppleEated();
    void isSnakePassedWindow();
    bool isSnakeHitItSelf(Vector2 pos, deque<Vector2> snake_body);
    void isSnakeHitItSlefOGameOver();
    void GameOver();


};

