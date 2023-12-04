#include "Snake.h"

Snake::Snake()
{
    Image imguh = LoadImage("images/uhead.png");
    Image imgdh = LoadImage("images/dhead.png");
    Image imgrh = LoadImage("images/rhead.png");
    Image imglh = LoadImage("images/lhead.png");
    Image imgvbody = LoadImage("images/vbody.png");
    Image imghbody = LoadImage("images/hbody.png");
    Image imgtl = LoadImage("images/tl.png");
    Image imgtr = LoadImage("images/tr.png");
    Image imgtld = LoadImage("images/tld.png");
    Image imgtrd = LoadImage("images/trd.png");
    Image imgdt = LoadImage("images/dtail.png");
    Image imgut = LoadImage("images/utail.png");
    Image imgrt = LoadImage("images/rtail.png");
    Image imglt = LoadImage("images/ltail.png");

    texture[0] = LoadTextureFromImage(imguh);
    texture[1] = LoadTextureFromImage(imgdh);
    texture[2] = LoadTextureFromImage(imgrh);
    texture[3] = LoadTextureFromImage(imglh);
    texture[4] = LoadTextureFromImage(imgvbody);
    texture[5] = LoadTextureFromImage(imghbody);
    texture[6] = LoadTextureFromImage(imgtl);
    texture[7] = LoadTextureFromImage(imgtr);
    texture[8] = LoadTextureFromImage(imgtld);
    texture[9] = LoadTextureFromImage(imgtrd);
    texture[10] = LoadTextureFromImage(imgdt);
    texture[11] = LoadTextureFromImage(imgut);
    texture[12] = LoadTextureFromImage(imgrt);
    texture[13] = LoadTextureFromImage(imglt);
    UnloadImage(imguh);
    UnloadImage(imgdh);
    UnloadImage(imgrh);
    UnloadImage(imglh);
    UnloadImage(imgvbody);
    UnloadImage(imghbody);
    UnloadImage(imgtr);
    UnloadImage(imgtl);
    UnloadImage(imgtld);
    UnloadImage(imgtrd);
    UnloadImage(imgdt);
    UnloadImage(imgut);
    UnloadImage(imgrt);
    UnloadImage(imglt);
}

Snake::~Snake()
{
    for (char i = 0; i < 6; i++)
    {
        UnloadTexture(texture[i]);
    }
}
#include <iostream>
void Snake::draw() {
    for (unsigned int i = 0; i < body.size(); i++){
        float x = body[i].x;
        float y = body[i].y;
        Rectangle block;
        if (0 == i){
            DrawCircle((x * cell_size) + cell_size/2, (y * cell_size) + cell_size / 2, cell_size/4, snake_head_color);
            if ((body[1].x - body[0].x) == 0 && (body[1].y - body[0].y) == 1) { // moves up
                DrawTexture(texture[0], x * cell_size, y * cell_size, WHITE);
            }
            else if ((body[1].x - body[0].x) == 0 && (body[1].y - body[0].y) == -1) { // moves down
                DrawTexture(texture[1], x * cell_size, y * cell_size, WHITE);
            }
            else if ((body[1].x - body[0].x) == -1 && (body[1].y - body[0].y) == 0) { // moves right
                DrawTexture(texture[2], x * cell_size, y * cell_size, WHITE);
            }
            else if ((body[1].x - body[0].x) == 1 && (body[1].y - body[0].y) == 0) { // moves left
                DrawTexture(texture[3], x * cell_size, y * cell_size, WHITE);
            }
            else { /* Nothing */ }
        }
        else if(body.size()-1 == i){

            block = Rectangle{ (x * cell_size) + cell_size / 2, (y * cell_size) + cell_size / 2, (float)cell_size/2, (float)cell_size/2 };
            DrawRectangleRounded(block, 0.5, 15, snake_color);
            if ((body[body.size() - 2].x - body[body.size() - 1].x) == 0 && (body[body.size() - 2].y - body[body.size() - 1].y) == 1) { // moves down
                DrawTexture(texture[10], x * cell_size, y * cell_size, WHITE);
            }
            else if ((body[body.size() - 2].x - body[body.size() - 1].x) == 0 && (body[body.size() - 2].y - body[body.size() - 1].y) == -1) { // moves up
                DrawTexture(texture[11], x * cell_size, y * cell_size, WHITE);
            }
            else if ((body[body.size() - 2].x - body[body.size() - 1].x) == 1 && (body[body.size() - 2].y - body[body.size() - 1].y) == 0) { // moves right
                DrawTexture(texture[12], x * cell_size, y * cell_size, WHITE);
            }
            else if ((body[body.size() - 2].x - body[body.size() - 1].x) == -1 && (body[body.size() - 2].y - body[body.size() - 1].y) == 0) { // moves left
                DrawTexture(texture[13], x * cell_size, y * cell_size, WHITE);
            }
            else { /* Nothing */ }
        }
        else if (i+1 != body.size())  {
            int front_block_x_relation = body[i - 1].x - body[i].x;
            int front_block_y_relation = body[i - 1].y - body[i].y;
            int rear_block_x_relation = body[i + 1].x - body[i].x;
            int rear_block_y_relation = body[i + 1].y - body[i].y;

            block = Rectangle{ (x * cell_size) + cell_size / 2, (y * cell_size) + cell_size / 2, (float)cell_size/2, (float)cell_size/2 };
            DrawRectangleRounded(block, 0.5, 15, snake_color);

            if (rear_block_x_relation == front_block_x_relation) { // horizontal
                DrawTexture(texture[4], x * cell_size, y * cell_size, WHITE);
            }
            else if ((body[i+1].y - body[i].y) == (body[i-1].y - body[i].y) ) { // vertical
                DrawTexture(texture[5], x * cell_size, y * cell_size, WHITE);
            }
            else { 
                if(((rear_block_x_relation == -1) && (front_block_y_relation== -1)) || ((rear_block_y_relation == -1) && (front_block_x_relation == -1)) ){ // from down to left or from right to up
                    DrawTexture(texture[8], x * cell_size, y * cell_size, WHITE);
                }
                else if (((rear_block_x_relation == -1) && (front_block_y_relation == 1)) || ((rear_block_y_relation == 1) && (front_block_x_relation == -1))) { // from up to left or from right to down
                    DrawTexture(texture[6], x * cell_size, y * cell_size, WHITE);
                }
                else if (((rear_block_x_relation == 1) && (front_block_y_relation == -1)) || ((rear_block_y_relation == -1) && (front_block_x_relation == 1))) { // from down to right or from left to up
                    DrawTexture(texture[9], x * cell_size, y * cell_size, WHITE);
                }
                else if (((rear_block_x_relation == 1) && (front_block_y_relation == 1)) || ((rear_block_y_relation == 1) && (front_block_x_relation == 1))) { // from down to right or from left to up
                    DrawTexture(texture[7], x * cell_size, y * cell_size, WHITE);
                }
                else { /* Nothing*/ }
            }
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
    body = { Vector2{15,15}, Vector2{16, 15}, Vector2{17, 15} };
    direction = { 1, 0 };
}
