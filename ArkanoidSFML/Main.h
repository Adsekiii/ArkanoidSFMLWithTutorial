#pragma once
#include "iostream"
#include <vector>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Variables.h"

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"

int main();

void collisionHandling(Paddle& paddle, Ball& ball);
void collisionHandling(Brick& brick, Ball& ball);



template<class T1, class T2> bool areIntersecting(T1& A, T2& B);