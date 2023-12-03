#include "Apple.h"

using namespace std;

Apple::Apple(deque<Vector2> snake_body)
{
	Image img = LoadImage("images/apple.png");
	texture = LoadTextureFromImage(img);
	UnloadImage(img);
	pos = randPosNotOnSnake(snake_body);
}

Apple::~Apple()
{
	UnloadTexture(texture);
}



void Apple::draw()
{
	DrawRectangle((pos.x * cell_size) + cell_size / 2, (pos.y * cell_size) + cell_size / 2, 15, 20, red); // in case image didnot appear
	DrawTexture(texture, pos.x * cell_size, pos.y * cell_size, WHITE);
}

Vector2 Apple::randPos() {
	float x = GetRandomValue(0, no_cells - 1);
	float y = GetRandomValue(0, no_cells - 1);
	return Vector2{ x, y };
}

bool Apple::isElementOnSnake(Vector2 pos, deque<Vector2> snake_body) {
	for (unsigned int i = 0; i < snake_body.size(); i++)
	{
		if (Vector2Equals(snake_body[i], pos))
		{
			return true;
		}
	}
	return false;
}
#include <iostream>
Vector2 Apple::randPosNotOnSnake(deque<Vector2> snake_body)
{
	Vector2 pos = randPos();
	while (isElementOnSnake(pos, snake_body))
	{
		pos = randPos();
	}
	return pos;
}

