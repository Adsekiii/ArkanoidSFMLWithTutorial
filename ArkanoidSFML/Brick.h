#pragma once
#include "iostream"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Variables.h"

class Brick
{
public:
	sf::RectangleShape brick;
	bool isDestroyed{ false };

	Brick(sf::Vector2f pos);
	float leftSide();
	float rightSide();
	float topSide();
	float bottomSide();
	void updateBrick(float dt);


};