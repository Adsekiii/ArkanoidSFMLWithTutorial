#include "Brick.h"

Brick::Brick(sf::Vector2f pos)
{
	this->brick.setSize({ brickWidth,brickHeight });
	this->brick.setOrigin({ this->brick.getPosition().x + brickWidth / 2,this->brick.getPosition().y + brickHeight / 2 });
	this->brick.setPosition(pos);
	this->brick.setFillColor(sf::Color::Green);

}
float Brick::leftSide()
{
	return this->brick.getPosition().x - brickWidth / 2;
}
float Brick::rightSide()
{
	return this->brick.getPosition().x + brickWidth / 2;
}
float Brick::topSide()
{
	return this->brick.getPosition().y - brickHeight / 2;
}
float Brick::bottomSide()
{
	return this->brick.getPosition().y + brickHeight / 2;
}
void Brick::updateBrick(float dt)
{

}