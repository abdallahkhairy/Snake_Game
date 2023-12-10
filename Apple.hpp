#pragma once
#include <raylib.h>
#include <raymath.h>
#include <deque>
#include "images_hex/apple.hpp"

using namespace std;

class Apple
{
public:
	Vector2 pos;
	Texture2D texture;
	const unsigned int cell_size = 30;
	const unsigned int no_cells = 30;
	Color red = Color{ 255, 0, 0, 255 };

	Apple(deque<Vector2> snake_body);
	~Apple();
	void draw();
	Vector2 randPos();


	bool isElementOnSnake(Vector2 pos, deque<Vector2> snake_body);
	Vector2 randPosNotOnSnake(deque<Vector2> snake_body);

};