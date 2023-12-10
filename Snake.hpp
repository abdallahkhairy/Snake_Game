#pragma once
#include <raylib.h>
#include <raymath.h>
#include <deque>
#include "images_hex/imguh.hpp"
#include "images_hex/imgdh.hpp" 
#include "images_hex/imgrh.hpp" 
#include "images_hex/imglh.hpp" 
#include "images_hex/imgvbody.hpp"
#include "images_hex/imghbody.hpp"
#include "images_hex/imgtl.hpp"
#include "images_hex/imgtr.hpp"
#include "images_hex/imgtld.hpp"
#include "images_hex/imgtrd.hpp"
#include "images_hex/imgdt.hpp"
#include "images_hex/imgut.hpp"
#include "images_hex/imgrt.hpp"
#include "images_hex/imglt.hpp"
using namespace std; 
class Snake
{
public:
    const unsigned int cell_size = 30;
    const unsigned int no_cells = 30;
    Color snake_color = Color{ 161, 134, 89, 255 };
    Color snake_head_color = Color{ 73, 60, 51, 255};
    deque<Vector2> body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    Vector2 direction = { 1, 0 };
    //Texture2D texture;
    Texture2D texture[14];

    Snake();
    ~Snake();
    bool add_block = false;

    void draw();
    void update();


    void reset();
    
};

