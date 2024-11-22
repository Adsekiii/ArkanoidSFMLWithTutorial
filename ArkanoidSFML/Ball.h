#pragma once
#include "iostream"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Paddle.h"
#include "Brick.h"

#include "Variables.h"

class Ball
{
public:
	sf::RectangleShape ball;
	float ballWidth{ 30.f };
	float ballHeight{ 30.f };
	float ballSpeed{ 100.f };
	sf::Vector2f velocity;
	const float ballVelocity{1};


	Ball(sf::Vector2f pos, sf::Color col);
	float leftSide();
	float rightSide();
	float topSide();
	float bottomSide();
	void updateBall(float dt);
	void moveBall();

};