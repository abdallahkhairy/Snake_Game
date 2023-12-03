#include "Snake.h"

Snake::Snake()
{
    Image img = LoadImage("images/apple.png");
    texture = LoadTextureFromImage(img);
    UnloadImage(img);
}

Snake::~Snake()
{
}

void Snake::draw() {
    for (unsigned int i = 0; i < body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle block;
        if (0 == i){
            DrawCircle((x * cell_size) + cell_size/2, (y * cell_size) + cell_size / 2, cell_size/2, snake_head_color);
        }
        else{
            block = Rectangle{ x * cell_size, y * cell_size, (float)cell_size, (float)cell_size };
            DrawRectangleRounded(block, 0.5, 15, snake_color);
        }
        
        
    }
}

void Snake::update() {
    body.push_front(Vector2Add(body[0], direction));
    if (add_block == true){
        add_block = false;
    }
    else{
        body.pop_back();
    }
}

void Snake::reset() {
    body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    direction = { 1, 0 };
}
