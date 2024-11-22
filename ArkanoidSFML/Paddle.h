#pragma once
#include "iostream"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Variables.h"

class Paddle
{
public:
	sf::RectangleShape paddle;
	float paddleWidth{ 100.f };
	float paddleHeight{ 30.f };
	float paddleSpeed{ 100.f };
	sf::Vector2f paddleVelocity;
	

	Paddle(sf::Vector2f pos, sf::Color col);
	float leftSide();
	float rightSide();
	float topSide();
	float bottomSide();
	void updatePaddle(float dt);
	void movePaddle();

	
};