#include "Game.h"
#include <iostream>

void Game::draw() {
    apple.draw();
    snake.draw();
    //std::cout << snake.body[0].x << "now snake" << snake.body[0].y << " ";
    //std::cout << apple.pos.x << " now apple" << apple.pos.y << " ";
}



Game::Game(){
     InitAudioDevice();
     eat_sound = LoadSound("audio/eats.mp3");
     crash_sound = LoadSound("audio/crash.mp3");
     passing_sound = LoadSound("audio/passing.mp3");

}

Game::~Game() {
    UnloadSound(eat_sound);
    UnloadSound(crash_sound);
    UnloadSound(passing_sound);

    CloseAudioDevice();
}

void Game::update() {
    if (is_game_running)
    {
        snake.update();
        isSnakeHitItSlefOGameOver();
        //std::cout << snake.body[0].x << " sanke head " << snake.body[0].y <<endl;
        isAppleEated();
        isSnakePassedWindow();
    }

}

void Game::isAppleEated(){
    if (Vector2Equals(snake.body[0], apple.pos))
    {
        apple.pos = apple.randPosNotOnSnake(snake.body);
        snake.add_block = true;
        score++;
        PlaySound(eat_sound);
    }
}

void Game::isSnakePassedWindow() {
    
    if (snake.body[0].x == no_cells) {
        snake.body[0].x = 0;
        PlaySound(passing_sound);
    }
    else if (snake.body[0].x == -1) {
        snake.body[0].x = no_cells;
        PlaySound(passing_sound);
    }
    else if (snake.body[0].y == no_cells) {
        snake.body[0].y = 0;
        std::cout << "down";
        PlaySound(passing_sound);
    }
    else if (snake.body[0].y == -1) {
        snake.body[0].y = no_cells;
        std::cout << "up";
        PlaySound(passing_sound);
    }
    else { /* Nothing */ }
}
bool Game::isSnakeHitItSelf(Vector2 pos, deque<Vector2> snake_body) {
    for (unsigned int i = 0; i < snake_body.size(); i++)
    {
        if (Vector2Equals(snake_body[i], pos))
        {
            return true;
        }
    }
    return false;
}

void Game::isSnakeHitItSlefOGameOver() {
    deque<Vector2> no_head_snake_body = snake.body;
    no_head_snake_body.pop_front();
    if (isSnakeHitItSelf(snake.body[0], no_head_snake_body))
    {
        PlaySound(crash_sound);
        GameOver();
    }
}
void Game::GameOver(){
    snake.reset();
    apple.pos = apple.randPosNotOnSnake(snake.body);
    is_game_running = false;
    score = 0;
   // PlaySound(wallSound);
}