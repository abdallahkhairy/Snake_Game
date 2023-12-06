#include <iostream>
#include <raylib.h>
#include "Game.hpp"



using namespace std;
// To close the console uncomment hash this line
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
// And go to project Properites >> Linker >> System - Change SubSystem to No Set

const unsigned int cell_size = 30;
const unsigned int no_cells = 30;
double last_time = 0;
bool move_flag = false;

bool eventTriggered(double interval);
Color bg_color = Color{ 87, 114, 69, 255 };
Color text_color = Color{ 0, 0, 0, 100 };

int main() {
    InitWindow(cell_size* no_cells, cell_size * no_cells, "Snake Game By Abdullah Khairy");
    SetTargetFPS(60);
    Game game;
    Image img = LoadImage("images/logo.png");
    SetWindowIcon(img);
    //Texture2D texture = LoadTextureFromImage(img);
    UnloadImage(img);
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(bg_color);

        if (eventTriggered(0.2)) {
            move_flag = true;
            game.update();
        }
        else { /* Nothing */ }
        
        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1 && move_flag){
            game.snake.direction = { 0, -1 };
            game.is_game_running = true;
            move_flag = false;
        }
        else if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1 && move_flag){
            game.snake.direction = { 0, 1 };
            game.is_game_running = true;
            move_flag = false;
        }
        else if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 && move_flag){
            game.snake.direction = { -1, 0 };
            game.is_game_running = true;
            move_flag = false;
        }
        else if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1 && move_flag){
            game.snake.direction = { 1, 0 };
            game.is_game_running = true;
            move_flag = false;
        }
        else if (IsKeyPressed(KEY_ENTER)) {
            game.is_game_running = true;

        }
        else { /* Nothing */ }

        game.draw();
        DrawText(TextFormat("Score : %u", game.score), 5,  10, 40, text_color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - last_time >= interval)
    {
        last_time = currentTime;
        return true;
    }
    return false;
}